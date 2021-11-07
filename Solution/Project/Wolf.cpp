#include "Wolf.h"
#include "Sheep.h"

Wolf::Wolf(SDL_Point position, SDL_Surface* window) :
	Animal(position, "./media/wolf.png", window), hungerCount_(frame_rate * 15), closestRange_Sheep(frame_height + frame_width)
{}

void Wolf::move()
{
	closestRangeSheep_ = frame_height + frame_width;
}

void Wolf::interact(Interacting_object* obj)
{
	if (obj->hasTag("alive") ){
		if (obj->hasTag("prey") ) //sheep or other
		{
			Rendered_object* prey = dynamic_cast<Rendered_object*>(obj);
			SDL_Point preyPos = prey->getPosition();
			velocity_.x = 
		}
		if (obj->hasTag("Dog")) //chien du berger 
		{

		}
	}
}

