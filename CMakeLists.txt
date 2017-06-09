cmake_minimum_required(VERSION 3.7)

#set(cmake_c_compiler "clang-4.0")
#set(cmake_cxx_compiler "clang++-4.0")

project(colors)

enable_testing()

add_library(colors_lib
	"include/colors/black.h"
	"include/colors/white.h"
	"include/colors/ginger.h"
	"src/black.cpp"
	"src/white.cpp"
	"src/ginger.cpp"
	)

target_include_directories(colors_lib PUBLIC "include")
target_sources(colors_lib PRIVATE "src")

add_executable(colors_test "test/main.cpp")
target_link_libraries(colors_test colors_lib)
add_test(colors_test colors_test)

