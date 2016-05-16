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
			socket_.async_read_some(boost::asio::buffer(buffer_), 
				[this](const boost::system::error_code &error, std::size_t transferred){
					if(error)
					{
						std::cout << "Error while reading some data : " << error.message() << "\n";
					}

					std::cout << transferred << " bytes transferred\n";
					std::cout.write(&buffer_[0], 4096);
						
			});
		}

	private:
		Connection(boost::asio::io_service& io_service): socket_(io_service)
		{
#ifdef DEBUG
			std::cout << __PRETTY_FUNCTION__ << "\n";
#endif
		}

		T socket_;
		boost::array<char, 4096> buffer_;
};

} // namespace Muffin

#endif	/* CONNECTION_HPP */

