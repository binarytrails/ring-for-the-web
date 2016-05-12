# Ring-web

Exploring the possibilities

## Why not Emscripten?

For those who don't know [Emscripten](https://github.com/kripken/emscripten), it's a really nice [LLVM](https://en.wikipedia.org/wiki/LLVM) to Javascript compiler. So basically, it will be able to generate LLVM bytecode from C/C++ and compiles it into Javascript. 

Useful to compile the daemon into JS isn't it? Unfortunately, the compiler still have trouble with the [long long type](http://stackoverflow.com/questions/18971732/what-is-the-difference-between-long-long-long-long-int-and-long-long-i) in C++, so we were unable to compile all the ring-daemon dependancies (specially [GMP Library](https://gmplib.org)). But give it time, and maybe some day we'll be able to compile it.

Here's what I got so far
```sh
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
```
