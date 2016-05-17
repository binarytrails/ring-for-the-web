# Goland

## Introduction

[Go for C++ Programmers](https://github.com/golang/go/wiki/GoForCPPProgrammers)

[Syntax standards in comparison to Java](https://www.nada.kth.se/~snilsson/go_for_java_programmers/#Syntax)

## State of things

### Implemented

The two possible ways to implement the RESTful API using an HTTP Server are done.

1. In the *wrapper/* mode, the server handles the daemon.
2. In *dynamic-lib/*, the c++ daemon uses the server as a shared library.
3. In both modes, [Mux](https://github.com/gorilla/mux) to handle the routing which is [GPLv3 compatible](https://github.com/gorilla/mux/issues/164).

### Work in progress

1. I'm looking for a way to specify to *cgo* that is handled during a *go build* different [flags](https://golang.org/cmd/cgo/) to change the project architecture from having everything (*.h, .cpp, .swigcxx*) in one directory to instead have *.h -> includes/*, *.cpp -> /src/*, etc. Likewise, this options should be also passed to built-in SWIG. Otherwise, I might have to analyse the compiling under the hood with *go build -x* and create a Makefile to automate our homemade build. If this is achieved, I will be able to start interacting with the real daemon *dring*.

2. Provide a [callback](https://github.com/swig/swig/tree/master/Examples/java/callback) in *dynamic-lib/* to notify the server if the registered signals have changed. To implement the callback I need to be able to separate the C++ sources files. Otherwise, there is interdependency issue during the server build with an *import "../daemon"* because it needs the libserver.so that is not yet generated. Thus, this is related to **1**. Otherwise, they could be build manually.

## Commands

    go run server.go

    go doc net/http

Show the execution commands:

    go build -x

Keep the temporary build files:

    go build --work

## Go with C++

### Using cgo

A possible way would be to use the Go C library along with different C headers.

#### Memory management

    // #include <stdio.h>
    // #include <stdlib.h>
    import "C"
    import "unsafe"

    // Memory allocations made by C code are not known to Go's memory manager
    cs := C.CString("hello")

    // You have to release them
    C.free(unsafe.Pointer(cs))

The .free is contained in stdlib.h which means that you do need to include it.

Read more about the [cgo command](https://golang.org/cmd/cgo/).

### Wrapping C++ in C

[Working example](https://github.com/burke/howto-go-with-cpp)

### Using SWIG for C++

There is some documentation about how to use SWIG and Go on their [website](http://www.swig.org/Doc2.0/Go.html) but it is not always accurate(i.e. [type mappings](http://www.swig.org/Doc2.0/Go.html#Go_primitive_type_mappings) such as int -> int where in reality int32 -> int). Starting from Go 1.2 (I am using [1.6.2](https://golang.org/doc/go1.6#swig)), SWIG has been merged into Go which implies that you don't need to run a variety of SWIG commands by hand. Go handles almost everything.

#### Compiling and running

There are two ways to do it:

	go build -v
	./web-go-cpp

	go run server.go

#### Getting generated methods documentation

There are two ways to achieve that:

1. Telling Go to keep the temporary genarated files

	    go build --work

    It's time to go [beyond the horizon](https://en.wikipedia.org/wiki/Event_Horizon_%28film%29):

	    cd /tmp/.../web-go-cpp/deamon/_obj/
	    go doc
	    go doc <Method>

2. Using SWIG manually

    Go into your package folder containing the .swigcxx file. In our case:

        cd web-go-cpp/daemon/

    Warning: You will have to delete manually the SWIG generated files:

	    swig -intgosize 32 -go -c++ daemon.swigcxx

    Now, you can access the docs related to the generated methods as previously.

