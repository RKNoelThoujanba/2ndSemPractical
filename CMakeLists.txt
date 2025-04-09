cmake_minimum_required(VERSION 3.30)

set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

if(MSVC)
  # Force to always compile with W4
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  # Update if necessary
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
endif()

project(del)
add_executable(del del.c)


project(eval)
add_executable(eval eval.c)

project(evenodd)
add_executable(evenodd evenodd.c)

project(fib)
add_executable(fib fib.c)

project(insert)
add_executable(insert insert.c)

project(linear)
add_executable(linear linear.c)

project(stringrev)
add_executable(stringrev stringrev.c)

project(triangle)
add_executable(triangle triangle.c)