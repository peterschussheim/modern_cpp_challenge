cmake_minimum_required (VERSION 3.8)

project ("modern_cpp_challenge")
if (UNIX)
  message(status "** Setting GCC flags")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -fexceptions -g -Wall")
elseif(WIN32)
  message(status "** Setting MSVC flags")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc /std:c++latest")
  
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()
message(status "** CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")

set(LIBS_PATH "${CMAKE_SOURCE_DIR}/libs")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Scan subdirectories containing CMakeLists.txt files and store in variable
# SUBDIRLIST(SUBDIRS ${MY_CURRENT_DIR})
MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child} AND EXISTS ${curdir}/${child}/CMakeLists.txt)
      LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()

# add_subdirectory(libs/ZipLib)
# add_subdirectory(libs/PDF-Writer)
# add_subdirectory(libs/PngWriter)
# add_subdirectory(libs/cryptopp)
# add_subdirectory(libs/curl)
# add_subdirectory(libs/curlcpp)

include_directories(include)
add_subdirectory(src)

# SUBDIRLIST(SUBDIRS ${MY_CURRENT_DIR})