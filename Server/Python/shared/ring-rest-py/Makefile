.PHONY: clean

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin) 
    LIB_EXT := .dylib
else
    LIB_EXT := .so
endif

main:
	g++ -o main.out main.cpp -lringrestpy

main-local:
	g++ -o main.out main.cpp -L./ -lringrestpy

shared:
	g++ -o libringrestpy$(LIB_EXT) pyserver.cpp -Wall -shared -fPIC -I/usr/include/python2.7 -lpython2.7

install:
	sudo mv libringrestpy$(LIB_EXT) /usr/lib/

uninstall:
	sudo rm -f /usr/lib/libringrestpy$(LIB_EXT)

clean:
	rm -rf *$(LIB_EXT) *.out {*,api/*}.pyc __pycache__/

