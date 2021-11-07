#pragma once
#include "rendered_object.h"
class Moving_object :
    public Rendered_object
{
    Moving_object(SDL_Point position, SDL_Surface* image);

    void step();
    virtual void move() = 0;

private:
    SDL_Point velocity_;
};

