#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

// Helper function to initialize SDL
void init();


 SDL_Surface* load_surface_for(const std::string& path, SDL_Surface* window_surface_ptr);

