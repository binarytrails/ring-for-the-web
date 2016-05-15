UNAME := $(shell uname)

ifeq ($(UNAME), Darwin) 
    DYLIB_EXT := .dylib
else
    DYLIB_EXT := .so
endif

libserver$(DYLIB_EXT):
	go build -v -o $@ -buildmode=c-shared

clean:
	rm -f libserver.* server.a
