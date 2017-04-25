set(code_snips_npm ${CMAKE_BINARY_DIR}/code_snips_npm)

add_custom_command(
  OUTOUT ${code_snips_npm}/index.js
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/code_snips/src ${code_snips_npm}
)

add_custom_command(
  OUTPUT ${code_snips_npm}
  COMMAND npm install --silent
  WORKING_DIRECTORY ${code_snips_npm}
  COMMENT "Resolve npm deps for code_snips"
)

add_custom_target(code_snips
  DEPENDS
  ${code_snips_npm}/index.js
  ${code_snips_npm}/node_modules
)
