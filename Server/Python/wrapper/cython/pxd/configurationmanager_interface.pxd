from libcpp.string cimport string
from libcpp cimport bool as boolean
from libcpp.map cimport map as map

cdef extern from "configurationmanager_interface.h" namespace "DRing":

    map[string, string] getAccountDetails(const string& accountID);

