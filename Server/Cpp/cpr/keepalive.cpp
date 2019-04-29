#include <chrono>
#include <cpr/cpr.h>
#include <iostream>

void request()
{
    auto start = std::chrono::system_clock::now();
    auto response = cpr::Get(cpr::Url{"https://httpbin.org/get"});
    auto end = std::chrono::system_clock::now();
    std::cout << response.text << std::endl;
}

void request2(cpr::Session& session)
{
    auto start = std::chrono::system_clock::now();
    auto response = session.Get();
    auto end = std::chrono::system_clock::now();
    std::cout << response.text << std::endl;
}

int main(int argc, char** argv) {
    // Without session mgmt.
    request();
    request();

    cpr::Session session;
    auto url = cpr::Url{"https://httpbin.org/get"};
    session.SetUrl(url);

    request2(session);
    request2(session);
    request2(session);

    return 0;
}
