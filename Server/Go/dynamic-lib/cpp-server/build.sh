make clean
make

# LD_LIBRARY_PATH is for Linux, DYLD_LIBRARY_PATH for Mac
LD_LIBRARY_PATH=./server DYLD_LIBRARY_PATH=./server ./main

