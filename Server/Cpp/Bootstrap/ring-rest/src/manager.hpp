#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <iostream>
#include <memory>
#include <unordered_set>
#include <boost/asio.hpp>
#include <boost/log/trivial.hpp>

#include "connection.hpp"

namespace Muffin
{

/*
 *	The manager is here to handle all the connection, and delete them properly
 */
template<class T>
class Manager
{
	public:
		Manager() {}
		
		void start(std::shared_ptr<Connection<T> > c)
		{
			connections_.insert(c);
  			c->start();
		}

		void stop(std::shared_ptr<Connection<T> > c)
		{
			connections_.erase(c);
  			c->stop();
		}

		void stopAll()
		{
			for (auto c: connections_)
				c->stop();
			connections_.clear();
		}
		

	private:
		std::unordered_set<std::shared_ptr<Connection<T> >> connections_;
};

} // namespace Muffin

#endif	/* MANAGER_HPP */
