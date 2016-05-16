cmake_minimum_required (VERSION 2.8.8)
project (ring-rest C CXX)

# Set the project's version
set (ring-rest_VERSION_MAJOR 1)
set (ring-rest_VERSION_MINOR 0)

# Flags for debug and release
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread -Wall -Wextra -Wfatal-errors -pedantic -DBOOST_LOG_DYN_LINK")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -ggdb -DDEBUG ")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DNDEBUG -O3")

# Check if any compiler is available
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

include_directories(AFTER include)

# Fetch the files
file(GLOB_RECURSE SOURCES_EXE src/*.cpp)
file(GLOB_RECURSE HEADERS include/*.hpp)
set(SOURCES_LIB ${SOURCES_EXE})

# Remove the main.cpp for the library targets
list(REMOVE_ITEM SOURCES_LIB ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

# Find the needed packages
find_package(Boost 1.60 REQUIRED COMPONENTS system program_options log)
find_package(OpenSSL)

if(NOT Boost_FOUND)
	message(FATAL_ERROR "Boost not found, please go to http://www.boost.org to install the latest version of Boost")
elseif(NOT OPENSSL_FOUND)
	message(FATAL_ERROR "OpenSSL not found, please go to https://www.openssl.org to install the latest version of OpenSSL")
endif()

include_directories(.)
include_directories( ${Boost_INCLUDE_DIR} )
include_directories(SYSTEM ${OPENSSL_INCLUDE_DIR})

# This is temporary
set(CMAKE_BUILD_TYPE Debug)

# The executable for test
set(EXE ${SOURCES_EXE} ${HEADERS})
add_executable(ring-rest ${EXE})

# Link the librairies to the executable
target_link_libraries(ring-rest ${Boost_LIBRARIES})
target_link_libraries(ring-rest ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(ring-rest ${OPENSSL_LIBRARIES})

# The libraries
set(LIB ${SOURCES_LIB} ${HEADERS})

add_library(ring-rest-static EXCLUDE_FROM_ALL STATIC ${LIB})
set_target_properties(ring-rest-static PROPERTIES OUTPUT_NAME ring-rest CLEAN_DIRECT_OUTPUT 1)

add_library(ring-rest-shared EXCLUDE_FROM_ALL SHARED ${LIB})
set_target_properties(ring-rest-shared PROPERTIES OUTPUT_NAME ring-rest CLEAN_DIRECT_OUTPUT 1)

enable_testing()
