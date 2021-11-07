#pragma once
#include "Animal.h"
class Sheep :
    public Animal
{
public:
    Sheep(SDL_Point position, SDL_Surface* window);
    void move() override;
    void interact(Interacting_object* obj) override;

private:
    void grow();
    void ready();
    void mate();

    int maturityCounter_;
    int restCounter_;
};

