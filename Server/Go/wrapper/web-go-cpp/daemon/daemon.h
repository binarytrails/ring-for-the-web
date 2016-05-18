#ifndef DAEMON_H
#define DAEMON_H

#include <iostream>
#include <vector>

class Daemon
{
    public:
        Daemon();
        ~Daemon();

        void echo(std::string message);
        void getContacts(std::string ring_id, std::vector<std::string>* contacts);
};

#endif
