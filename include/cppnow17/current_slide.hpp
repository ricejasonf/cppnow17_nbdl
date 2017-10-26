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

  struct current_slide_tag { };

  struct current_slide_t
  {
    unsigned int value;
  };

  struct current_slide_c_tag { };

  template <unsigned int i>
  struct current_slide_c_t
  {
    using hana_tag = current_slide_c_tag;
    static constexpr current_slide_t value = {i};
  };

  template <unsigned int i>
  constexpr current_slide_c_t<i> current_slide_c{};

  // To be used as a key: nbdl::context keys are always Paths (ie Sequence of keys)
  constexpr auto current_slide = hana::tuple<current_slide_tag>{};

  namespace detail
  {
    template <typename>
    struct make_slide_variant;

    template <std::size_t ...i>
    struct make_slide_variant<std::index_sequence<i...>>
    {
      using type = nbdl::variant<hana::size_t<i>...>;
    };

    constexpr auto apply_slide_action(current_slide_t s, slide_action_prev_t)
    {
      if (s.value == 0)
      {
        return current_slide_t{0};
      }
      else
      {
        return current_slide_t{(s.value - 1) % slide_count};
      }
    }

    constexpr auto apply_slide_action(current_slide_t s, slide_action_next_t)
    {
      if (s.value == slide_count - 1)
      {
        return current_slide_t{slide_count - 1};
      }
      else
      {
        return current_slide_t{(s.value + 1) % slide_count};
      }
    }
  }

  /*
   * current_slide_store
   */
  struct current_slide_store
  {
    current_slide_t value;

    current_slide_store()
      : value(current_slide_t{0})
    { }
  };
}

namespace nbdl
{
  template<>
  struct get_impl<cppnow17::current_slide_store>
  {
    template <typename Store, typename Key>
    static auto apply(Store const& store, Key&&)
    {
      return store.value;
    }
  };

  template<>
  struct apply_foreign_message_impl<cppnow17::current_slide_store>
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
        auto old_value = store.value;
        message::get_payload(std::forward<Message>(m)).match([&](auto action)
        {
          if constexpr(hana::typeid_(action) != hana::type_c<nbdl::unresolved>)
          {
            auto new_value = cppnow17::detail::apply_slide_action(old_value, action);
            store.value = new_value;
            std::forward<Fn>(fn)(cppnow17::current_slide);
          }
        });
      }
    }
  };
}

namespace boost::hana
{
  // Comparable (don't do this)

  template <>
  struct equal_impl<cppnow17::current_slide_t, cppnow17::current_slide_t>
  {
    constexpr static auto apply(cppnow17::current_slide_t x, cppnow17::current_slide_t y)
    {
      return x.value = y.value;
    }
  };

  template <>
  struct equal_impl<cppnow17::current_slide_t, cppnow17::current_slide_c_tag>
  {
    template <unsigned int i>
    constexpr static auto apply(cppnow17::current_slide_t x
                              , cppnow17::current_slide_c_t<i> y)
    {
      return x.value == y.value.value;
    }
  };

  template <>
  struct equal_impl<cppnow17::current_slide_c_tag, cppnow17::current_slide_t>
  {
    template <unsigned int i>
    constexpr static auto apply(cppnow17::current_slide_c_t<i> x
                              , cppnow17::current_slide_t y)
    {
      return x.value.value == y.value;
    }
  };

  // Constant

  template <>
  struct value_impl<cppnow17::current_slide_c_tag>
  {
    template <typename T>
    static auto apply(T)
    {
      return T::value;
    }
  };
}

namespace nbdl
{
  NBDL_ENTITY(cppnow17::current_slide_t, value);
}

namespace cppnow17
{
  static_assert(boost::hana::equal(current_slide_t{42}, current_slide_c<42>));
  static_assert(boost::hana::equal(current_slide_c<42>, current_slide_t{42}));
}
#endif
