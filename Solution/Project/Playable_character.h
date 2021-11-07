#pragma once
#include "moving_object.h"
class Playable_character :
    public Moving_object
{
public:
    Playable_character(SDL_Point position, std::string image_path, SDL_Surface* window);
    void move() override;
};

