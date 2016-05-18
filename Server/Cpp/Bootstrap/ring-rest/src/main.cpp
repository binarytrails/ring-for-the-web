#include <iostream>
#include <thread>
#include <cstdint>

#include <boost/log/trivial.hpp>
#include <boost/program_options.hpp>

#include "server.hpp"

int main(int argc, char* argv[])
{
    // Handling the arguments
    try
    {
		unsigned short port = 0;

        namespace po = boost::program_options;
        po::options_description desc("Options");
        desc.add_options()
            ("help,h", "Print help messages")
            ("port,p", po::value<unsigned short>(&port)->default_value(8080), "Server's port. Default is 8080");

        po::variables_map vm;
        try
        {
            po::store(po::parse_command_line(argc, argv, desc),  vm);

            if ( vm.count("help")  )
            {
              std::cout << "A neat HTTP Server written in C++11 and Boost" << std::endl << desc << std::endl;
              return 0;
            }

            po::notify(vm);
        }
        catch(po::error& e)
        {
            std::cerr << "Error : " << e.what() << std::endl << std::endl;
            std::cerr << desc << std::endl;
            return -1;
        }

        // Server code right here, the other stuff is for boost::program_options
        BOOST_LOG_TRIVIAL(info) << "Initializing";


#ifdef HTTPS
        // Display the parameters
		BOOST_LOG_TRIVIAL(info) << "HTTPS server running on port " << port;
        
		// Creating the server with a HTTP socket
        Muffin::Server<Muffin::HTTPS> server(port);
#else
        // Display the parameters
		BOOST_LOG_TRIVIAL(info) << "HTTP server running on port " << port;
        
		// Creating the server with a HTTP socket
        Muffin::Server<Muffin::HTTP> server(port);
#endif

		// Adding the routes to the server
		server.addRoute("/patates", [](){
			return "carottes";
		});

        // Run the server
        server.run();

    }
    catch(std::exception& e)
    {
        std::cerr << "Unhandled Exception reached the top of main: " << e.what() << ", the server will now exit" << std::endl;
        return -1;
    }

    return 0;
}
