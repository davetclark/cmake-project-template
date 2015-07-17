# cmake Project Template for C++ Projects
Creates a nice base to work from. Includes gmock/gtest, glog.

Only tested on Linux. Should be easily ported to all platforms.

## Build dependencies
```
cd deps
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=../stage ..
make install

# Have cmake re-check for dependencies now that they've been built
cmake ..
```
That will put the prebuilt dependencies into deps/stage

## How to configure CMake for Debug, with ninja
```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug -GNinja ..
```

## How to configure for Debug, with Makefiles
```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
```

## How to configure for Release with ninja
```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release -GNinja ..
```

## Building
```
# Build Everything:
ninja

# Build only project
ninja <ProjectName>

# Build only tests
ninja unit

# If you built with makefiles, replace "ninja" with "make"
```

## Running
```
# Run with log going only to file in tmp/
./<ProjectName>

# Run with logging to console as well
GLOG_logtostderr=1 ./<ProjectName>

# Run unit tests with log going only to file in tmp/
./unit

# Run unit tests with logging to console as well
GLOG_logtostderr=1 ./unit

# Run certain unit test cases or tests:
./unit --gtest_filter=AppTestCase.*
./unit --gtest_filter=AppTestCase.AppTest
./unit --gtest_filter=App*
```

## Logging
Uses Google Logging Library (glog)
https://google-glog.googlecode.com/svn/trunk/doc/glog.html

## Testing/Mocking
Uses Google Mocks and Google Test (gmock/gtest)
https://code.google.com/p/googlemock/wiki/ForDummies
https://code.google.com/p/googletest/wiki/V1_7_Primer

By default, this logs to
```"/tmp/<program name>.<hostname>.<user name>.log.<severity level>.<date>.<time>.<pid>"```

To get console output, run like this: GLOG_logtostderr=1 ./myProgram
