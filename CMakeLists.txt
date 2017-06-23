# Enforce a min version.
cmake_minimum_required(VERSION 3.7)

# This projects name.
project(colors)

# This project is testable.
enable_testing()

# We want modern C++.
set(CMAKE_CXX_STANDARD 14)

# Group all of the C++ files that we need.
file(GLOB colors_include_headers "${CMAKE_CURRENT_SOURCE_DIR}/include/colors/*.h")
file(GLOB colors_src_headers "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h")
file(GLOB colors_src_bodies "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# Create a library with all of our files.
add_library(colors_lib
    ${colors_include_headers}
    ${colors_src_headers}
    ${colors_src_bodies}
)

# The library headers are the public API.
target_include_directories(colors_lib PUBLIC "include")

# The library source is a private implemendation.
target_sources(colors_lib PRIVATE "src")

# Group all of the tests
file(GLOB test_files "${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp")

# Create a test for each file in the folder.
foreach(test_file ${test_files})

    # Get the files name without any path or extension.
    get_filename_component(test_file_name ${test_file} NAME_WE)

    # Make the tests name.
    set(test_name test_${test_file_name})

    # Create a executable for the test.
    add_executable(${test_name} ${test_file})

    # Link that test exe against our library.
    target_link_libraries(${test_name} colors_lib)

    # Add it to the test system
    add_test(${test_name} ${test_name})

endforeach(test_file)


