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
class Connection
{
	public:
		Connection(boost::asio::io_service& io_service): 
			socket_(io_service)
		{}

		T& socket()
		{
			return socket_;
		}

		void start()
		{
			socket_.async_read_some(boost::asio::buffer(buffer_), 
                [this](const boost::system::error_code& error, std::size_t bytes)
                {
                    if(error)
                    {
						BOOST_LOG_TRIVIAL(error) << error.message();
                    }
					else
					{
						BOOST_LOG_TRIVIAL(info) << bytes << " bytes transferred";
						BOOST_LOG_TRIVIAL(info) << std::cout.write(&buffer_[0], 4096);
					}
                });
		}

	private:

		T socket_;
		boost::array<char, 4096> buffer_;
};

} // namespace Muffin

#endif	/* CONNECTION_HPP */

