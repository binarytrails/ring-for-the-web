# C++ HTTP Server

## Introduction

The main purpose of this project is to create a simple and fast HTTP server, C++11 compatible, who will handle the talk between a web interface and the [ring-daemon](https://github.com/savoirfairelinux/ring-daemon). The server is written with [Boost.asio](http://www.boost.org/doc/libs/1_61_0/doc/html/boost_asio.html) with asynchronous calls.

## Work done

Up to this date, here's what we got :
 - Parsing the argument
 - Connecting to a socket and listen on localhost
 - Sending a dummy response when there's a socket
 - HTTP request to json parser
 - Listing the HTTP status code

## Working on it
 - Routing for the queries

## Todo List
 - Responding correctly to the queries
 - Integrate the daemon headers into the server




