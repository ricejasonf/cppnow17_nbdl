//
// Copyright Jason Rice 2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef CPPNOW17_SLIDE_ACTION_HPP
#define CPPNOW17_SLIDE_ACTION_HPP

#include <boost/hana.hpp>
#include <nbdl.hpp>

namespace cppnow17
{
  namespace hana = boost::hana;

  struct slide_action_prev_t { };
  struct slide_action_next_t { };

  struct slide_action_tag { };
  using slide_action_t = typename nbdl::variant<slide_action_next_t, slide_action_prev_t>;

  constexpr auto slide_action_prev = slide_action_prev_t{};
  constexpr auto slide_action_next = slide_action_next_t{};

  // To be used as a key: nbdl::context keys are always Paths (ie Sequence of keys)
  constexpr auto slide_action  = hana::tuple<slide_action_tag>{};
}
#endif
