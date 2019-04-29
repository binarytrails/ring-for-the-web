**Update (2019):**

Multiple changes has been brought up as a new need has appreared at Ring now called [Jami](jami.net) and its network [OpenDHT](https://opendht.net).

# Libraries

HTTP / REST:

Library | C / C++ | License | Cross-platform | Complexity | Size | Releases / Maintenance | Session | Content
---|---|---|---|---|---|---|---|---
[Restbed](https://github.com/Corvusoft/restbed) | C++ | AGPL | Yes | Average | Large | Yes | Yes | REST
[pistache](https://github.com/oktal/pistache) | C++ | Apache2 | [No win](https://github.com/oktal/pistache/issues/6) | Easy | Huge (1.6M) | Yes | ? | REST
[cpp-httplib](https://github.com/yhirose/cpp-httplib) | C++ | MIT | Maybe | Fine | Header | Yes | ? | HTTP
[uWebScokets](https://github.com/uNetworking/uWebSockets) | C++17 header-only | Apache2.0 | Seems | Average | Average | Lots | ? | http, websockets, js lib
[oatpp](https://github.com/oatpp/oatpp) | C++ | Apache2.0 | [Todo Win](https://github.com/oatpp/oatpp/issues/2) | Ok | Average | Yes | ? | fast web, rest, async
[cpr](https://github.com/whoshuu/cpr) | C++11 | MIT | [Maybe](https://github.com/whoshuu/cpr/search?q=windows&type=Issues) | Easy | Average | Yes | [Maybe](https://github.com/whoshuu/cpr/search?q=session&type=Issues) | Spiritual port of Python Requests, Rest, Asynci and more
[restino](https://github.com/Stiffstream/restinio) | C++14 | BSD3 | Yes | Average | Huge | Yes | ? | REST
[]() | | | | | | | | 

With boost:

Library | C / C++ | License | Cross-platform | Complexity | Size | Releases / Maintenance | Content
---|---|---|---|---|---|---|---
[Crow](https://github.com/ipkn/crow) | C++ | BSD3 | Probably | Easy | Header | Not maintained | REST
[cpprestsdk/casablanca](https://github.com/Microsoft/cpprestsdk) | C++ | Apache2 | Yes | Hard | Huge (2M) | Yes | REST
[evpp](https://github.com/Qihoo360/evpp) | C++ | BSD3 | Yes | Fine | Huge | Yes | high load for TCP/UDP/HTTP
[facebook/proxygen](https://github.com/facebook/proxygen) | C++ | BSD | Yes | Average | Average | Lots | Libraries with HTTP server

Not C++ but may fit:

Library | C / C++ | License | Cross-platform | Complexity | Size | Releases / Maintenance | Content
---|---|---|---|---|---|---|---
[onion](https://github.com/davidmoreno/onion) | C | Apache2.0 & GPLv2 | Seems | Average | Average | Yes | Webserver as plugin

Far from REST but worth mention:

Library | C / C++ | License | Cross-platform | Complexity | Size | Releases / Maintenance | Boost | Content
---|---|---|---|---|---|---|---|---
[dyad](https://github.com/rxi/dyad) | C | MIT | - | Easy | Light | Not maintained | No | Async TCP
[cpp-netlib](https://github.com/cpp-netlib/cpp-netlib) | C++ | Boost | Yes | Medium | Medium | Yes | Yes | HTTP
[restclient-cpp](https://github.com/mrtazz/restclient-cpp) | C++ | MIT | | | | Yes | | libcurl wrapper


Definitions:

- [Header-only](https://en.wikipedia.org/wiki/Header-only)

# Considerations

## Restbed

Not compatible for reselling without fees.

## Crow

Not maintained but boost may be replaced with native async.

Microframework for Web, inspired by Python Flask. See the [debate](https://news.ycombinator.com/item?id=8002604) on its usability / performance.

## Pistache

Great but no Windows support.

## Dyad

Simple, direct but no http support.

