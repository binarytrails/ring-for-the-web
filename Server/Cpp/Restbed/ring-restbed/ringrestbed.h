#ifndef RINGRESTBED_H
#define RINGRESTBED_H

#include <assert.h>

#include <dring/dring.h>

// Each of those should have a corresponding RingRestbed header file
#include <dring/callmanager_interface.h>
#include "dring/configurationmanager_interface.h"
#include "dring/presencemanager_interface.h"
#ifdef RING_VIDEO
#include "dring/videomanager_interface.h"
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
