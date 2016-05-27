# Nodejs <-> C++

## Installation

Node dependecies from package.json (locally):

    npm install

Node-gyp (globally):
	
    npm install -g node-gyp

It [depends](https://www.npmjs.com/package/node-gyp) on Python, Make, and a C++ compiler like GCC.

## Compiling

    node-gyp configure build

## Run

    node hello.js -a 127.0.0.1:8000

## Help

    node hello.js -h

