#include <iostream>
#include <thread>
#include <cstdint>

#include <boost/log/trivial.hpp>
#include <boost/program_options.hpp>

#include <dring/dring.h>
#include <dring/callmanager_interface.h>
#include <dring/configurationmanager_interface.h>
#include <dring/presencemanager_interface.h>
#include <dring/videomanager_interface.h>

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
			("port", po::value<unsigned short>(&port)->default_value(8080), "Server's port. Default is 8080")		
			("console,c", po::bool_switch()->default_value(false), "Log in console (instead of syslog)")
			("debug,d", po::bool_switch()->default_value(false), "Debug mode (more verbose)")
			("persistent,p", po::bool_switch()->default_value(false), "Stay alive after client quits")
			("auto-answer", po::bool_switch()->default_value(false), "Force automatic answer to incoming calls");

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

		// Init all the stuff related to the daemon
		BOOST_LOG_TRIVIAL(info) << "Init Ring Daemon";

		std::cout
			<< "Ring Daemon " << DRing::version()
			<< ", by Savoir-faire Linux 2004-2016" << std::endl
			<< "http://www.ring.cx/" << std::endl
			<< "[Video support enabled]" << std::endl
			<< std::endl;

		int ringFlags = 0;

		if (vm["console"].as<bool>())
			ringFlags |= DRing::DRING_FLAG_CONSOLE_LOG;

		if (vm["debug"].as<bool>())
			ringFlags |= DRing::DRING_FLAG_DEBUG;

		if (vm["auto-answer"].as<bool>())
			ringFlags |= DRing::DRING_FLAG_AUTOANSWER;


		DRing::init(static_cast<DRing::InitFlag>(ringFlags));

		registerCallHandlers(std::map<std::string, std::shared_ptr<DRing::CallbackWrapperBase>>());
		registerConfHandlers(std::map<std::string, std::shared_ptr<DRing::CallbackWrapperBase>>());
		registerPresHandlers(std::map<std::string, std::shared_ptr<DRing::CallbackWrapperBase>>());
		registerVideoHandlers(std::map<std::string, std::shared_ptr<DRing::CallbackWrapperBase>>());

		if (!DRing::start())
			throw "DRing Error Cannot purturb at this time.";
		

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
		
		server.addRoute("/id", [](){
			return "this is supposed to be a ringID";
		});

		std::thread daemonEvents([](){
			while (true) {
				DRing::pollEvents();
				sleep(1);
			}
		});

        // Run the server
        server.run();
		

		DRing::fini();
    }
    catch(std::exception& e)
    {
        std::cerr << "Unhandled Exception reached the top of main: " << e.what() << ", the server will now exit" << std::endl;
        return -1;
    }

    return 0;
}
