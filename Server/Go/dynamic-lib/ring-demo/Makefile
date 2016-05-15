.PHONY: clean

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin) 
    DYLIB_EXT := .dylib
else
    DYLIB_EXT := .so
endif

all: server/libserver$(DYLIB_EXT) main

server/libserver$(DYLIB_EXT):
	$(MAKE) -C server

main:
	$(MAKE) -C daemon

clean:
	rm -f daemon/main server/libserver.* server/server{,.a,.h}
	
