#pragma once

#include "application.h"
#include <stdio.h>
#include <string>

int main(int argc, char* argv[]) {

    std::cout << "Starting up the application" << std::endl;

    if (argc != 5)
        throw std::runtime_error("Need three arguments - "
            "number of sheep, number of wolves,number of sheepherdDog "
            "simulation time\n");

    application::init();

    std::cout << "Done with initilization" << std::endl;

    application my_app(std::stoul(argv[1]), std::stoul(argv[2]), std::stoul(argv[3]));

    std::cout << "Created window" << std::endl;

    int retval = my_app.loop(std::stoul(argv[4]));

    std::cout << "Exiting application with code " << retval << std::endl;

    my_app.~application();

    return retval;
}