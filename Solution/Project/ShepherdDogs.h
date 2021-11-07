#pragma once
#include "Animal.h"
class ShepherdDogs :
    public Animal
{  
public:
    ShepherdDogs(SDL_Point position, SDL_Surface* window);
    void move() override;
    Animal* interact(Interacting_object* obj) override;

private:
    int closestRange;
};

