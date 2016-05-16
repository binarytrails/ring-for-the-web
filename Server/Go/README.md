# Goland

## Introduction

[Go for C++ Programmers](https://github.com/golang/go/wiki/GoForCPPProgrammers)

[Syntax standards in comparison to Java](https://www.nada.kth.se/~snilsson/go_for_java_programmers/#Syntax)

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

