#ifndef ROUTER_HPP
#define ROUTER_HPP

#include <string>
#include <functional>
#include <unordered_map>

namespace Muffin
{

class Router
{
	public:
		Router() {};
		
		void addRoute(std::string path, std::function<std::string()> func);

		static std::unordered_map<std::string, std::function<std::string()>> routes;
	private:
};

} // namespace Muffin

#endif	/* ROUTER_HPP */
