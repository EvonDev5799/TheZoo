#include "Wolf.h"

Wolf::Wolf(SDL_Point position, SDL_Surface* window) :
	Animal(position, "./media/wolf.png", window), hungerCount_(frame_rate * 15), closestRange_(frame_height + frame_width)
{}

void Wolf::move()
{
	closestRange_ = frame_height + frame_width;
}

void Wolf::interact(Interacting_object* obj)
{
	if (obj->hasTag("prey") && obj->hasTag("alive"))
	{
		
	}
}

