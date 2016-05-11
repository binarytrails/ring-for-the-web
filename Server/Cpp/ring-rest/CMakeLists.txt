cmake_minimum_required (VERSION 2.8.8)
project (ring-rest)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.8)
        message(FATAL_ERROR "GCC version >=4.8 required.")
    endif()
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 3.3)
        message(FATAL_ERROR "Clang version >=3.3 required.")
    endif()
else()
    message(WARNING "Your compiler (${CMAKE_CXX_COMPILER_ID}) has not been tested on this project. Only Clang and GCC has been tested. Please report any problems at the project page on GitHub.")
endif()

find_package(Boost 1.60 REQUIRED COMPONENTS system program_options)

include_directories(.)
include_directories(SYSTEM ${Boost_INCLUDE_DIR})

set(CMAKE_BUILD_TYPE Debug)
add_executable(ring-rest main.cpp)

target_link_libraries(ring-rest ${Boost_LIBRARIES})
target_link_libraries(ring-rest ${CMAKE_THREAD_LIBS_INIT})

enable_testing()
