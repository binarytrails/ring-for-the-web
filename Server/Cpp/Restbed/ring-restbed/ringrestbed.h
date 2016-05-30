#ifndef RINGRESTBED_H
#define RINGRESTBED_H

#include <assert.h>

#include "dring.h"

// Each of those should have a corresponding RingRestbed header file
#include "callmanager_interface.h"
#include "configurationmanager_interface.h"
#include "presencemanager_interface.h"
#ifdef RING_VIDEO
#include "videomanager_interface.h"
#endif

class RingRestbed
{
    public:
        RingRestbed(int flags, bool persistent);
        ~RingRestbed();

    private:
        int startServer();
        int initLibrary(int flags);
};

#endif
