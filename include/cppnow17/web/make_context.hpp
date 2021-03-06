//
// Copyright Jason Rice 2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef CPPNOW17_WEB_MAKE_CONTEXT_HPP
#define CPPNOW17_WEB_MAKE_CONTEXT_HPP

#include <cppnow17/make_context_def.hpp>
#include <cppnow17/slides.hpp>
#include <cppnow17/web/render_slide.hpp>
#include <cppnow17/web/key_control.hpp>

#include <boost/hana.hpp>
#include <nbdl.hpp>
#include <nbdl/ui_spec.hpp>
#include <nbdl/webui/html.hpp>
#include <nbdl/webui/renderer.hpp>

namespace cppnow17::web
{
  namespace hana = boost::hana;
  using namespace boost::hana::literals;

  struct context { };
  auto make_spec()
  {
    using namespace nbdl::ui_spec;
    using namespace nbdl::webui::html;

    //return div(text_node("Hello world"_s));
    constexpr auto range = hana::make_range(hana::size_c<0>, hana::length(slides));
    return hana::unpack(range, [](auto ...i)
    { 
      return div(
        attr_class("app-container"_s)
      , div(
          attr_class("slides"_s)
        , render_slide(i, hana::at(slides, i))...
        )
      , div(
          attr_class("counter"_s)
        , text_node(get(current_slide, "value"_s))
        , text_node("/"_s)
        , text_node(hana::length(slides) - hana::size_c<1>)
        )
      , div (
          attr_class("conference-name"_s)
        , text_node("C++Now 2017"_s)
        )
      , div (
          attr_class("copyright"_s)
        , text_node("Jason Rice 2017"_s)
        )
      );
    });
  }
  constexpr auto my_html_renderer = nbdl::webui::renderer<decltype(make_spec())>{};

  auto make_context_def()
  {
    using namespace nbdl_def;

    return cppnow17::make_context_def(
      nbdl::echo_producer{}
    , my_html_renderer
    , Context(
        Name("key_control"_s)
      , Type(key_control{})
      )
    );
  };
  
  template<typename ConsumerArg>
  auto make_context(ConsumerArg&& c)
  {
    return nbdl::make_unique_context<context>(
      hana::type_c<void>
    , std::forward<ConsumerArg>(c)
    , hana::type_c<void>
    );
  }
}

namespace nbdl
{
  template <>
  struct make_def_impl<cppnow17::web::context>
  {
    static constexpr auto apply()
      -> decltype(cppnow17::web::make_context_def())
    { return {}; }
  };
}
#endif
