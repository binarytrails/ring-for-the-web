#include <memory>
#include <cstdlib>
#include <restbed>
#include <iostream>

using namespace std;
using namespace restbed;

void getHello(const shared_ptr<Session> session)
{
    const auto request = session->get_request();

    int content_length = 0;
    request->get_header("Content-Length", content_length);

    session->fetch( content_length, [ ](const shared_ptr<Session> session, const Bytes & body)
    {
        fprintf(stdout, "%.*s\n", (int) body.size(), body.data( ));
        session->close(OK, "Hello, World!", {{"Content-Length", "13"}});
    } );
}

int main( const int, const char** )
{
    auto resource = make_shared< Resource >();
    resource->set_path("/hello");
    resource->set_method_handler("GET", getHello);

    auto settings = make_shared<Settings>();
    settings->set_port(8080);
    settings->set_default_header("Connection", "close");

    std::cout << "Available Routes: " <<
        "http://127.0.0.1:8080/hello" << endl;

    Service service;
    service.publish(resource);
    service.start(settings);

    return EXIT_SUCCESS;
}
