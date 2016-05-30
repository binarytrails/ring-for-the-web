# Ring-rest

It's embedding the Python RESTful API into C++ by using [Python / C API](https://docs.python.org/2/c-api/index.html#c-api-index). The C++ file *pyserver.cpp* is the bridge between the [Ring](https://ring.cx/) daemon and the python code. The C++ bindings are directly used from the Ring-daemon [rest-py fork](https://github.com/sevaivanov/ring-daemon/tree/rest-py).

## Dependencies

### C++ bindings

* Python.h and friends (part of python2-dev on some distros)
* [Ring-daemon](https://gerrit-ring.savoirfairelinux.com/#/admin/projects/ring-daemon)

### Server

* python2.7
* [Bottle](http://bottlepy.org/docs/dev/index.html):

        pip install --user bottle
        pip install -r requirements.txt    # or install it from the dev requirements

## Testing

You can directly interact with the python stand-alone server using the interpreter:

    > import server
    > server.startServer()

You can compile the C++ example *main.cpp* to test the binding using:

    make
    ./dring.out /path/to/python-code         # will add it to PYTHONPATH
    ./dring.out $(pwd)                       # or for set it for current dir

    # if a library is not found, verify where it points:
    ldd ./dring.out
    
    make clean

## License

The code is licensed under a GNU General Public License [GPLv3](http://www.gnu.org/licenses/gpl.html).

## Authors

Seva Ivanov mail@sevaivanov.com

