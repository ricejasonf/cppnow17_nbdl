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
#include <cppnow17/diagram.hpp>
#include <cppnow17/slide_spec.hpp>
#include <nbdl/webui/html.hpp>

namespace cppnow17::web
{
  namespace hana = boost::hana;
      
  namespace view
  {
    using namespace boost::hana::literals;
    using namespace nbdl::webui::html;
    using namespace nbdl::ui_spec;

    auto slide_container = [](auto index, auto child)
    {
      constexpr std::size_t i = hana::value(index);

      return div(
        attr_class(concat(
          "slide "_s
        , match(get(current_slide)
          , when<hana::size_t<i>>("current"_s)
          , when<hana::size_t<i + 1>>("prev"_s)
          , when<hana::size_t<i - 1>>("next"_s)
          , when<>(""_s)
          )
        ))
      , child
      );
    };

    auto title = [](auto header, auto description) {
      return div(
        attr_class("title-slide"_s)
      , div(
          attr_class("header"_s)
        , text_node(header)
        )
      , div(
          attr_class("description"_s)
        , text_node(description)
        )
      );
    };

    auto syntax_slide = [](auto header, auto syntax)
    {
      return div(
        attr_class("slide-syntax"_s)
      , div(
          attr_class("header"_s)
        , text_node(header)
        )
      , div(
          attr_class("syntax-container"_s)
        , pre(
            attr_class("syntax"_s)
          , unsafe_set_inner_html(code_syntax(syntax))
          )
        )
      );
    };

    auto bulleted_slide = [](auto header, auto ...bullets)
    {
      return div(
        attr_class("slide-bulleted"_s)
      , div(
          attr_class("header"_s)
        , text_node(header)
        )
      , ul(li(text_node(bullets))...)
      );
    };

    auto overview_diagram = div(
      attr_class("slide-overview-diagram"_s)
    , unsafe_set_inner_html(cppnow17::overview_diagram)
    );
  }

  struct render_slide_fn
  {
    template <typename Index, typename Spec>
    constexpr auto operator()(Index index, Spec) const
    {
      namespace tag = slide_spec::tag;
      constexpr Spec spec{};
      constexpr auto key = hana::first(spec);
      constexpr auto props = hana::second(spec);
      
      if constexpr(key == tag::syntax)
      {
        return decltype(view::slide_container(
          index
        , view::syntax_slide(props[tag::header], props[tag::name])
        )){};
      }
      else if constexpr(key == tag::bulleted)
      {
        return decltype(view::slide_container(
          index
        , hana::unpack(
            props[tag::bullets]
          , hana::partial(view::bulleted_slide, props[tag::header])
          )
        )){};
      }
      else if constexpr(key == tag::title)
      {
        return decltype(view::slide_container(
          index
        , view::title(props[tag::header], props[tag::description])
        )){};
      }
      else if constexpr(key == tag::overview_diagram)
      {
        return decltype(view::slide_container(
          index 
        , view::overview_diagram
        )){};
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
