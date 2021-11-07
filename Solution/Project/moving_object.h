#pragma once
#include "rendered_object.h"
class Moving_object :
    public Rendered_object
{
public:
    Moving_object(SDL_Point position, const std::string& image_path, SDL_Surface* window);
    // apply the current velocity to the current position
    void step();

    // modify the velocity, require override from child classes
    virtual void move() = 0;

protected:
    //SDL_Point = 2dimensional vector
    SDL_Point velocity_;
};

