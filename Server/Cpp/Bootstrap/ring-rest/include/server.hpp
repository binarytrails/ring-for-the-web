#ifndef SERVER_HPP
#define SERVER_HPP

// Standard Library
#include <iostream>
#include <string>
#include <thread>
#include <future>    
#include <memory>
#include <cstdint>
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

			Server(unsigned short port, std::uint16_t nbThreads) :
				port_(port), nbThreads_(nbThreads), ios_(), 
				acceptor_(ios_, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port_))
			{
#ifdef DEBUG
				std::cout << __PRETTY_FUNCTION__ << "\n";
#endif
			}

			~Server()
			{
#ifdef DEBUG
				std::cout << __PRETTY_FUNCTION__ << "\n";
#endif
				stop_();
			}

			void run()
			{
#ifdef DEBUG
				std::cout << __PRETTY_FUNCTION__ << "\n";
#endif
				for(int i = 0; i < nbThreads_;  ++i) {
                	iosPool_.emplace_back(new boost::asio::io_service());
					std::async(std::launch::async, [this, i]{
						iosPool_[i]->run();	
					});
				}

				accept_();
				
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
				ios_.stop();
				for(auto &ios: iosPool_)
					ios->stop();
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
			const std::uint16_t nbThreads_;
			asio::io_service ios_;	
			std::vector<std::unique_ptr<asio::io_service> > iosPool_;
			asio::ip::tcp::acceptor acceptor_;
		};

} // namespace Muffin

#endif	/* SERVER_HPP */
