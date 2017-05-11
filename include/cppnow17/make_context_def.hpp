//
// Copyright Jason Rice 2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef CPPNOW17_MAKE_CONTEXT_DEF_HPP
#define CPPNOW17_MAKE_CONTEXT_DEF_HPP

#include <cppnow17/slides.hpp>

#include <boost/hana.hpp>
#include <boost/hana/ext/std/integer_sequence.hpp>
#include <nbdl.hpp>
#include <utility>

namespace cppnow17
{
  namespace hana = boost::hana;
  using namespace hana::literals;

  namespace detail
  {
    template <typename>
    struct make_slide_variant;

    template <std::size_t ...i>
    struct make_slide_variant<std::index_sequence<i...>>
    {
      using type = nbdl::variant<hana::size_t<i>...>;
    };
  }

  struct current_slide_tag { };
  using current_slide_t = typename detail::make_slide_variant<
    std::make_index_sequence<decltype(hana::length(slides))::value>
  >::type;

  struct slide_action_prev_t { };
  struct slide_action_next_t { };

  struct slide_action_tag { };
  using slide_action_t = typename nbdl::variant<slide_action_next_t, slide_action_prev_t>;

  constexpr auto slide_action_prev = slide_action_prev_t{};
  constexpr auto slide_action_next = slide_action_next_t{};

  // To be used as a keys: nbdl::context keys are always Paths (ie Sequence of keys)
  constexpr auto current_slide = hana::tuple<current_slide_tag>{};
  constexpr auto slide_action  = hana::tuple<current_slide_tag>{};

  template <typename ProducerTag, typename ConsumerTag, typename ...MoreConsumerDefs>
  auto make_context_def(ProducerTag, ConsumerTag, MoreConsumerDefs...)
  {
    using namespace nbdl_def;
    return Context(
      Providers(
        Provider(
          Name("producer"_s)
        , Type(ProducerTag{})
        , AccessPoint(
            Name("current_slide"_s)
          , Actions(UpdateRaw())
          , Store<nbdl::context_store<current_slide_t>>
          , Entity<current_slide_t>
          , PathKey<current_slide_tag>
          )
        , AccessPoint(
            Name("slide_action"_s)
          , Actions(Create())
          , Entity<slide_action_t>
          , PathKey<slide_action_tag>
          )
        )
      )
    , Consumers(
        Consumer(
          Name("consumer"_s)
        , Type(ConsumerTag{})
        )
      , MoreConsumerDefs{}...
      )
    );
  };
}
#endif
