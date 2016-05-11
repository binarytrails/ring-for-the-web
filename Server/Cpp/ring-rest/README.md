#Cpp

## Introduction

This is a C++ HTTP server, maybe it will support HTTPS in the futur.
Also it is named Muffin.

## Dependancies

Boost 1.60

## Build
```sh
mkdir -p build
cd build
cmake ..
make
./ring-rest
```

## Options
```
Options:
  -h [ --help ]             Print help messages
  -p [ --port ] arg (=8080) Server's port. Default is 8080
  -t [ --threads ] arg (=4) Number of threads used by the server. Default is
                            maximum usable
```
