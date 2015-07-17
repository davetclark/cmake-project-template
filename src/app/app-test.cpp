/**
 * Original Author: David Clark
 * This is free and unencumbered software released into the public domain
 */
 
#include "app.hpp"

#include "gtest/gtest.h"

TEST(AppTestCase, AppTest) {
    // This will fail. Note that the expected is the first argument, actual is second
    EXPECT_EQ("Hello", helloWorld());
}
