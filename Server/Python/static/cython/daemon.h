#ifndef DAEMON_H
#define DAEMON_H

#include <string>

class Daemon
{
    public:
        Daemon();
        ~Daemon();

        std::string callme();
};

#endif
