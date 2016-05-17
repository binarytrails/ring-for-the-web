#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include <iostream>
#include <memory>
#include <boost/asio.hpp>
#include <boost/log/trivial.hpp>

#include "manager.hpp"

namespace asio = boost::asio;

namespace Muffin
{

template<class T> 
class Manager;

/*
 *	Each Connection represents a request from the client
 */
template<class T>
class Connection : public std::enable_shared_from_this<Connection<T> >
{


	public:
		Connection(boost::asio::io_service& io_service, Manager<T> manager): 
			socket_(io_service), manager_(manager)
		{}

		T& socket()
		{
			return socket_;
		}

		void start()
		{
			read_();
		}

		void stop()
		{
		}

	private:
		void read_()
		{
			auto self(this->shared_from_this());
			socket_.async_read_some(asio::buffer(buffer_),
				[this, self](boost::system::error_code ec, std::size_t bytes)
				{
					if(!ec)
					{
						BOOST_LOG_TRIVIAL(info) << bytes << " bytes received";
						BOOST_LOG_TRIVIAL(info) << "HTTP Request\n" << buffer_.data();

						// Something about parsing here

						write_();
					}
					else if(ec != asio::error::operation_aborted)
					{
						manager_.stop(this->shared_from_this());
					}
				});
		}

		void write_()
		{
			std::string msg = "HTTP/1.0 200 OK\r\n";

			auto self(this->shared_from_this());
			asio::async_write(socket_, asio::buffer(msg.c_str(), msg.size()), 
				[this, self](boost::system::error_code ec, std::size_t bytes)
				{
					if(!ec)
					{
						BOOST_LOG_TRIVIAL(info) << bytes << " bytes sent";
						BOOST_LOG_TRIVIAL(info) << "HTTP/1.0 200 OK"; // TEMPORARY

						boost::system::error_code ignored;
          				socket_.shutdown(T::shutdown_both, ignored);
					}

					if (ec != asio::error::operation_aborted)
					{
						manager_.stop(this->shared_from_this());
					}
				});
		}
	

		T socket_;
		boost::array<char, 4096> buffer_;
		Manager<T> manager_;
};

} // namespace Muffin

#endif	/* CONNECTION_HPP */

