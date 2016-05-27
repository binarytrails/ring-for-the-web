#include "pyserver.h"

int main(int argc, char* argv[])
{
    setenv("PYTHONPATH", argv[1], 1);
    
    PyServer pyserver;
    pyserver.startServer();
    
    return 0;
}
