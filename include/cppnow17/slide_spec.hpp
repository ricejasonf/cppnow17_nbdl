//
// Copyright Jason Rice 2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef CPPNOW17_SLIDE_SPEC_HPP
#define CPPNOW17_SLIDE_SPEC_HPP

#include <mpdef/MPDEF_DIRECTIVE.hpp>

namespace cppnow17::slide_spec
{
  MPDEF_DIRECTIVE(bulleted);
  MPDEF_DIRECTIVE(overview_diagram);
  MPDEF_DIRECTIVE(syntax);
  MPDEF_DIRECTIVE(title);

  MPDEF_DIRECTIVE_LEAF(description);
  MPDEF_DIRECTIVE_LEAF(header);
  MPDEF_DIRECTIVE_LEAF(name);
  MPDEF_DIRECTIVE_LIST(bullets);
}

#endif
