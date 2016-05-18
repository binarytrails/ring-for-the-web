#Cpp

## Introduction

This is a C++ HTTP server, maybe it will support HTTPS in the futur.
Also it is named Muffin.

## Dependancies

[Boost 1.60](http://www.boost.org)
[OpenSSL](https://www.openssl.org) to use the HTTPS socket

## Build

There is 3 different build possible : the executable, the shared library and the static library
You can use ```-DCMAKE_BUILD_TYPE=Debug``` to have all the debug output.

### Executable ring-rest
The executable is the default target
```sh
mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
./ring-rest
```

### Static library
To build libring-rest.a and install it
```sh
mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make ring-rest-static
sudo make install # not implemented yet
```

### Shared library
To build libring-rest.so and install it
```sh
mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make ring-rest-shared
sudo make install # not implemented yet
```

## Options
```
Options:
  -h [ --help ]             Print help messages
  -p [ --port ] arg (=8080) Server's port. Default is 8080
  -t [ --threads ] arg (=4) Number of threads used by the server. Default is
                            maximum usable
```
