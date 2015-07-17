#
# Original Author: David Clark
# This is free and unencumbered software released into the public domain
#

cmake_minimum_required(VERSION 2.8.9)

set(PROJECT_NAME "TemplateProjectDeps")
project(${PROJECT_NAME})

include("ExternalProject")
externalproject_add(glog
    GIT_REPOSITORY https://github.com/google/glog
    GIT_TAG v0.3.4
    CONFIGURE_COMMAND ./configure --prefix=${CMAKE_INSTALL_PREFIX}
    BUILD_COMMAND make
    BUILD_IN_SOURCE 1
    INSTALL_COMMAND make install
)
add_dependencies(glog ${PROJECT_NAME})

externalproject_add(gmock
    SVN_REPOSITORY http://googlemock.googlecode.com/svn/tags/release-1.7.0
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}
    INSTALL_COMMAND ""
)
add_dependencies(gmock ${PROJECT_NAME})

# Need to manually install gmock/gtest, it doesn't include install steps
set(GMOCK_SOURCE_DIR ${CMAKE_CURRENT_BINARY_DIR}/gmock-prefix/src/gmock)
set(GMOCK_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/gmock-prefix/src/gmock-build)
install(FILES ${GMOCK_BINARY_DIR}/libgmock.a
              ${GMOCK_BINARY_DIR}/libgmock_main.a
              ${GMOCK_BINARY_DIR}/gtest/libgtest.a
              ${GMOCK_BINARY_DIR}/gtest/libgtest_main.a
        DESTINATION lib)
install(DIRECTORY ${GMOCK_SOURCE_DIR}/include/gmock ${GMOCK_SOURCE_DIR}/gtest/include/gtest
        DESTINATION include)
