#include "daemon.h"

Daemon::Daemon(){}

Daemon::~Daemon(){}

void Daemon::echo(std::string message)
{
    std::cout << "C++: " << message << std::endl;
}

