# Ring-web

Ring-web uses the Ring daemon ([dring](https://gerrit-ring.savoirfairelinux.com/#/q/status:open)) which is written in C++.

## State of things

1. At first our mission was to create support for web using the browser directly.

2. Now, we are oriented into creating a RESTful API closely bound to the daemon to allow simple communication.

    1. Read [Why choosing Go?](https://github.com/sevaivanov/ring-web-demos#go-1) and track the [Go server progress](https://github.com/sevaivanov/ring-web-demos/blob/master/Server/Go/README.md#state-of-things).

## 1. Control delegated to the browser

This approach is user-friendly because it allows anyone to install it directly as an Add-on that can be used to control the daemon. For this there are a few options: 

### Executing the C++ binary

This part is under [Add-ons/Extensions/](Add-ons/Extensions/). Firefox dropped the support for its engine XPCOM. For more information, see its [Readme](Add-ons/Extensions/XPCOM/README.md). Nowadays, Firefox focuses on the WebExtensions which are essentialy compatible with Chrome and Opera. They are focusing into providing a native Web Extension instead of an Extension. Chrome does allow Extensions using NaCL: see an [example](Add-ons/Extensions/Chrome-NaCl/) but they are focusing more on the Chrome Apps.

### Compiling the daemon into Javascript

![Asm.js](Resources/Images/c_to_js.png)

#### Why not Emscripten?

For those who don't know [Emscripten](https://github.com/kripken/emscripten), it's a really nice [LLVM](https://en.wikipedia.org/wiki/LLVM) to Javascript compiler. So basically, it will be able to generate LLVM bytecode from C/C++ and compiles it into Javascript. 

Useful to compile the daemon into JS, isn't it? Unfortunately, the compiler still has trouble with the [long long type](http://stackoverflow.com/questions/18971732/what-is-the-difference-between-long-long-long-long-int-and-long-long-i) in C++, so we were unable to compile all the ring-daemon dependancies (specially [GMP Library](https://gmplib.org)). But give it time, and maybe some day we'll be able to compile it.

Here's what I got so far

    sh
    RING=$PWD/ring-daemon
    cd $RING/contrib

    # Make the dependancies using emmake, a little script that will override the variables for emscripten
    mkdir build
    cd build
    ../bootstrap
    emmake make

    # And for the daemon compilation
    cd $RING
    ./autogen
    # Same as emmake, emconfigure will override the variables in ./configure
    emconfigure ./configure # Dont forget the flags you want
    emmake make
    sudo emmake install

## 2. RESTful Server

At the moment, we are going with the second option of delegating the control to the daemon.

### Wrapping the Daemon

#### Go

See Go [Readme](Server/Go/README.md) and [example](Server/Go/wrapper).

#### NodeJS

The base of the server has been written but the binding has not been implemented.

See [example](Server/Nodejs/ring-demo/).

### Delegating control to the Daemon using shared library

#### Python

Follow the [Work in Progress](Server/Python/).

#### Go

The PROs of this option are that it is fast to implement (has a build-in http server), easy to maintain, scalable and supports concurrency.

The main part of the work would be to create mapping from C++ uncommon Objects that are not supported by built-in SWIG support. Although, there is an [excellent example](https://github.com/savoirfairelinux/ring-client-android/blob/master/ring-android/app/src/main/jni/jni_interface.i) of how this can be done in ring-client-android. 

The major CON would be to define the interaction with the daemon to provide a Go Callback function.

Go supports pointers but it provides automatic garbage collection of allocated memory. Therefore, to avoid memory leaks there should be a careful destruction of each shared pointer before the Go garbage collector does its duties.

See [Readme](Server/Go/README.md) and [example](Server/Go/dynamic-lib/ring-demo/).

#### C / C++

The Pro is that is it directly compatible with C++

##### Writing from scratch using Bootstrap

TODO Move Cpp/ring-rest -> Cpp/Bootstrap/ring-rest/

##### Using existing libraries

Library | C / C++ | GPLv3 Compatible | Cross-platform | Complexity | Size | Latest Release
---|---|---|---|---|---|---
[Restbed](https://github.com/Corvusoft/restbed) | C++ | Yes | Yes | Average | Large | 4.0 : 28-05-2016 
[Crow](https://github.com/ipkn/crow) | C++ | Yes | Yes | Easy | Short | Last commit in march
[cpprestsdk](https://github.com/Microsoft/cpprestsdk) | C++ | Yes | Yes | Hard | Huge | 2.8.0 : 25-02-2016
[cpp-netlib](https://github.com/cpp-netlib/cpp-netlib) | C++ | Yes | Yes | Medium | Medium | 0.12.0 : 30-03-2016
[dyad](https://github.com/rxi/dyad) | C | Yes | Yes | Easy | Light | Last commit 9 month ago

###### Restbed

The release 3.5 and the most recent one 4.0 have a dependency *asio* that needs a [patch](https://bugs.archlinux.org/task/48620#comment145230) to counter the restbed build fail caused by:

    error: ‘::SSLv3_server_method’ has not been declared

