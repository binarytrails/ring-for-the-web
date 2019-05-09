**Update (2019):**

Multiple changes has been brought up as a new need has appreared at Ring now called [Jami](jami.net) and its network [OpenDHT](https://opendht.net).

# Libraries

HTTP / REST (ordered by best fit):

Library | C / C++ | License | Cross-platform | Complexity | Size | Releases / Maintenance | Session | Content
---|---|---|---|---|---|---|---|---
[~~Restbed~~](https://github.com/Corvusoft/restbed) | C++ | AGPL | Yes | Average | Large | Yes | Yes | REST
[~~pistache~~](https://github.com/oktal/pistache) | C++ | Apache2 | [No win](https://github.com/oktal/pistache/issues/6) | Easy | Huge (1.6M) | Yes | ? | REST
[restino](https://github.com/Stiffstream/restinio) | C++14 | BSD3 | Yes | Average | Huge | Yes | Yes with [Async HTTP Pipelining](https://github.com/Stiffstream/restinio/tree/master/dev/test/http_pipelining) | Rest
[envoy](https://github.com/envoyproxy/envoy) | C++ | Apache2.0 | Yes | Elevate | Massive | Lots | Probably | Used by many major corps. & has a [security audit](https://github.com/envoyproxy/envoy/blob/master/docs/SECURITY_AUDIT.pdf)
[~~oatpp~~](https://github.com/oatpp/oatpp) | C++ | Apache2.0 | [Todo Win](https://github.com/oatpp/oatpp/issues/2) | Wild | Gigantic | Yes | No | fast, rest, async, **very complex**
[~~cpp-httplib~~](https://github.com/yhirose/cpp-httplib) | C++ | MIT | Maybe | Fine | Header | Yes | No | HTTP, [not async](https://github.com/yhirose/cpp-httplib/issues/133)
[~~libhttpserver~~](https://github.com/etr/libhttpserver) | C++ | LGPL-2.1 | Yes | Average | Average | Yes | No | not async
[]() | | | | | | | | 


Turns out to be w/o a native server but has it all:

Library | C / C++ | License | Cross-platform | Complexity | Size | Releases / Maintenance | Session | Content
---|---|---|---|---|---|---|---|---
[cpr](https://github.com/whoshuu/cpr) | C++11 | MIT | [Maybe](https://github.com/whoshuu/cpr/search?q=windows&type=Issues) | Easy | Average | Yes | Yes [but](https://github.com/whoshuu/cpr/issues/69) | Async, libcurl, for its server, it uses [mongoose](https://github.com/cesanta/mongoose)

With boost:

Library | C / C++ | License | Cross-platform | Complexity | Size | Releases / Maintenance | Content
---|---|---|---|---|---|---|---
[Crow](https://github.com/ipkn/crow) | C++ | BSD3 | Probably | Easy | Header | Not maintained | REST
[cpprestsdk](https://github.com/Microsoft/cpprestsdk) | C++ | Apache2 | Yes | Hard | Huge (2M) | Yes | REST
[evpp](https://github.com/Qihoo360/evpp) | C++ | BSD3 | Yes | Fine | Huge | Yes | high load for TCP/UDP/HTTP
[facebook/proxygen](https://github.com/facebook/proxygen) | C++ | BSD | Yes | Average | Average | Lots | Libraries with HTTP server

Not C++ but may fit:

Library | C / C++ | License | Cross-platform | Complexity | Size | Releases / Maintenance | Session | Content
---|---|---|---|---|---|---|---|---
[~~onion~~](https://github.com/davidmoreno/onion) | C | Apache2.0 & GPLv2 | Seems | Average | Average | Yes | Yes | Webserver as plugin, [not async](https://github.com/davidmoreno/onion/issues/237)

Far from REST but worth mention:

Library | C / C++ | License | Cross-platform | Complexity | Size | Releases / Maintenance | Boost | Content
---|---|---|---|---|---|---|---|---
[dyad](https://github.com/rxi/dyad) | C | MIT | - | Easy | Light | Not maintained | No | Async TCP
[cpp-netlib](https://github.com/cpp-netlib/cpp-netlib) | C++ | Boost | Yes | Medium | Medium | Yes | Yes | HTTP
[restclient-cpp](https://github.com/mrtazz/restclient-cpp) | C++ | MIT | | | | Yes | | libcurl wrapper
[uWebScokets](https://github.com/uNetworking/uWebSockets) | C++17 header-only | Apache2.0 | Seems | Average | Average | Lots | No | websockets, js lib, clang


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

## CPR

The code is great, it handles sessions but there is no embedded server.

