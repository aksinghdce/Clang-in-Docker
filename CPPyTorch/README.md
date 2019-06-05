# Install C++ library for PyTorch

[Installation guide](https://pytorch.org/cppdocs/installing.html)

Followed the instructions. I had to take a diversion to install CMake in Dockerfile.
Following is the result

```
root@52ed1d7781f3:/CPPyTorch/example-app# ls
CMakeLists.txt  example-app.cpp
root@52ed1d7781f3:/CPPyTorch/example-app# mkdir build
root@52ed1d7781f3:/CPPyTorch/example-app# cd build/
root@52ed1d7781f3:/CPPyTorch/example-app/build# cmake -DCMAKE_PREFIX_PATH=/CPPyTorch/libtorch/
CMake Warning:
  No source or binary directory provided.  Both will be assumed to be the
  same as the current working directory, but note that this warning will
  become a fatal error in future CMake releases.


CMake Error: The source directory "/CPPyTorch/example-app/build" does not appear to contain CMakeLists.txt.
Specify --help for usage, or press the help button on the CMake GUI.
root@52ed1d7781f3:/CPPyTorch/example-app/build# cmake -DCMAKE_PREFIX_PATH=/CPPyTorch/libtorch/ ..
-- The C compiler identification is GNU 7.4.0
-- The CXX compiler identification is GNU 7.4.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Looking for pthread.h
-- Looking for pthread.h - found
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Failed
-- Looking for pthread_create in pthreads
-- Looking for pthread_create in pthreads - not found
-- Looking for pthread_create in pthread
-- Looking for pthread_create in pthread - found
-- Found Threads: TRUE
-- Found torch: /CPPyTorch/libtorch/lib/libtorch.so
-- Configuring done
-- Generating done
-- Build files have been written to: /CPPyTorch/example-app/build
root@52ed1d7781f3:/CPPyTorch/example-app/build# make
Scanning dependencies of target example-app
[ 50%] Building CXX object CMakeFiles/example-app.dir/example-app.cpp.o
[100%] Linking CXX executable example-app
[100%] Built target example-app
root@52ed1d7781f3:/CPPyTorch/example-app/build# ls
CMakeCache.txt  CMakeFiles  Makefile  cmake_install.cmake  example-app
root@52ed1d7781f3:/CPPyTorch/example-app/build# ./example-app
 0.1522  0.4003  0.0999
 0.9898  0.0532  0.1502
[ Variable[CPUFloatType]{2,3} ]


```
