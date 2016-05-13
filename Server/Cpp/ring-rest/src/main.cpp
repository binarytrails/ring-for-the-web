#include <iostream>
#include <thread>

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
        namespace po = boost::program_options;
        po::options_description desc("Options");
        desc.add_options()
            ("help,h", "Print help messages")
            ("port,p", po::value<unsigned short>()->default_value(8080), "Server's port. Default is 8080");

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

        // Copy the parameters
        unsigned short port = vm["port"].as<unsigned short>();
        std::cout << "\tPort is " << port <<  "\n";

        // Creating the server
        Muffin::Server<Muffin::HTTP> server(port);

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
