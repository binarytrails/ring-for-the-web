#include "pyserver.h"

#include <iostream>

int main(int argc, char* argv[])
{
    setenv("PYTHONPATH", argv[1], 1);
    
	std::unique_ptr<PyServer> pyServer;
    try
    {
        pyServer.reset(new PyServer {0, 0});
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Initialization of PyServer client failed: "
            << ex.what() << std::endl;
        return 1;
    }
    pyServer->startServer();

    return 0;
}
