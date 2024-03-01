#include <cstdlib>
#include <iostream>

#include "Logger.hpp"
#include "Server.hpp"
#include "ConfigParser.hpp"
#include "EventListener.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " [CONFIGURATION FILE]" << std::endl;
        return EXIT_FAILURE;
    }

    try
    {
        ConfigParser parser(argv[1]);
        ConfigSpecList specs = parser.getSpecs();
        EventListener listener;
        for (size_t idx = 0; idx < specs.size(); ++idx)
        {
            listener.subscribe(new Server(specs[idx]));
        }
        listener.start();
    }
    catch (const std::exception& e)
    {
        Logger::log(e.what());
    }
}
