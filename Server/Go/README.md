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

    go build -work

## Go with C++

### Wrapping C++ in C

@TODO

### Using SWIG for C++

There is some documentaiton about how to use SWIG and Go on their [website](http://www.swig.org/Doc2.0/Go.html) but it is not always accurate. Starting from Go 1.2 (I am using [1.6.2](https://golang.org/doc/go1.6#swig)), SWIG has been merged into Go which implies that you don't need to run a variety of SWIG commands by hand. Go handles almost everything.

#### Compiling and running

There is two ways to do it:

	go build -v
	./ring-demo

	go run server.go

#### Getting generated methods documentation

There is two ways to achieve that:

1. Telling Go to keep the temporary genarated files

	    go build --work

    It's time to go [beyond the horizon](https://en.wikipedia.org/wiki/Event_Horizon_%28film%29):

	    cd /tmp/.../ring-web/deamon/_obj/
	    go doc
	    go doc <Method>

2. Using SWIG manually

    Go into your package folder containing the .swigcxx file. In our case:

        cd ring-demo/daemon/

    Warning: You will have to delete manually the SWIG generated files:

	    swig -intgosize 32 -go -c++ daemon.swigcxx

    Now, you can access the docs related to the generated methods as previously.

