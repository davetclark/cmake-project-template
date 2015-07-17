#include "app.hpp"

#include <glog/logging.h>

#include <string>

std::string helloWorld() {
    DLOG(INFO) << "Entered helloWorld function, Debug Build";
    return "Hello World";
}
