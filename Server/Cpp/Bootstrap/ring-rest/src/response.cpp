#include "response.hpp"

#include <ctime>

#include "router.hpp"
#include "http_status.hpp"

namespace Muffin
{

std::string
Response::generate(json& req)
{
	std::string res = "";

	if(req["Method"] == "GET")
	{
		auto search = Router::routes.find(req["Path"]);
		if(search != Router::routes.end()) {
			std::string h = statusCodes[200];
			std::string t = "Date: " + daytime_() + "\r\n";
			std::string s = "Server: Muffin 1.0\r\n";
			
			std::string content = search->second();
			std::string type = "Content-Type: text/html\r\n";
			std::string length = "Content-Length: " + std::to_string(content.size()) + "\r\n";
			res = h + t + s + length + type + "\r\n" + content + "\r\n"; 
		}
		else {
			res = statusCodes[404];	
		}
	}
	else if(req["Method"] == "POST")
	{
		res = statusCodes[200];
	}	
	else	
	{
		res = statusCodes[400];
	}

	return res;
}

std::string
Response::daytime_()
{
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	time (&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer,80,"%a %b %d %H:%M:%S %Y",timeinfo);
	std::string time(buffer);

  	return time;
}

} // namespace Muffin
