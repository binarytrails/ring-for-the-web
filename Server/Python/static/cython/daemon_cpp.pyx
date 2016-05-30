# Relevant comment

cdef extern from "string" namespace "std":
    cdef cppclass string:
        char* c_str()

cdef extern from "daemon.h":
    cdef cppclass Daemon:
        Daemon() except+
        string callme()

cdef Daemon* dring = new Daemon()
print(dring.callme())

