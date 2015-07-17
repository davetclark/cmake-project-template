/**
 * Original Author: David Clark
 * This is free and unencumbered software released into the public domain
 */
 
#include "config.hpp"
#include "app/app.hpp"

#include <glog/logging.h>

int main(int argc, char* argv[]) {
    google::InitGoogleLogging(argv[0]);
    google::InstallFailureSignalHandler();

    LOG(INFO) << "Welcome to " << CONFIG_APP_NAME << " Version " << CONFIG_VERSION_STRING;

    LOG(INFO) << helloWorld();
    return 0;
}
