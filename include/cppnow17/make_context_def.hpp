//
// Copyright Jason Rice 2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef CPPNOW17_MAKE_CONTEXT_DEF_HPP
#define CPPNOW17_MAKE_CONTEXT_DEF_HPP

#include <cppnow17/slides.hpp>
#include <cppnow17/current_slide.hpp>
#include <cppnow17/slide_action.hpp>

#include <boost/hana.hpp>
#include <boost/hana/ext/std/integer_sequence.hpp>
#include <nbdl.hpp>
#include <utility>

namespace cppnow17
{
  namespace hana = boost::hana;
  using namespace hana::literals;

  template <typename ProducerTag, typename ConsumerTag, typename ...MoreConsumerDefs>
  auto make_context_def(ProducerTag, ConsumerTag, MoreConsumerDefs...)
  {
    using namespace nbdl_def;

    return Context(
      Producers(
        Producer(
          Name("producer"_s)
        , Type(ProducerTag{})
        , AccessPoints(
            AccessPoint(
              Name("current_slide"_s)
            , Store<cppnow17::current_slide_store>
            , Entity<current_slide_t>
            , PathKey<current_slide_tag>
            , ListenPaths(Path<slide_action_tag>)
            )
          , AccessPoint(
              Name("slide_action"_s)
            , Actions(Create())
            , Entity<slide_action_t>
            , PathKey<slide_action_tag>
            )
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
