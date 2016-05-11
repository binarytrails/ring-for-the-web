#ifndef SERVER_HPP
#define SERVER_HPP

// Standard Library
#include <iostream>
#include <string>
#include <thread>
#include <unordered_map>

// Boost
#include <boost/asio.hpp>

namespace asio = boost::asio;

namespace Muffin
{

typedef asio::ip::tcp::socket HTTP;

template<class socket>
class Server
{
	public:

		Server(unsigned short port, size_t nbThreads=1) : _port(port), _nbThreads(nbThreads)
		{

		}

		~Server()
		{
				abort();
		}

		void run()
		{
				std::cout << "Running ...\n";

				// Just in case
				if(_ios.stopped())
						_ios.reset();

				/*
				boost::asio::ip::tcp::endpoint endpoint;
				if(config.address.size()>0)
				    endpoint=boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(config.address), config.port);
				else
				    endpoint=boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), config.port);
				acceptor.open(endpoint.protocol());
				acceptor.set_option(boost::asio::socket_base::reuse_address(config.reuse_address));
				acceptor.bind(endpoint);
				acceptor.listen();

				accept();

				//If num_threads>1, start m_io_service.run() in (num_threads-1) threads for thread-pooling
				threads.clear();
				for(size_t c=1;c<config.num_threads;c++) {
				    threads.emplace_back([this](){
				        io_service.run();
				    });
				}

				//Main thread
				io_service.run();

				//Wait for the rest of the threads, if any, to finish as well
				for(auto& t: threads) {
				    t.join();
				}
				*/
		}

		void _abort()
		{
				_ios.stop();
		}

		// The first string correspond to the path, and the second to the action (GET, POST, etc)
		std::unordered_map<std::string, std::unordered_map<std::string, std::function<void()>> > routes;

	private:

		const std::string address = "127.0.0.1";
		const unsigned short _port;
		const size_t _nbThreads;
		asio::io_service _ios;
};

} // namespace Muffin

#endif	/* SERVER_HPP */
