#include "router.hpp"

namespace Muffin
{

std::unordered_map<std::string, std::function<std::string()>> Router::routes_;


void
Router::addRoute(std::string path, std::function<std::string()> func)
{
	Router::routes_.insert({path, func});
}

} // namespace Muffin
