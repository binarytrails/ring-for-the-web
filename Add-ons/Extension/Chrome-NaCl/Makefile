
#PNACL_PATH = $(NACL_SDK)/toolchain/linux_pnacl
PNACL_PATH = /home/simon/Sdk/pepper_49/toolchain/linux_pnacl

PNACL_FINALIZE := $(PNACL_PATH)/bin/pnacl-finalize
PNACL_CXX = $(PNACL_PATH)/bin/pnacl-clang++
CXXFLAGS = -std=gnu++11 -Wall -pedantic
#LDFLAGS = -I$(NACL_SDK)/include -L$(NACL_SDK)/lib/pnacl/Release -lppapi_cpp -lppapi
LDFLAGS = -I/home/simon/Sdk/pepper_49/include -L/home/simon/Sdk/pepper_49/lib/pnacl/Release -lppapi_cpp -lppapi

all: dir pexe

dir:
	mkdir -p pnacl

pexe: bc
	$(PNACL_FINALIZE) -o pnacl/ring.pexe pnacl/ring.bc

bc:
	$(PNACL_CXX) -o pnacl/ring.bc src/ring.cc -O2 $(CXXFLAGS) $(LDFLAGS)

clean:
	rm -r pnacl
