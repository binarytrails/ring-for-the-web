.PHONY: clean

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin) 
    LIB_EXT := .dylib
else
    LIB_EXT := .so
endif

simple:
	g++ -o simple.out simple.cpp -std=c++11 \
		-lrestbed -lcrypto -lpthread -lssl

clean:
	rm -rf *$(LIB_EXT) *.out

