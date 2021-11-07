#pragma once
#include "Playable_character.h"
class Shepherd :
    public Playable_character
{
public:
    Shepherd(SDL_Point position, SDL_Surface* window);
    Moving_object* interact(Interacting_object* obj) override;

};

