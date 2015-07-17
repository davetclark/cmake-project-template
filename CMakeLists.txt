#
# Original Author: David Clark
# This is free and unencumbered software released into the public domain
#

cmake_minimum_required(VERSION 2.8.9)

set(PROJECT_NAME TemplateProject)
set(PROJECT_BIN ${PROJECT_NAME})
set(PROJECT_LIB "${PROJECT_NAME}Lib")
set(UNIT_BIN unit)

set(CONFIG_VERSION_MAJOR 0)
set(CONFIG_VERSION_MINOR 1)
set(CONFIG_VERSION_PATCH 0)
set(CONFIG_APP_NAME \"${PROJECT_NAME}\")

project(${PROJECT_NAME})

set(PREBUILT_DEPENDENCIES "${CMAKE_CURRENT_SOURCE_DIR}/deps/stage" CACHE STRING "Dependency Directory")

# Set up paths
set(Project_SOURCEDIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Compiler flags
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -std=gnu++11 -Wall -O2")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -std=gnu++11 -Wall -O0 -g")

# Create config header file
configure_file("${Project_SOURCEDIR}/config.hpp.in"
               "${Project_SOURCEDIR}/config.hpp")

# Where to look for cmake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Find required system packages
find_package(Threads REQUIRED)
set(GMOCK_ROOT ${PREBUILT_DEPENDENCIES})
find_package(GMock)
set(GLOG_ROOT ${PREBUILT_DEPENDENCIES})
find_package(GLog)

# Source files
list(APPEND Project_SOURCES ${Project_SOURCEDIR}/app/app.cpp)
list(APPEND Project_HEADERS ${Project_SOURCEDIR}/app/app.hpp)

# Test source files
list(APPEND TemplateProjectUnit_SOURCES ${Project_SOURCEDIR}/app/app-test.cpp)

# Include 3rd party dependencies
include_directories(${GLOG_INCLUDE_DIRS})
include_directories(${GMOCK_INCLUDE_DIRS})


# Create static lib from sources
# Add headers to this line just so that IDEs like QtCreator pick them up
add_library(${PROJECT_LIB} STATIC ${Project_SOURCES} ${Project_HEADERS})
target_link_libraries(${PROJECT_LIB} ${GLOG_LIBRARIES})

# Create Project binary
add_executable(${PROJECT_BIN} ${Project_SOURCEDIR}/main.cpp)
target_link_libraries(${PROJECT_BIN} ${PROJECT_LIB} ${CMAKE_THREAD_LIBS_INIT})

# Create project test binary
add_executable(${UNIT_BIN} ${Project_SOURCEDIR}/test-main.cpp ${TemplateProjectUnit_SOURCES})
target_link_libraries(${UNIT_BIN} ${PROJECT_LIB} ${GLOG_LIBRARIES} ${GMOCK_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

#################### INSTALL #####################
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_BIN}
        DESTINATION BIN)


install(FILES ${GMOCK_BINARY_DIR}/libgmock.a
              ${GMOCK_BINARY_DIR}/libgmock_main.a
              ${GMOCK_BINARY_DIR}/gtest/libgtest.a
              ${GMOCK_BINARY_DIR}/gtest/libgtest_main.a
        DESTINATION ${DEP_INSTALL_PREFIX}/lib)
install(DIRECTORY ${GMOCK_SOURCE_DIR}/include/gmock ${GMOCK_SOURCE_DIR}/gtest/include/gtest
        DESTINATION ${DEP_INSTALL_PREFIX}/include)
