#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>
#include <sstream>

#include "json.hpp"

using json = nlohmann::json; 

class ParserHTTP
{
	public:
		ParserHTTP() {};
	
		json parse(std::string& request);			
		
	private:
		std::vector<std::string> tokenize_(const std::string& str, const char delim);
		
		bool isMethod_(const std::string& m);
		bool isHost_(const std::string& h);
		bool containsAccept_(const std::string& a);	
		
};

#endif // PARSER_HPP
