#include "daemon.h"

Daemon::Daemon(){}

Daemon::~Daemon(){}

void Daemon::echo(std::string message)
{
    std::cout << "C++: " << message << std::endl;
}

void Daemon::getContacts(std::string ring_id, std::vector<std::string>* contacts)
{
    if (ring_id == "toto")
    {
        contacts->push_back("Dog");
        contacts->push_back("Cat");
        contacts->push_back("Peekaboo");
    }
}

