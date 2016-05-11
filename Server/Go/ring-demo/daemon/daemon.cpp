#include "daemon.h"

Daemon::Daemon(){}

Daemon::~Daemon(){}

std::string Daemon::echo()
{
    return "Echo from C++";
}

void Daemon::echo(std::vector<std::string> *results)
{
    results->push_back("Pushed back");
}

