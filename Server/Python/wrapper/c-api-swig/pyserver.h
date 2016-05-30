#ifndef PYSERVER_H
#define PYSERVER_H

#include <python2.7/Python.h>
#include <assert.h>

#include <dring/dring.h>

// Each of those should have a corresponding PyServer header file
#include <dring/callmanager_interface.h>
#include "dring/configurationmanager_interface.h"
#include "dring/presencemanager_interface.h"
#ifdef RING_VIDEO
#include "dring/videomanager_interface.h"
#endif

class PyServer
{
    public:
        PyServer(int flags, bool persistent);
        ~PyServer();

        void startServer();

    private:
        int initLibrary(int flags);
};

#endif
