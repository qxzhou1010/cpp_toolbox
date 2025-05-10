cmake_minimum_required(VERSION 3.5)

# Set the project name
project(cpptoolbox)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# 生成 json 文件，用于 clangd 建立 index
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add an executable
add_library(cpptoolbox STATIC)
# 指定 target 中的 .cc 文件
target_sources(cpptoolbox PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src/main.cc)

set(BUILD_TEST ON)
if(BUILD_TEST)
  message(STATUS "Compiling the unit tests")

  # add test
  find_package(GTest 1 CONFIG REQUIRED)

  add_executable(alltest "")

  add_subdirectory(tests)

  target_link_libraries(alltest PRIVATE GTest::gtest)

endif()
