#pragma once

#include "SDL_init.h"
#include <SDL.h>
#include <SDL_image.h>
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <numeric>
#include <random>
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
}

SDL_Surface* load_surface_for(const std::string& path, SDL_Surface* window_surface_ptr) {

    if (!window_surface_ptr) {
        std::cout << "window not valid." << std::endl;
        return (nullptr);
    }
    SDL_Surface* surf = SDL_ConvertSurface(IMG_Load(path.c_str()), window_surface_ptr->format, 0);
    if (!surf) {
        std::cout << "Error during creation of surface." << std::endl;
        return (nullptr);
    }

    return (surf);

}
