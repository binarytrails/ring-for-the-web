#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <string>
#include <thread>
#include <future>    
#include <memory>
#include <cstdint>

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

#include "manager.hpp"
#include "connection.hpp"
#include "router.hpp"

namespace asio = boost::asio;

namespace Muffin
{

typedef asio::ip::tcp::socket HTTP;
typedef asio::ssl::stream<boost::asio::ip::tcp::socket> HTTPS;

template<class T>
class Server
{
	public:

		Server(unsigned short port) :
			port_(port), router_(), ios_(), manager_(),
			acceptor_(ios_, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port_))
		{
			// Default route, just in case		
			addRoute("/", [](){
				return "";
			});
			accept_();
		}

		~Server()
		{
			stop_();
		}

		void run()
		{
			// Run the main process	
			ios_.run();
		}

		void addRoute(std::string path, std::function<std::string()> func)
		{
			router_.addRoute(path, func);
		}

	private:
		void accept_()
		{
			auto c = std::make_shared<Connection<T> >(ios_, manager_);
			acceptor_.async_accept(c->socket(), [this, c](boost::system::error_code ec)
			{
				// Check whether the server was stopped by a signal before this
				// completion handler had a chance to run.
				if (!acceptor_.is_open())
				{
					BOOST_LOG_TRIVIAL(error) << "Acceptor not open";
					return;
				}

				if (!ec)
				{
					manager_.start(c);
				}
				else
				{
					BOOST_LOG_TRIVIAL(error) << "Error launching async_accept";
				}

				accept_();
			});	

		}

		void stop_()
		{
			ios_.stop();
		}
		
		const unsigned short port_;
		unsigned int index_ = 0;
		asio::io_service ios_;	
		asio::ip::tcp::acceptor acceptor_;
		Manager<T> manager_;
		Router router_;
};

} // namespace Muffin

#endif	/* SERVER_HPP */
