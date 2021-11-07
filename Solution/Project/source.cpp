#pragma once

#include "application.h"
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <string>



void init() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0)
        throw std::runtime_error("init():" + std::string(SDL_GetError()));

    // Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
        throw std::runtime_error("init(): SDL_image could not initialize! "
            "SDL_image Error: " +
            std::string(IMG_GetError()));


    std::cout << "Done with initilization" << std::endl;
} 


int main(int argc, char* argv[]) {

    std::cout << "Starting up the application" << std::endl;

    init();

    std::cout << "Done with initilization" << std::endl;
    application my_app(std::stoul(argv[1]), std::stoul(argv[2]), std::stoul(argv[3]));

    std::cout << "Created window" << std::endl;

    int retval = my_app.loop(std::stoul(argv[4]));

    std::cout << "Exiting application with code " << retval << std::endl;

    my_app.~application();

    return retval;
}