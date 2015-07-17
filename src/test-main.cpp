/**
 * Original Author: David Clark
 * This is free and unencumbered software released into the public domain
 */

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <glog/logging.h>

int main(int argc, char* argv[]) {
    ::testing::InitGoogleMock(&argc, argv);

    google::InitGoogleLogging(argv[0]);
    google::InstallFailureSignalHandler();

    return RUN_ALL_TESTS();
}
