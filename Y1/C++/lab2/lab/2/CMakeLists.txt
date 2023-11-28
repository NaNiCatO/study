cmake_minimum_required(VERSION 3.10)
project(example1)
add_executable(q2 2.3.cpp)
# set C++ standard
set_target_properties(
    q2
    PROPERTIES
CXX_STANDARD 17
CXX_STANDARD_REQUIRED YES
CXX_EXTENSIONS NO)
# add more warning to the compiler options
if (MSVC)
target_compile_options(q2 PRIVATE /Wall /WX)
else()
target_compile_options(q2 PRIVATE -Wall -Wextra)
endif()
set(TARGETS q2)
set_target_properties(
${TARGETS}
PROPERTIES
CXX_STANDARD 17
CXX_STANDARD_REQUIRED YES
CXX_EXTENSIONS NO)
foreach(T ${TARGETS})
if (MSVC)
target_compile_options(${T} PRIVATE /Wall /WX)
else()
target_compile_options(${T} PRIVATE -Wall -Wextra)
endif()
endforeach()