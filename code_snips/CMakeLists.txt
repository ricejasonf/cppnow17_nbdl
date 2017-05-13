set(code_snips_dir ${CMAKE_BINARY_DIR}/code_snips)
set(code_snips_npm ${CMAKE_BINARY_DIR}/code_snips/src)

add_custom_command(
  OUTPUT ${code_snips_npm}/index.js
  DEPENDS
  ${CMAKE_SOURCE_DIR}/code_snips/src/index.js
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/code_snips ${code_snips_dir}
)

add_custom_command(
  OUTPUT ${code_snips_npm}/node_modules
  COMMAND npm install --silent
  WORKING_DIRECTORY ${code_snips_npm}
  COMMENT "Resolve npm deps for code_snips"
  DEPENDS
  ${code_snips_npm}/index.js
)

add_custom_command(
  OUTPUT generated_include/generated/code_syntax.hpp
  COMMAND node index.js
  DEPENDS
  ${code_snips_npm}/index.js
  ${code_snips_npm}/node_modules
  WORKING_DIRECTORY "./src"
)

add_custom_target(code_snips
  DEPENDS generated_include/generated/code_syntax.hpp
)
