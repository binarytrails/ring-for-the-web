#include "pyserver.h"

PyServer::PyServer(int flags, bool persistent)
{
    /*
        @TODO:
            threading
            persistent
    */

    Py_Initialize();

    //callManager_.reset(new DBusCallManager {sessionConnection});

    if (initLibrary(flags) < 0)
    {
        throw std::runtime_error {"Cannot initialize PyServer"};
    }
}

PyServer::~PyServer()
{
    Py_Finalize();
}

int PyServer::initLibrary(int flags)
{
    using namespace std::placeholders;

    using std::bind;
    using DRing::exportable_callback;
    using DRing::CallSignal;
    using DRing::ConfigurationSignal;
    using DRing::PresenceSignal;
    using DRing::AudioSignal;

    using SharedCallback = std::shared_ptr<DRing::CallbackWrapperBase>;

    //auto callM = callManager_.get();
    
    if (!DRing::start())
    {
        return -1;
    }
    return 0;
}

void PyServer::startServer()
{
    PyObject* serverModule = PyImport_ImportModule("server");
    if (serverModule == NULL)
    {
        PyErr_Print();
    }

    PyObject* startServerFunc = PyObject_GetAttrString(serverModule, "startServer");
    if (startServerFunc == NULL)
    {
        PyErr_Print();
    }

    PyObject_CallObject(startServerFunc, NULL);
}

