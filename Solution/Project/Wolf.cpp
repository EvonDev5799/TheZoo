#pragma once
#include "Wolf.h"
#include "Sheep.h"
#include "tools.cpp"

Wolf::Wolf(SDL_Point position, SDL_Surface* window) :
	Animal(position, "./media/wolf.png", window), hungerCount_(frame_rate * 15), closestRange(frame_height + frame_width)
{}

void Wolf::move()
{
	closestRange = frame_height + frame_width;
}

Animal* Wolf::interact(Interacting_object* obj)
{
	if (obj->hasTag("alive") ){
		if (obj->hasTag("prey") ) //sheep or other
		{
			Rendered_object* prey = dynamic_cast<Rendered_object*>(obj);
			
			velocity_ = focusdirection(velocity_,prey->getPosition());
			
		}
		if (obj->hasTag("Dog")) //chien du berger 
		{
			Rendered_object* prey = dynamic_cast<Rendered_object*>(obj);

			velocity_ = diff({ 0,0 },focusdirection(velocity_, prey->getPosition())); // par à l'opposé
		}
	}
	return nullptr;
}

