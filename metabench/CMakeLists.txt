#cmake_minimum_required(VERSION 3.5)
#
#add_definitions(-std=c++1z)
#add_definitions(-DBOOST_HANA_CONFIG_ENABLE_STRING_UDL)
#add_definitions(-ftemplate-backtrace-limit=0)
#add_definitions(-Wall)
#add_definitions(-Wextra)

# metabench.cmake is added in Dockerfile
include("/opt/metabench.cmake")

add_subdirectory(static_polymorphism)
add_subdirectory(chaining)
