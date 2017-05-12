//
// Copyright Jason Rice 2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef CPPNOW17_CURRENT_SLIDE_HPP
#define CPPNOW17_CURRENT_SLIDE_HPP

#include <cppnow17/slide_action.hpp>
#include <cppnow17/slides.hpp>

#include <boost/hana.hpp>
#include <boost/hana/ext/std/integer_sequence.hpp>
#include <nbdl.hpp>
#include <utility>

namespace cppnow17
{
  namespace hana = boost::hana;

  constexpr std::size_t slide_count = hana::value(hana::length(slides));

  namespace detail
  {
    template <typename>
    struct make_slide_variant;

    template <std::size_t ...i>
    struct make_slide_variant<std::index_sequence<i...>>
    {
      using type = nbdl::variant<hana::size_t<i>...>;
    };

    template <std::size_t i>
    constexpr auto apply_slide_action(hana::size_t<i>, slide_action_prev_t)
    {
      if constexpr(i == 0)
      {
        return hana::size_c<0>;
      }
      else
      {
        return hana::size_c<(i - 1) % slide_count>;
      }
    }

    template <std::size_t i>
    constexpr auto apply_slide_action(hana::size_t<i>, slide_action_next_t)
    {
      if constexpr(i == slide_count - 1)
      {
        return hana::size_c<slide_count - 1>;
      }
      else
      {
        return hana::size_c<(i + 1) % slide_count>;
      }
    }

    template <typename Action>
    constexpr auto apply_slide_action(nbdl::unresolved, Action)
    {
      return hana::size_c<0>;
    }
  }

  struct current_slide_tag { };
  using current_slide_t = typename detail::make_slide_variant<
    std::make_index_sequence<slide_count>
  >::type;

  // To be used as a key: nbdl::context keys are always Paths (ie Sequence of keys)
  constexpr auto current_slide = hana::tuple<current_slide_tag>{};

  /*
   * current_slide_store
   */
  struct current_slide_store
  {
    current_slide_t value;

    current_slide_store()
      : value()
      //: value(hana::size_c<0>)
    { }
  };
}

namespace nbdl
{
  template<>
  struct match_impl<cppnow17::current_slide_store>
  {
    template <typename Store, typename Key, typename Fn>
    static auto apply(Store&& store, Key&&, Fn&& fn)
    {
      std::forward<Store>(store).value.match(
        std::forward<Fn>(fn)
      );
    }
  };

  template<>
  struct apply_foreign_action_impl<cppnow17::current_slide_store>
  {
    template <typename Store, typename Message, typename Fn>
    static void apply(Store& store, Message&& m, Fn&& fn)
    {
      if constexpr(
           message::is_downstream<Message>
        && message::is_create<Message>
        && decltype(message::get_path_type(m)){} == hana::typeid_(cppnow17::slide_action)
      )
      {
        store.value.match([&](auto old_value)
        {
          message::get_payload(std::forward<Message>(m)).match([&](auto action)
          {
            if constexpr(hana::typeid_(action) != hana::type_c<nbdl::unresolved>)
            {
              auto new_value = cppnow17::detail::apply_slide_action(old_value, action);
              store.value = new_value;
              std::forward<Fn>(fn)(cppnow17::current_slide);
            }
          });
        });
      }
    }
  };
}
#endif
