# Once done this will define
#  ring_INCLUDE_DIRS - include directories
#  ring_BIN - Path to Ring binary

SET(RING_FOUND true)

IF(EXISTS ${RING_BUILD_DIR}/dring/dring.h)
   SET(RING_INCLUDE_DIRS ${RING_BUILD_DIR}/dring)
ELSEIF(EXISTS ${CMAKE_INSTALL_PREFIX}/include/dring/dring.h)
   SET(RING_INCLUDE_DIRS ${CMAKE_INSTALL_PREFIX}/include/dring)
ELSE()
   MESSAGE("Daemon header not found!
   Add -DRING_BUILD_DIR or -DCMAKE_INSTALL_PREFIX")
   SET(RING_FOUND false)
ENDIF()

SET(CMAKE_FIND_LIBRARY_SUFFIXES ".dylib;.so;.dll")

FIND_LIBRARY(RING_LIBRAIRIES NAMES ring
   PATHS ${RING_BUILD_DIR}/.libs
   #PATHS ${CMAKE_INSTALL_PREFIX}/lib
   #PATHS ${CMAKE_INSTALL_PREFIX}/libexec
   #PATHS ${CMAKE_INSTALL_PREFIX}/bin
)

# Try a static version too
IF(${RING_LIBRAIRIES} MATCHES "")
   SET(CMAKE_FIND_LIBRARY_SUFFIXES ".a;.lib")

   FIND_LIBRARY(RING_LIBRAIRIES NAMES ring
      PATHS ${RING_BUILD_DIR}/.libs
      #PATHS ${CMAKE_INSTALL_PREFIX}/lib
      #PATHS ${CMAKE_INSTALL_PREFIX}/libexec
   )

IF(NOT ${CMAKE_SYSTEM_NAME} MATCHES "Windows")
   ADD_DEFINITIONS(-fPIC)
ENDIF()

ENDIF()

MESSAGE("Ring daemon header is in " ${RING_INCLUDE_DIRS})
MESSAGE("Ring library path is " ${RING_LIBRAIRIES})
