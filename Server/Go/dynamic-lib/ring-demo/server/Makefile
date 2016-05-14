UNAME := $(shell uname)

ifeq ($(UNAME), Darwin) 
    DYLIB_EXT := .dylib
else
    DYLIB_EXT := .so
endif

libserver$(DYLIB_EXT):
	# odd that both are needed?
	go build -v -buildmode=c-archive
	go build -v -o $@ -buildmode=c-shared

clean:
	rm -f libserver.* server.a
