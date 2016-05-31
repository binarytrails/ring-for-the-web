# cython: language_level=3

cimport dring_cpp as cpp
from enum import Enum

cdef class Dring:
    cdef:
        readonly DEBUG
        readonly CONSOLE_LOG
        readonly AUTOANSWER

    def __cinit__(self):
        self.DEBUG          = cpp.DRING_FLAG_DEBUG
        self.CONSOLE_LOG    = cpp.DRING_FLAG_CONSOLE_LOG
        self.AUTOANSWER     = cpp.DRING_FLAG_AUTOANSWER

        print(self.DEBUG)
        cpp.init(self.DEBUG)

