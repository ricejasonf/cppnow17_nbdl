//
// Copyright Jason Rice 2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef CPPNOW17_DIAGRAM_HPP
#define CPPNOW17_DIAGRAM_HPP

#include <boost/hana/core/to.hpp>

namespace cppnow17
{
  namespace hana = boost::hana;

  struct diagram_tag { };

  struct overview_diagram_t
  {
    using hana_tag = diagram_tag;
    static constexpr char const* value =
"<svg width=\"1200\" height=\"900\">"
"  <defs>"
"       <marker id=\"arrow\" markerWidth=\"10\" markerHeight=\"10\" refX=\"0\" refY=\"2\" orient=\"auto\" markerUnits=\"strokeWidth\">"
"      <path d=\"M0,0 L0,4 L4,2 z\" fill=\"#cccccc\" /> "
"    </marker>"
"  </defs>"
"  <rect width=\"1200\" height=\"900\" style=\"fill:000000;\" />"
"  <g transform=\"translate(300, 0)\">"
"    <rect width=\"600\" height=\"200\" style=\"fill:#0a0a0a;stroke-width:5;stroke:#cccccc\" />"
"    <text font-size=\"75\""
"    text-anchor=\"middle\""
"    dominant-baseline=\"middle\""
"    x=\"300\""
"    y=\"100\""
"    fill=\"#cccccc\""
"    >"
"    Producer"
"    </text>"
"  </g>"
"  <g transform=\"translate(300, 350)\">"
"    <rect width=\"600\" height=\"200\" style=\"fill:#0a0a0a;stroke-width:5;stroke:#cccccc\" />"
"    <text font-size=\"75\""
"    text-anchor=\"middle\""
"    dominant-baseline=\"middle\""
"    x=\"300\""
"    y=\"100\""
"    fill=\"#cccccc\""
"    >"
"    Store"
"    </text>"
"  </g>"
"  <g transform=\"translate(300, 700)\">"
"    <rect width=\"600\" height=\"200\" style=\"fill:#0a0a0a;stroke-width:5;stroke:#cccccc\" />"
"    <text font-size=\"75\""
"    text-anchor=\"middle\""
"    dominant-baseline=\"middle\""
"    x=\"300\""
"    y=\"100\""
"    fill=\"#cccccc\""
"    >"
"    Consumer"
"    </text>"
"  </g>"
"  <g transform=\"translate(500, 250)\">"
"    <g transform=\"\">"
"      <path d=\"M 0,0 v 25\""
"        style=\"stroke:#cccccc; stroke-width: 7; fill: none;"
"         marker-end: url(#arrow);\""
"        /> "
"      <path d=\"M 0,0 m 0, 25 v -25\""
"        style=\"stroke:#cccccc; stroke-width: 14; fill: none;\""
"        /> "
"    </g>"
"    <g transform=\"translate(200, 30)\">"
"      <path d=\"M 0,25 v -25\""
"        style=\"stroke:#cccccc; stroke-width: 7; fill: none;"
"         marker-end: url(#arrow);\""
"        /> "
"      <path d=\"M 0,25 m 0, -25 v 25\""
"        style=\"stroke:#cccccc; stroke-width: 14; fill: none;\""
"        /> "
"    </g>"
"  </g>"
"  <g transform=\"translate(500, 600)\">"
"    <g transform=\"\">"
"      <path d=\"M 0,0 v 25\""
"        style=\"stroke:#cccccc; stroke-width: 7; fill: none;"
"         marker-end: url(#arrow);\""
"        /> "
"      <path d=\"M 0,0 m 0, 25 v -25\""
"        style=\"stroke:#cccccc; stroke-width: 14; fill: none;\""
"        /> "
"    </g>"
"    <g transform=\"translate(200, 30)\">"
"      <path d=\"M 0,25 v -25\""
"        style=\"stroke:#cccccc; stroke-width: 7; fill: none;"
"         marker-end: url(#arrow);\""
"        /> "
"      <path d=\"M 0,25 m 0, -25 v 25\""
"        style=\"stroke:#cccccc; stroke-width: 14; fill: none;\""
"        /> "
"    </g>"
"  </g>"
"</svg>";
  };

  constexpr overview_diagram_t overview_diagram{};
}

namespace boost::hana
{
  template <>
  struct to_impl<char const*, cppnow17::diagram_tag>
  {
    template <typename Diagram>
    static constexpr char const* apply(Diagram)
    {
      return Diagram::value;
    }
  };
}
#endif
