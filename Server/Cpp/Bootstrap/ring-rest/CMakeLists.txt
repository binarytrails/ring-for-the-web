CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

IF(POLICY CMP0022)
   CMAKE_POLICY(SET CMP0022 NEW)
ENDIF(POLICY CMP0022)

IF(POLICY CMP0043)
   CMAKE_POLICY(SET CMP0043 NEW)
ENDIF(POLICY CMP0043)

IF(POLICY CMP0020)
   CMAKE_POLICY(SET CMP0020 NEW)
ENDIF(POLICY CMP0020)

IF(POLICY CMP0063)
   CMAKE_POLICY(SET CMP0063 NEW)
ENDIF(POLICY CMP0063)

INCLUDE(GNUInstallDirs)
INCLUDE(CMakePackageConfigHelpers)
INCLUDE(GenerateExportHeader)

# Project name and version
PROJECT(ring-rest)
SET(ring-rest_VERSION_MAJOR 1)
SET(ring-rest_VERSION_MINOR 0)

# First, check is the compiler is new enough, most version of Clang are fine
# until problems arise, checking for GCC is enough
IF (CMAKE_COMPILER_IS_GNUCC)
   EXECUTE_PROCESS(COMMAND ${CMAKE_C_COMPILER} -dumpversion OUTPUT_VARIABLE GCC_VERSION)
   IF (GCC_VERSION VERSION_GREATER 4.8 OR GCC_VERSION VERSION_EQUAL 4.8)
      MESSAGE(STATUS "Found GCC version >= 4.8: " ${GCC_VERSION})
   ELSE()
      MESSAGE(FATAL_ERROR "Your version of GCC is too old, please install GCC 4.8 or later")
   ENDIF()
ENDIF()

SET(LOCAL_CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/")
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${LOCAL_CMAKE_MODULE_PATH})

FIND_PACKAGE(Ring REQUIRED)

# Enable some useful warnings
ADD_DEFINITIONS(
	-std=c++11
	-Wall
	-Wextra
	#-Wmissing-declarations
	#-Wmissing-noreturn
	#-Wpointer-arith
	#-Wcast-align
	#-Wwrite-strings
	#-Wformat-nonliteral
	#-Wformat-security
	#-Wswitch-enum
	#-Winit-self
	#-Wmissing-include-dirs
	#-Wundef
	#-Wmissing-format-attribute
	-Wno-reorder
	-Wunused
	-Wuninitialized
	#-Woverloaded-virtual
	#-Wunused-value
	#-pedantic
	#-Wnonnull
	#-Wsequence-point
	##-Wsystem-headers
	#-Wsizeof-pointer-memaccess
	##-Wuseless-cast
	#-Wvarargs

	##See https://gcc.gnu.org/bugzilla/show_bug.cgi?id=55578
	#-Wno-unused-function
	#-Wno-attributes
)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DBOOST_LOG_DYN_LINK")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -ggdb -DDEBUG ")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DNDEBUG -O3")

#Add more warnings for compilers that support it. I used this command:
#curl https://gcc.gnu.org/onlinedocs/gcc-4.9.2/gcc/Warning-Options.html | \
#grep -E "^[\t ]+<br><dt><code>-W[a-zA-Z=-]*" -o | grep -E "\-W[a-zA-Z=-]*" -o >
#cat /tmp/48 /tmp/49 | sort | uniq -u
# IF (CMAKE_COMPILER_IS_GNUCC)

IF (CMAKE_COMPILER_IS_GNUCC)
   IF (GCC_VERSION VERSION_GREATER 4.9 OR GCC_VERSION VERSION_EQUAL 4.9)
      ADD_DEFINITIONS(
         -Wunused-but-set-parameter
         -Wconditionally-supported
         #-Wsuggest-attribute=const
         -Wno-cpp
         #-Wdouble-promotion
         -Wdate-time
         -Wdelete-incomplete
         -Wfloat-conversion
      )
   ENDIF()

   if (GCC_VERSION VERSION_GREATER 5.1 OR GCC_VERSION VERSION_EQUAL 5.1)
      ADD_DEFINITIONS(
         #-Wsuggest-override
         #-Wsuggest-final-types
         #-Wsuggest-final-methods
         -Wbool-compare
         -Wformat-signedness
         -Wlogical-not-parentheses
         -Wnormalized
         -Wshift-count-negative
         -Wshift-count-overflow
         -Wsized-deallocation
         -Wsizeof-array-argument
      )
   ENDIF()

   IF (GCC_VERSION VERSION_GREATER 6.0 OR GCC_VERSION VERSION_EQUAL 6.0)
      ADD_DEFINITIONS(
         -Wnull-dereference
         -Wshift-negative-value
         -Wshift-overflow
         -Wduplicated-cond
         -Wmisleading-indentation
      )
   ENDIF()
ENDIF()

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	ADD_DEFINITIONS(
		#-Wno-c++98-compat
		#-Wno-c++98-compat-pedantic
		-Wno-unknown-pragmas
		-Wno-documentation-unknown-command
		-Wno-padded
		-Wno-old-style-cast
		-Wno-sign-conversion
		-Wno-exit-time-destructors
		-Wno-global-constructors
		-Wno-shorten-64-to-32
		#-Weverything
	)
endif()

