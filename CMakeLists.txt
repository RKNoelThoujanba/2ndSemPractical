cmake_minimum_required(VERSION 3.30)

project(2ndSemPractical)

add_executable(del CSrc/del.c)

add_executable(eval CSrc/eval.c)

add_executable(evenodd CSrc/evenodd.c)

add_executable(fib CSrc/fib.c)

add_executable(insert CSrc/insert.c)

add_executable(linear CSrc/linear.c)

add_executable(stringrev CSrc/stringrev.c)

add_executable(triangle CSrc/triangle.c)

add_executable(mat CSrc/mat.c)

add_executable(call CSrc/call.c)

add_executable(fact CSrc/factorial.c)

add_executable(factDigitCount CSrc/factDigitCount.c)

add_executable(factTrailingZeroCount CSrc/factTrailingZeroCount.c)

if(MSVC)
  # Force to always compile with W4
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Wall /WX /std:c++17")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /Wall /std:c17 /D_CRT_SECURE_NO_WARNINGS")

else()
  # Update if necessary
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-long-long -pedantic -Werror -std=c++17")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wno-long-long -pedantic -Werror -std=c17")
endif()


message(STATUS "C Flags: ${CMAKE_C_FLAGS}")
message(STATUS "CXX Flags: ${CMAKE_CXX_FLAGS}")