#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include <iostream>
#include <string>

#include <boost/log/trivial.hpp>

#include "json.hpp"

using json = nlohmann::json;

namespace Muffin
{

class Response
{
	public:
		static std::string generate(json& req);

	private:
		static std::string daytime_();
};

} // namespace Muffin

#endif	/* RESPONSE_HPP */
