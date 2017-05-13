//
// Copyright Jason Rice 2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef CPPNOW17_WEB_KEY_CONTROL_HPP
#define CPPNOW17_WEB_KEY_CONTROL_HPP

#include <cppnow17/make_context_def.hpp>

#include <boost/hana.hpp>
#include <emscripten.h>
#include <emscripten/html5.h>
#include <nbdl.hpp>

namespace cppnow17::web
{
  namespace hana = boost::hana;
  using namespace boost::hana::literals;

  struct key_control { };

  template <typename ContextHandle>
  struct key_control_impl
  {
    using hana_tag = key_control;

    ContextHandle ctx;

    static EM_BOOL keyup_callback(int /* event_type */
                                , EmscriptenKeyboardEvent const* event_info
                                , void* self
                                 )
    {
      reinterpret_cast<key_control_impl*>(self)->handle_event(event_info);
      return EM_TRUE;
    }

    void register_callback()
    {
      emscripten_set_keyup_callback(0 , this , EM_FALSE , &key_control_impl::keyup_callback);
    }

    void unregister_callback()
    {
      emscripten_set_keyup_callback(0 , this, EM_FALSE , 0);
    }

    key_control_impl(ContextHandle c)
      : ctx(std::move(c))
    {
      register_callback();
    }

    key_control_impl(key_control_impl const& other)
      : ctx(other.ctx)
    {
      other.unregister_callback();
      register_callback();
    }

    key_control_impl(key_control_impl&& other)
      : ctx(std::move(other).ctx)
    {
      other.unregister_callback();
      register_callback();
    }

    // Can not unregister in destructor because unregister effects all handlers :/

    void handle_event(EmscriptenKeyboardEvent const* e)
    {
      switch (e->keyCode)
      {
        case 37:
          left_arrow();
          break;
        case 39:
          right_arrow();
          break;
      }
    }

    void left_arrow()
    {
      EM_ASM("console.log('left_arrow')");
      constexpr auto key = hana::transform(slide_action, hana::typeid_);

      ctx.push(
        ctx
        .message_api()
        .make_upstream_create_message(key, slide_action_prev)
      );
    }

    void right_arrow()
    {
      EM_ASM("console.log('right_arrow')");
      constexpr auto key = hana::transform(slide_action, hana::typeid_);

      ctx.push(
        ctx
        .message_api()
        .make_upstream_create_message(key, slide_action_next)
      );
    }
  };

}

namespace nbdl
{
  template <>
  struct make_state_consumer_impl<cppnow17::web::key_control>
  {
    template <typename ContextHandle>
    static auto apply(ContextHandle&& ctx)
    {
      return cppnow17::web::key_control_impl<ContextHandle>(std::forward<ContextHandle>(ctx));
    }
  };

  template <>
  struct notify_state_change_impl<cppnow17::web::key_control>
  {
    template <typename Consumer, typename Path>
    static auto apply(Consumer const& c, Path const& path)
    {
      if constexpr(decltype(hana::typeid_(path) == hana::typeid_(cppnow17::current_slide)){})
      {
        nbdl::match(c.ctx, cppnow17::current_slide, [](auto value)
        {
          if constexpr(hana::typeid_(value) == hana::type_c<nbdl::unresolved>)
          {
            EM_ASM("console.log('current_slide: nbdl::unresolved');");
          }
          else
          {
            EM_ASM_("console.log('current_slide: hana::size_c<' + $0 + '>');", hana::value(value));
          }
        });
      }
    }
  };
}
#endif
