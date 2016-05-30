#include "ringrestbed.h"

#include <memory>
#include <cstdlib>
#include <restbed>
#include <iostream>

RingRestbed::RingRestbed(int flags, bool persistent)
{
    /*
        @TODO:
            threading
            persistent
    */
    //callManager_.reset(new DBusCallManager {sessionConnection});

    if (initLibrary(flags) < 0)
    {
        throw std::runtime_error {"Cannot initialize RingRestbed"};
    }
    startServer();
}

RingRestbed::~RingRestbed()
{
}

// TODO change
using namespace std;
using namespace restbed;

// TODO move to Handlers.cpp
void getHello(const shared_ptr<Session> session)
{
    const auto request = session->get_request();

    int content_length = 0;
    request->get_header("Content-Length", content_length);

    session->fetch(content_length, [](const shared_ptr<Session> session, const Bytes & body)
    {
        cout << (int) body.size() << body.data() << endl;
        session->close(OK, "Hello, World!", {{"Content-Length", "13"}});
    } );
}

int RingRestbed::startServer()
{
    auto resource = make_shared<Resource>();
    resource->set_path("/hello");
    resource->set_method_handler("GET", getHello);

    auto settings = make_shared<Settings>();
    settings->set_port(8080);
    settings->set_default_header("Connection", "close");

    cout << "Available Routes: " <<
        "http://127.0.0.1:8080/hello" << endl;
    
    Service service;
    service.publish(resource);
    service.start(settings);

    return EXIT_SUCCESS;
}

int RingRestbed::initLibrary(int flags)
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
    
    // FIXME autotools for libring.a ?
    //if (!DRing::start())
    //{
    //    return -1;
    //}
    return 0;
}

