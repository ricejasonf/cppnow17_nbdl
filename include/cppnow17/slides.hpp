//
// Copyright Jason Rice 2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef CPPNOW17_SLIDES_HPP
#define CPPNOW17_SLIDES_HPP

#include <boost/hana.hpp>
#include <cppnow17/slide_spec.hpp>
#include <mpdef/list.hpp>

namespace cppnow17
{
  constexpr auto make_slides()
  {
    namespace hana = boost::hana;
    using namespace boost::hana::literals;
    using namespace cppnow17::slide_spec;

    return mpdef::make_list(
      title()
     ,bulleted(
        header("Overview"_s)
      , bullets(
          "What is Nbdl?"_s
        , "Concepts"_s
        , "Abstraction"_s
        , "Empty Interface"_s
        , "Store"_s
        , "Promises"_s
        , "Deployment"_s
        )
      )
    , syntax(
        header("First Slide"_s)
      , name("test.cpp"_s)
      )
    , syntax(
        header("Second Slide"_s)
      , name("test.cpp"_s)
      )
    , syntax(
        header("Third Slide"_s)
      , name("test.cpp"_s)
      )
    );
  }

  constexpr auto slides = make_slides();
}

#endif
