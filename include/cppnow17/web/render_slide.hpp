//
// Copyright Jason Rice 2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef CPPNOW17_WEB_RENDER_SLIDE_HPP
#define CPPNOW17_WEB_RENDER_SLIDE_HPP

#include <boost/hana.hpp>
#include <cppnow17/code_syntax.hpp>
#include <cppnow17/slide_spec.hpp>
#include <nbdl/webui/html.hpp>

namespace cppnow17::web
{
      
  auto syntax_slide = [](auto header, auto syntax)
  {
    using namespace boost::hana::literals;
    using namespace nbdl::webui::html;

    return div(attr_class("slide current"_s), div(
      attr_class("slide-syntax"_s),
      div(
        attr_class("header"_s),
        text_node(header)
      ),
      div(
        attr_class("syntax-container"_s),
        pre(
          attr_class("syntax"_s),
          unsafe_set_inner_html(code_syntax(syntax))
        )
      ),
      div()
    ));
  };

  struct render_slide_fn
  {
    template <typename Spec>
    constexpr auto operator()(Spec) const
    {
      namespace tag = slide_spec::tag;
      constexpr Spec spec{};
      constexpr auto key = hana::first(spec);
      constexpr auto props = hana::second(spec);
      
      if constexpr(key == tag::syntax)
      {
        return decltype(syntax_slide(props[tag::header], props[tag::name])){};
      }
      else
      {
        static_assert(
          key == hana::type_c<void>
        , "cppnow17::web::render_slide must receive a valid slide_spec::tag."
        );
      }
    }
  };

  constexpr render_slide_fn render_slide{};
}

#endif
