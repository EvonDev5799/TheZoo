#pragma once
#include "Wolf.h"
#include "Sheep.h"
#include "tools.h"

Wolf::Wolf(SDL_Point position, SDL_Surface* window) :
	Animal(position, "./media/wolf.png", window), hungerCount_(frame_rate * 15), closestRange(frame_height + frame_width)
{
	addTag("wolf");
	addTag("predateur");

}

void Wolf::move()
{
	closestRange = frame_height + frame_width;
	hungerCount_--;
}

Animal* Wolf::interact(Interacting_object* obj)
{	
	

	if (obj->hasTag("alive") ){
		Rendered_object* animal_ = dynamic_cast<Rendered_object*>(obj);
		auto animal_pos = animal_->getPosition();

		if (closestRange > sqareRange(position_, animal_pos)) {
			closestRange = sqareRange(position_, animal_pos);
			if (obj->hasTag("prey")) //sheep or other
			{
				velocity_ = focusdirection(velocity_, animal_pos);
			}
			if (obj->hasTag("dog")) //chien du berger 
			{
				velocity_ = diff({ 0,0 }, focusdirection(velocity_, animal_pos)); // par à l'opposé
			}
			
		}
		
	}

	if (hungerCount_ <= 0) {
		removeTag("alive");

	}
	return nullptr;
}

