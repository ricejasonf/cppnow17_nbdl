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
#include <nbdl.hpp>

namespace cppnow17::web
{
  namespace hana = boost::hana;
  using namespace boost::hana::literals;

  struct key_control { }

  template <typename ContextHandle>
  struct key_control_impl
  {
    ContextHandler ctx;

    static EM_BOOL keyup_callback(int /* event_type */
                                , EmscriptenKeyboardEvent const* event_info
                                , void* self
                                 )
    {
      reinterpret_cast<key_control_impl*>(self)->handle_event(event_info);
    }

    key_control_impl(ContextHandle c)
      : ctx(std::move(c))
    {
      // register call back
      emscripten_set_keyup_callback(
        0
      , this
      , EM_FALSE
      , &key_control_impl::keyup_callback
      );
    }

    // TODO implement destructor to release handler??

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
      ctx.push(
        ctx
        .message_api()
        .make_upstream_create_message(slide_action, slide_action_prev)
      );
    }

    void right_arrow()
    {
      ctx.push(
        ctx
        .message_api()
        .make_upstream_create_message(slide_action, slide_action_next)
      );
    }
  };

}

namespace nbdl
{
  template <>
  struct make_consumer_impl<cppnow17::web::key_control>
  {
    template <typename ContextHandle>
    static auto apply(ContextHandle&& ctx)
    {
      return key_control_impl<ContextHandle>(std::forward<ContextHandle>(ctx));
    }
  };

  template <>
  struct send_downstream_message_impl<cppnow17::web::key_control>
  {
    template <typename Consumer, typename Message>
    static auto apply(Consumer&& c, Message&& m)
    {
      // do nothing
    }
  };
}
#endif
