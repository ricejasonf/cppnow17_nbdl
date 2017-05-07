//
// Copyright Jason Rice 2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef CPPNOW17_MAKE_CONTEXT_DEF_HPP
#define CPPNOW17_MAKE_CONTEXT_DEF_HPP

#include <boost/hana.hpp>
#include <nbdl.hpp>

namespace cppnow17
{
  using namespace boost::hana::literals;
  template <typename ProducerTag, typename ConsumerTag>
  auto make_context_def(ProducerTag, ConsumerTag)
  {
    using namespace nbdl_def;
    return Context(
      Providers(
        Provider(
          Name("producer"_s)
        , Type(ProducerTag{})
#if 0
        , AccessPoint(
            Name("TODO"_s)
          , Entity<entity::root1>
          , PathKey<test_context::key<entity::root1>>
          )
#endif
        )
      )
    , Consumers(
        Consumer(
          Name("consumer"_s)
        , Type(ConsumerTag{})
        )
      )
    );
  };
}
#endif
