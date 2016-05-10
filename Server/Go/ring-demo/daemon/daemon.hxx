#ifndef DAEMON_HXX
#define DAEMON_HXX

#include <iostream>

class Daemon
{
    public:
        Daemon();
        ~Daemon();

        std::string echo();
        void echo(std::string input);
};

#endif
