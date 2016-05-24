cmake_minimum_required (VERSION 3.0.0)
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

# Local cmake for ring
set(LOCAL_CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${LOCAL_CMAKE_MODULE_PATH})

# Find the needed packages
find_package(Boost 1.60 REQUIRED COMPONENTS system program_options log)
find_package(OpenSSL)
find_package(Ring REQUIRED)

if(NOT Boost_FOUND)
	message(FATAL_ERROR "Boost not found, please go to http://www.boost.org to install the latest version of Boost")
elseif(NOT OPENSSL_FOUND)
	message(FATAL_ERROR "OpenSSL not found, please go to https://www.openssl.org to install the latest version of OpenSSL")
elseif(NOT RING_FOUND)
	message(FATAL_ERROR "Ring package not found")
endif()

include_directories(.)
include_directories( ${Boost_INCLUDE_DIR} )
include_directories(SYSTEM ${OPENSSL_INCLUDE_DIR})

# This is temporary
set(CMAKE_BUILD_TYPE Debug)

# HTTP test executable
set(EXE ${SOURCES_EXE} ${HEADERS})
add_executable(ring-http ${EXE})

# Link the librairies to the executable
target_link_libraries(ring-http ${Boost_LIBRARIES})
target_link_libraries(ring-http ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(ring-http ${OPENSSL_LIBRARIES})

# HTTPS test executable
#add_executable(ring-https ${EXE})

# Link the librairies to the executable
#target_link_libraries(ring-https ${Boost_LIBRARIES})
#target_link_libraries(ring-https ${CMAKE_THREAD_LIBS_INIT})
#target_link_libraries(ring-https ${OPENSSL_LIBRARIES})

# Add the -DHTTPS define to the target
#set_target_properties(ring-https PROPERTIES COMPILE_FLAGS "-DHTTPS ${CMAKE_CXX_FLAGS}")

# The libraries
set(LIB ${SOURCES_LIB} ${HEADERS})

add_library(ring-rest-static EXCLUDE_FROM_ALL STATIC ${LIB})
set_target_properties(ring-rest-static PROPERTIES OUTPUT_NAME ring-rest CLEAN_DIRECT_OUTPUT 1)

add_library(ring-rest-shared EXCLUDE_FROM_ALL SHARED ${LIB})
set_target_properties(ring-rest-shared PROPERTIES OUTPUT_NAME ring-rest CLEAN_DIRECT_OUTPUT 1)

enable_testing()
