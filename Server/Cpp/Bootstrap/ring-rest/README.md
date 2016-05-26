#Cpp

## Introduction

This is a C++ HTTP server, maybe it will support HTTPS in the futur.
Also it is named Muffin.

## Dependancies

[Boost 1.60](http://www.boost.org)
[OpenSSL](https://www.openssl.org) to use the HTTPS socket

## Build

### Executable ring-http
While waiting for the ring-daemon plugin structure, I'm working on an executable, packaging the server and the daemon.
I'm using automake to compile it.
```sh
./autogen.sh
./configure
make
./src/ring_http
```

### Static library
Not implemented yet

### Shared library
Not implemented yet

## Options
```
Options:
  -h [ --help ]         Print help messages
  --port arg (=8080)    Server's port. Default is 8080
  -c [ --console ]      Log in console (instead of syslog)
  -d [ --debug ]        Debug mode (more verbose)
  -p [ --persistent ]   Stay alive after client quits
  --auto-answer         Force automatic answer to incoming calls
```
