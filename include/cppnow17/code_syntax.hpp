//
// Copyright Jason Rice 2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef CPPNOW17_CODE_SYNTAX_HPP
#define CPPNOW17_CODE_SYNTAX_HPP

#include <boost/hana/core/to.hpp>

namespace cppnow17
{
  namespace hana = boost::hana;

  struct code_syntax_tag { };

  namespace generated
  {
    template <typename>
    struct code_syntax;

    #include <generated/code_syntax.hpp>
  }

  auto code_syntax = [](auto name)
  {
    return generated::code_syntax<decltype(name)>{};
  };
}

namespace boost::hana
{
  template <typename Name>
  struct to_impl<char const*, cppnow17::generated::code_syntax<Name>>
  {
    template <typename CodeSyntax>
    static constexpr char const* apply(CodeSyntax)
    {
      return CodeSyntax::value;
    }
  };
}
#endif
