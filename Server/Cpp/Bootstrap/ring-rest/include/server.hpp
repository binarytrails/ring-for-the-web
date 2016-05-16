#ifndef SERVER_HPP
#define SERVER_HPP

// Standard Library
#include <iostream>
#include <string>
#include <thread>
#include <memory>
#include <unordered_map>

// Boost
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

#include "connection.hpp"

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
				port_(port), ios_(), acceptor_(ios_, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port_))
			{
#ifdef DEBUG
				std::cout << __PRETTY_FUNCTION__ << "\n";
#endif
				accept_();
			}

			~Server()
			{
#ifdef DEBUG
				std::cout << __PRETTY_FUNCTION__ << "\n";
#endif
			}

			void run()
			{
#ifdef DEBUG
				std::cout << __PRETTY_FUNCTION__ << "\n";
#endif

				ios_.run();
			}

		private:
			void accept_()
			{
#ifdef DEBUG
				std::cout << __PRETTY_FUNCTION__ << "\n";
#endif

				typename Muffin::Connection<T>::c_ptr new_connect = Connection<T>::create(acceptor_.get_io_service());

				acceptor_.async_accept(new_connect->socket(),
						boost::bind(&Server::acceptHandler_, this, new_connect,
							boost::asio::placeholders::error));
			}

			void stop_()
			{
#ifdef DEBUG
				std::cout << __PRETTY_FUNCTION__ << "\n";
#endif
			}

			void acceptHandler_(typename Muffin::Connection<T>::c_ptr new_connect, const boost::system::error_code& error)
			{
#ifdef DEBUG
				std::cout << __PRETTY_FUNCTION__ << "\n";
#endif
				if (!error)
				{
					new_connect->start();
					accept_();
				}
			}

			const unsigned short port_;
			asio::io_service ios_;	
			asio::ip::tcp::acceptor acceptor_;
		};

} // namespace Muffin

#endif	/* SERVER_HPP */
