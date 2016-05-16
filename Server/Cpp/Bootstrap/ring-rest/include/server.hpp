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
			}

			~Server()
			{
				stop_();
			}

			void run()
			{
				// Launch all the threaded io_services. If the server is single threaded, this will skip itself
				for(int i = 0; i < nbThreads_;  ++i) {
                	iosPool_.emplace_back(new boost::asio::io_service());
					std::async(std::launch::async, [this, i]{
						iosPool_[i]->run();	
					});
				}

				// Start to accept requests
				accept_();
				
				// Run the main process	
				ios_.run();
			}

		private:
			void accept_()
			{
				asio::io_service &ios = iosFinder_();

				auto c = new Connection<T>(ios);

				acceptor_.async_accept(c->socket(), [this, c, &ios](boost::system::error_code error)
                {
                    if (!error)
                    {
                        ios.post([c]
                        {
                            c->start();
                        });
                    }
					else
					{
						BOOST_LOG_TRIVIAL(error) << error.message();
					}

                    accept_();
                });
			}

			void stop_()
			{
				ios_.stop();
				for(auto &ios: iosPool_)
					ios->stop();
			}

			asio::io_service& iosFinder_()
			{
				if(index_ >= 4)
					index_ = 0;
					
				return *iosPool_[index_];
			}

			const unsigned short port_;
			const std::uint16_t nbThreads_;
			unsigned int index_ = 0;
			asio::io_service ios_;	
			std::vector<std::unique_ptr<asio::io_service> > iosPool_;
			asio::ip::tcp::acceptor acceptor_;
		};

} // namespace Muffin

#endif	/* SERVER_HPP */
