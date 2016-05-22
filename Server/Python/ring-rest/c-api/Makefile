.PHONY: clean

UNAME := $(shell uname)

all:
	gcc -o bridge.out bridge.cpp -lpython2.7

clean:
	rm -rf *.out {*,api/*}.pyc __pycache__/
