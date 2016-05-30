.PHONY: clean

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin) 
    LIB_EXT := .dylib
else
    LIB_EXT := .so
endif

main:
	g++ -o dring.out main.cpp pyserver.cpp daemon.cpp -std=c++11 -I/usr/include/python2.7 -lpython2.7

clean:
	rm -rf *$(LIB_EXT) *.out {*,api/*}.pyc __pycache__/

