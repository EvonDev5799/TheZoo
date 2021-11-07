#pragma once
#include "Wolf.h"
#include "Sheep.h"
#include "tools.h"


Wolf::Wolf(SDL_Point position, SDL_Surface* window) :
	Animal(position, "./media/wolf.png", window), hungerCount_(frame_rate * 7), closestRange(frame_height + frame_width)
{
	addTag("wolf");
	addTag("predator");
	auto speed = 5;
	velocity_.x = (std::rand() % speed) - (speed / 2);
	velocity_.y = (std::rand() % speed) - (speed / 2);

}

void Wolf::move()
{
	if (hasTag("alive"))
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

		if (hungerCount_ <= 0) {
			removeTag("alive");
			addTag("dead");
		}
	}
	if (hasTag("dead"))
	{
		removeTag("dead");
		image_ = load_surface_for("./media/wolf_d.png", window_ );
		auto color_key = SDL_MapRGB(image_->format, 0, 0, 0);
		SDL_SetColorKey(image_, SDL_TRUE, color_key);
		
	}
}

Animal* Wolf::interact(Interacting_object* obj)
{	
	

	if (obj->hasTag("alive") ){
		Rendered_object* animal_ = dynamic_cast<Rendered_object*>(obj);
		auto animal_pos = animal_->getPosition();
		int range = sqareRange(position_, animal_pos);

		if (obj->hasTag("prey"))
		{
			if (range < 40)
			{
				obj->removeTag("alive");
				obj->addTag("dead");
				hungerCount_ += frame_rate*2;
			}
			else if (range < closestRange)
			{
				closestRange = range;
				SDL_Point dir = diff(animal_pos, position_);
				velocity_ = dirAndLenght(dir, 3);
			}
			
		}
		else if (obj->hasTag("protector") && range < 120)
		{
			closestRange = range;
			SDL_Point dir = diff(animal_pos, position_);
			velocity_ = dirAndLenght(dir, -5);
		}

	}
	return nullptr;
}

