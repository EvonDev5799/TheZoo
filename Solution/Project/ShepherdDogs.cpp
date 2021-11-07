#include "ShepherdDogs.h"
#include "definitions.h"
#include "tools.h"

ShepherdDogs::ShepherdDogs(SDL_Point position, SDL_Surface* window) :
	Animal(position, "./media/shepherdDog_.png", window), closestRange(frame_height + frame_width)
{
	addTag("dog");
	addTag("protector");
	int speed = 6;
	velocity_.x = (std::rand() % speed) - (speed / 2);
	velocity_.y = (std::rand() % speed) - (speed / 2);
}

void ShepherdDogs::move() {
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
}

Animal* ShepherdDogs::interact(Interacting_object* obj) {
	if (obj->hasTag("shepherd")) {
		auto player = dynamic_cast<Moving_object*>(obj);
		closestRange = sqareRange(position_, player->getPosition());
		if (closestRange <= 30 && closestRange >=20) {
			SDL_Point dir = diff(player->getPosition(), position_);
			auto temps = dirAndLenght(dir, 7);
			velocity_.x = temps.y;
			velocity_.y = -temps.x;
		}
		else if (closestRange > 30) {
			SDL_Point dir = diff(player->getPosition(), position_);
			velocity_ = dirAndLenght(dir, 6);
		}
	}
	return(nullptr);
}