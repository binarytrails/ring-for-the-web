# Relevant comment

cdef extern from "string" namespace "std":
    cdef cppclass string:
        char* c_str()

cdef extern from "cpp/daemon.h":
    cdef cppclass Daemon:
        Daemon() except+
        string callme()

# dring

cdef extern from "dring.h" namespace "DRing":
    pass

