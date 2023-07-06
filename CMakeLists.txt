cmake_minimum_required(VERSION 3.14)
project(
  fdmss-linux
  VERSION 1.0
  LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_UNITY_BUILD ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
# )
# # For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt
#     ON
#     CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(googletest)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set(CMAKE_CXX_CLANG_TIDY "clang-tidy")
# set(CMAKE_CXX_CPPCHECK
#     cppcheck
#     --force
#     --enable=all
#     --suppress=missingIncludeSystem
#     --check-config
#     -UMPI
#     --std=c++17)

include_directories(${CMAKE_SOURCE_DIR}/include)

# macro(add_libs)
#   foreach(lib ${ARGN})
#     list(APPEND libs ${lib})
#   endforeach()
#   set(libs
#       ${libs}
#       PARENT_SCOPE)
# endmacro()

add_subdirectory(src)
# add_subdirectory(examples)
# add_subdirectory(tests)

# find_package(Doxygen)

# if(DOXYGEN_FOUND)
#     #SET INPUT AND OUTPUT FILES
#     set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
#     set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.out)
    
#     # request to configure the file
#     configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
#     message("-- Doxygen build started including directory")
    
#     add_custom_target( docs ALL
#         COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
#         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#         COMMENT "-- Generating API documentation with Doxygen"
#         VERBATIM )
# else (DOXYGEN_FOUND)
#     message("-- Doxygen need to be installed to generate the doxygen documentation")
# endif (DOXYGEN_FOUND)
