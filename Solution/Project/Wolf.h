#pragma once
#include "Animal.h"
#include "definitions.h"
class Wolf :
    public Animal
{
public:
    Wolf(SDL_Point position, SDL_Surface* window);
    void move() override;
    void interact(Interacting_object* obj) override;

private:
    int hungerCount_;
    int closestRange_;
};

