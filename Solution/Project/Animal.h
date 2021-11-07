#pragma once
#include "moving_object.h"
class Animal :
    public Moving_object
{
public:
    Animal(SDL_Point position, const std::string& image_path, SDL_Surface* window);
};

