#include <iostream>
#include <thread>
#include <cstdint>

#include <boost/program_options.hpp>

#include "server.hpp"

int main(int argc, char* argv[])
{
    #ifdef DEBUG
        std::cout << __PRETTY_FUNCTION__ << "\n";
    #endif
  
    // Handling the arguments
    try
    {
		unsigned short port;
		std::uint16_t threads;

        namespace po = boost::program_options;
        po::options_description desc("Options");
        desc.add_options()
            ("help,h", "Print help messages")
            ("port,p", po::value<unsigned short>(&port)->default_value(8080), "Server's port. Default is 8080")
			("threads,t", po::value<std::uint16_t>(&threads)->default_value(1), "Enable multithreading. Default is 1");

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
        std::cout << "Initializing\n";

        // Display the parameters
        std::cout << "\tPort is " << port << "\n";
		std::cout << "\tRunning on " << threads << (threads == 1 ? " thread\n" : " threads\n");

        // Creating the server
        Muffin::Server<Muffin::HTTP> server(port, threads);

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
