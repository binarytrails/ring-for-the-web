#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

namespace Muffin
{

template<class T>
class Connection: public boost::enable_shared_from_this<Connection<T> >
{
	public:
		typedef boost::shared_ptr<Connection<T> > c_ptr;

		static c_ptr create(boost::asio::io_service& io_service)
		{
#ifdef DEBUG
			std::cout << __PRETTY_FUNCTION__ << "\n";
#endif
			return c_ptr(new Connection(io_service));
		}

		T& socket()
		{
#ifdef DEBUG
			std::cout << __PRETTY_FUNCTION__ << "\n";
#endif
			return socket_;
		}

		void start()
		{
#ifdef DEBUG
			std::cout << __PRETTY_FUNCTION__ << "\n";
#endif
			message_ = "Ayy LMAO";

			boost::asio::async_write(socket_, boost::asio::buffer(message_),
					boost::bind(&Connection::writeHandler_, 
						boost::enable_shared_from_this<Connection<T> >::shared_from_this(),
						boost::asio::placeholders::error,
						boost::asio::placeholders::bytes_transferred));
		}

	private:
		Connection(boost::asio::io_service& io_service): socket_(io_service)
		{
#ifdef DEBUG
			std::cout << __PRETTY_FUNCTION__ << "\n";
#endif
		}

		void writeHandler_(const boost::system::error_code &error, size_t size)
		{
#ifdef DEBUG
			std::cout << __PRETTY_FUNCTION__ << "\n";
#endif
			if(error)
				std::cout << "Error : " << error << "\n";	
			else
				std::cout << size << " transferred\n";
		}

		T socket_;
		std::string message_;
  


};

} // namespace Muffin

#endif	/* CONNECTION_HPP */

