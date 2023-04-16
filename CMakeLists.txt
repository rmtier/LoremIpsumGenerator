# CMakeList.txt : CMake project for LoremIpsum++, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("LoremIpsumGenerator")

add_library(${PROJECT_NAME} INTERFACE)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET LoremIpsumGenerator PROPERTY CXX_STANDARD 20)
endif()

# Testing project
find_package(Catch2 REQUIRED)
add_executable(LoremIpsumGeneratorTest "test/LoremIpsumGeneratorTest.cpp")
target_link_libraries(LoremIpsumGeneratorTest PRIVATE Catch2::Catch2WithMain)
include_directories(LoremIpsumGeneratorTest PRIVATE include)

include(CTest)
include(Catch)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET LoremIpsumGeneratorTest PROPERTY CXX_STANDARD 20)
endif()

catch_discover_tests(LoremIpsumGeneratorTest)

enable_testing()
