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

int main()
{ 
    std::cout << "C++: Daemon is starting the Go server..";
    char *message = "C++: Daemon started the Go server";
    initServer(message);
    startServer();
}

