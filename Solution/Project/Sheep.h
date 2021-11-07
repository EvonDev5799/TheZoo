#pragma once
#include "Animal.h"
class Sheep :
    public Animal
{
public:
    Sheep(SDL_Point position, SDL_Surface* window);
    void move() override;
    Animal* interact(Interacting_object* obj) override;

private:
    void grow();
    void ready();
    Interacting_object* mate();

    int maturityCounter_;
    int restCounter_;
};

