cimport dring_cpp as cpp

cdef class Daemon:
    cdef cpp.Daemon* dring

    def __cinit__(self):
        self.dring = new cpp.Daemon()

    def __dealloc__(self):
        del self.dring

    def callme(self):
        return self.dring.callme()

# test
dring = Daemon()
print(dring.callme())
