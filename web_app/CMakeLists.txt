add_executable(web_app main.cpp)

set(link_flags "--bind -s EXPORTED_FUNCTIONS=\"['_start']\" -s ASSERTIONS=1")
get_target_property(existing_link_flags web_app LINK_FLAGS)
if (existing_link_flags)
  set(link_flags "${existing_link_flags} ${link_flags})")
endif(existing_link_flags)
set_target_properties(web_app PROPERTIES LINK_FLAGS ${link_flags})

set(www_dir ${CMAKE_CURRENT_BINARY_DIR}/www)

add_custom_command(
  TARGET web_app POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/www ${www_dir}
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/web_app.js ${www_dir}/web_app.js
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/web_app.js.mem ${www_dir}/web_app.js.mem
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/www/index.js
)

add_custom_target(hot_dev
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/www/index.html ${www_dir}/index.html
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/www/origins.css ${www_dir}/origins.css
  COMMAND http-server
  DEPENDS web_app
  WORKING_DIRECTORY ${www_dir}
)
