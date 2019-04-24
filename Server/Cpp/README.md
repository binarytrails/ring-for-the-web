# Libraries

Library | C / C++ | GPLv3 Compatible | Cross-platform | Complexity | Size | Latest Release
---|---|---|---|---|---|---
[Restbed](https://github.com/Corvusoft/restbed) | C++ | Yes | Yes | Average | Large | 4.0 : 28-05-2016
[dyad](https://github.com/rxi/dyad) | C | Yes | Yes | Easy | Light | Last commit 9 month ago
[Crow](https://github.com/ipkn/crow) | C++ | Yes | Yes | Easy | Short | Last commit in march
[cpprestsdk](https://github.com/Microsoft/cpprestsdk) | C++ | Yes | Yes | Hard | Huge (2M) | 2.8.0 : 25-02-2016
[cpp-netlib](https://github.com/cpp-netlib/cpp-netlib) | C++ | Yes | Yes | Medium | Medium | 0.12.0 : 30-03-2016
[pistache](https://github.com/oktal/pistache) | C++ | Yes | Yes | Easy | Huge (1.6M) | Last commit 24-04-2019

## Restbed

The release 3.5 and the most recent one 4.0 have a dependency *asio* that needs a [patch](https://bugs.archlinux.org/task/48620#comment145230) to counter the restbed build fail caused by:

    error: ‘::SSLv3_server_method’ has not been declared

## Crow

It's a C++ [Header-only](https://en.wikipedia.org/wiki/Header-only) Microframework for Web, inspired by Python Flask. See the [debate](https://news.ycombinator.com/item?id=8002604) on its usability / performance.
