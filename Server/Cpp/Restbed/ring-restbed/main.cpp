#include "ringrestbed.h"

#include <iostream>

int main(int argc, char* argv[])
{
    std::unique_ptr<RingRestbed> ringRestbed;
    try
    {
        ringRestbed.reset(new RingRestbed {0, 0});
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Initialization of RingRestbed client failed: "
            << ex.what() << std::endl;
        return 1;
    }
    return 0;
}
