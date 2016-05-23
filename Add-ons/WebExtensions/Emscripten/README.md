# Emscripten

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

