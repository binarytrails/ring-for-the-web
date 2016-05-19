# http-parser

## Description

http-parser is a lightweight HTTP parser written in c++11

## Dependencies

The project is using a json.h header from [nlohmann(https://github.com/nlohmann/json), but don't worry, the header is already in the project.

## Compilation

It's as easy as ABC
```sh
	make
	./http-parser [your http request file]
```

It uses clang++ as the default compiler, but you can change by overriding the CXX var.

## Usage

It is very easy to use it as a file in your project
```c++
#include <iostream>
#include <string>

#include "parserHTTP.hpp"
#include "json.hpp"

int main(int argc, char* argv[])
{
	// String containing the entire request
	std::string request;

	// Create a new parser
	ParserHTTP parser;

	// It will parse the request into a json file
	nlohmann::json parsed = parser.parse(request);

	// And then, to whatever you want to do with the json

	// For example, you can display it!
	std::cout << parsed.dump(4) << "\n";

	return 0;
}
```

More example on what you can do with the json on [nlohmann's page](https://github.com/nlohmann/json)
