# C++ HTTP Server

## Introduction

The main purpose of this project is to create a simple and fast HTTP server, C++11 compatible, who will handle the talk between a web interface and the [ring-daemon](https://github.com/savoirfairelinux/ring-daemon). The server is written with [Boost.asio](http://www.boost.org/doc/libs/1_61_0/doc/html/boost_asio.html) with asynchronous calls.

## How to run it
```sh
mkdir -p build
cd build
cmake ..
make
./ring-http
```

Then, go on your favorite web browser, and go to http://127.0.0.1:8080/, and you should see something.
In this example, you can go to http://127.0.0.1:8080/id to get a ringID, and http://127.0.0.1:8080/patates to have a nice vegetable

## Work done

Up to this date, here's what we got :
 - Parsing the argument
 - Connecting to a socket and listen on localhost
 - Sending a dummy response when there's a socket
 - HTTP request to json parser
 - Listing the HTTP status code
 - Routing for the queries
 - Build a correct response to the request
 - Handling GET request

## Working on it
 - Handling POST request

## Todo List
 - Integrate the daemon the server


