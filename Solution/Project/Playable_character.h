#pragma once
#include "moving_object.h"
class Playable_character :
    public Moving_object
{
public:
    void move() override;
};