IF(NOT (${ENABLE_VIDEO} MATCHES false))
	MESSAGE("VIDEO enabled")
	SET(ENABLE_VIDEO 1 CACHE BOOLEAN "Enable video")
	ADD_DEFINITIONS(-DENABLE_VIDEO=true)
ENDIF(NOT (${ENABLE_VIDEO} MATCHES false))

# Find the needed packages
FIND_PACKAGE(Boost 1.60 REQUIRED COMPONENTS system program_options log)

SET(GENERIC_LIB_VERSION "1.0.0")

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${RING_INCLUDE_DIRS})

INCLUDE_DIRECTORIES(AFTER include)

# File to compile
FILE(GLOB_RECURSE SOURCES src/*.cpp)
FILE(GLOB_RECURSE HEADERS include/*.hpp)
SET(FILES ${SOURCES} ${HEADERS})

# HTTP test executabe
ADD_EXECUTABLE(ring-http ${FILES})

TARGET_LINK_LIBRARIES(ring-http
	${Boost_LIBRARIES}
	${CMAKE_THREAD_LIBS_INIT}
	${OPENSSL_LIBRARIES}
	${RING_LIBRAIRIES} 
)

SET_TARGET_PROPERTIES(ring-http
  PROPERTIES VERSION ${GENERIC_LIB_VERSION} SOVERSION ${GENERIC_LIB_VERSION}
)

## ===============================================

#cmake_minimum_required (VERSION 3.0.0)
#project (ring-rest C CXX)
#
## Set the project's version
#set (ring-rest_VERSION_MAJOR 1)
#set (ring-rest_VERSION_MINOR 0)
#
## Flags for debug and release
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread -Wall -Wreorder -Wextra -Wfatal-errors -pedantic -DBOOST_LOG_DYN_LINK")
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -ggdb -DDEBUG ")
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DNDEBUG -O3")
#
## Check if any compiler is available
#if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
#    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.8)
#        message(FATAL_ERROR "GCC version >=4.8 required.")
#    endif()
#elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
#    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 3.3)
#        message(FATAL_ERROR "Clang version >=3.3 required.")
#    endif()
#else()
#    message(WARNING "Your compiler (${CMAKE_CXX_COMPILER_ID}) has not been tested on this project. Only Clang and GCC has been tested. Please report any problems at the project page on GitHub.")
#endif()
#
#include_directories(AFTER include)
#
## Fetch the files
#file(GLOB_RECURSE SOURCES src/*.cpp)
#file(GLOB_RECURSE HEADERS include/*.hpp)
#
## Find the needed packages
#find_package(Boost 1.60 REQUIRED COMPONENTS system program_options log)
#find_package(OpenSSL)
#
## Find all the RING related stuff
#set(RING_FOUND true)
#
## Display Ring folders
#
#find_path(RING_INCLUDE_DIRS NAMES dring/)
#find_library(RING_LIBRAIRIES NAMES libring.a )
#
#message("RING_INCLUDE_DIRS is " ${RING_INCLUDE_DIRS})
#message("RING_LIBRAIRIES is " ${RING_LIBRAIRIES})
#
#if(${RING_INCLUDE_DIRS})
#	set(RING_FOUND false)
#elseif(${RING_LIBRAIRIES})
#	set(RING_FOUND false)
#endif()
#
#if(NOT Boost_FOUND)
#	message(FATAL_ERROR "Boost not found, please go to http://www.boost.org to install the latest version of Boost")
#elseif(NOT OPENSSL_FOUND)
#	message(FATAL_ERROR "OpenSSL not found, please go to https://www.openssl.org to install the latest version of OpenSSL")
#elseif(NOT RING_FOUND)
#	message(FATAL_ERROR "Ring package not found")
#endif()
#
#
#include_directories(.)
#
## This is temporary
#set(CMAKE_BUILD_TYPE Debug)
#
## HTTP test executable
#set(FILES ${SOURCES} ${HEADERS})
#add_executable(ring-http ${FILES})
#set_target_properties(ring-http PROPERTIES LINKER_LANGUAGE CXX)
#
## Link the librairies to the executable
#target_link_libraries(ring-http 
#	${Boost_LIBRARIES}
#	${CMAKE_THREAD_LIBS_INIT}
#	${OPENSSL_LIBRARIES}
#	${RING_LIBRAIRIES} 
#)
#
## HTTPS test executable
##add_executable(ring-https ${EXE})
#
## Link the librairies to the executable
##target_link_libraries(ring-https ${Boost_LIBRARIES})
##target_link_libraries(ring-https ${CMAKE_THREAD_LIBS_INIT})
##target_link_libraries(ring-https ${OPENSSL_LIBRARIES})
#
## Add the -DHTTPS define to the target
##set_target_properties(ring-https PROPERTIES COMPILE_FLAGS "-DHTTPS ${CMAKE_CXX_FLAGS}")
#
## The libraries
##set(LIB ${SOURCES_LIB} ${HEADERS})
#
##add_library(ring-rest-static EXCLUDE_FROM_ALL STATIC ${LIB})
##set_target_properties(ring-rest-static PROPERTIES OUTPUT_NAME ring-rest CLEAN_DIRECT_OUTPUT 1)
#
##add_library(ring-rest-shared EXCLUDE_FROM_ALL SHARED ${LIB})
##set_target_properties(ring-rest-shared PROPERTIES OUTPUT_NAME ring-rest CLEAN_DIRECT_OUTPUT 1)
