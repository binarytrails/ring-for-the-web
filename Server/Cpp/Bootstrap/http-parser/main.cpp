#include <iostream>
#include <string>
#include <fstream>

#include "parserHTTP.hpp"
#include "json.hpp"

int main(int argc, char* argv[])
{
	// Handling lambda users
	if(argc != 2)
	{
		std::cerr << "You need to give a file as an argument to make this work, like ./http-parser [file]\n";
		return 1;
	}
	
	// Copy the argument
	std::string file = argv[1];	
	std::cout << "Processing " << file << std::endl;

	// Parse the file into a stream
	std::ifstream ifs(file);
 	std::string request((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

	// Creating a new parser
	ParserHTTP parser;

	// Create a new json object to get the parsed data
	nlohmann::json parsed;

	try
	{
		// Parse the request into a json file
		parsed = parser.parse(request);
	} 
	catch(std::exception& e) 
	{
		std::cerr << "Exception caught : " << e.what() << '\n';
	}

	// Display the parsed request
	std::cout << "Parsed request : \n";
	std::cout << parsed.dump(4) << "\n";	

	return 0;
}
