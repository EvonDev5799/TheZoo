#pragma once
#include "Wolf.h"
#include "Sheep.h"
#include "tools.h"

Wolf::Wolf(SDL_Point position, SDL_Surface* window) :
	Animal(position, "./media/wolf.png", window), hungerCount_(frame_rate * 15), closestRange(frame_height + frame_width)
{
	addTag("wolf");
	addTag("predator");
	auto speed = 6;
	velocity_.x = (std::rand() % speed) - (speed / 2);
	velocity_.y = (std::rand() % speed) - (speed / 2);

}

void Wolf::move()
{
	
	if (position_.x <= frame_boundary) {
		velocity_.x = abs(velocity_.x);
	}
	if (position_.y <= frame_boundary) {
		velocity_.y = abs(velocity_.y);
	}
	if (position_.x >= frame_width - frame_boundary) {
		velocity_.x = -abs(velocity_.x);
	}
	if (position_.y >= frame_height - frame_boundary) {
		velocity_.y = -abs(velocity_.y);
	}

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
				SDL_Point dir = diff(animal_pos, position_);
				velocity_ = dirAndLenght(dir, 7);
			}
			if (obj->hasTag("dog")) //chien du berger 
			{
				SDL_Point dir = diff(animal_pos, position_);
				velocity_ = dirAndLenght(dir, -7);
			}
			
		}
		
	}

	if (hungerCount_ <= 0) {
		removeTag("alive");
		SDL_FillRect(image_, NULL, SDL_MapRGB(image_->format, 255, 0, 0));
	}
	return nullptr;
}

