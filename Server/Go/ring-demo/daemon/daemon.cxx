#include "daemon.hxx"
#include <iostream>

Daemon::Daemon(){}

Daemon::~Daemon(){}

std::string Daemon::echo()
{
    return "Echo from C++";
}

void Daemon::echo(std::string input)
{
    std::cout << input;
}

