cmake_minimum_required(VERSION 2.8)

project(cppnow17_nbdl_project)

add_definitions(-std=c++1z)
add_definitions(-DBOOST_HANA_CONFIG_ENABLE_STRING_UDL)
add_definitions(-ftemplate-backtrace-limit=0)
add_definitions(-Wall)
add_definitions(-Wextra)

if (${EMSCRIPTEN})
	add_definitions(--bind)
else (${EMSCRIPTEN})
  find_package(Threads)
  find_library(JsonCpp jsoncpp)
endif (${EMSCRIPTEN})

include_directories(${cppnow17_nbdl_project_SOURCE_DIR}/include)
include_directories(${CMAKE_BINARY_DIR}/code_snips/generated_include)

add_subdirectory(code_snips)
add_subdirectory(metabench)
