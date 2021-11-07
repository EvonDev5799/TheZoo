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
		auto player = dynamic_cast<Rendered_object*>(obj);
		closestRange = sqareRange(position_, player->getPosition());
		if (closestRange < 10) {
			//tourne en rond
			auto temps = focusdirection(velocity_, player->getPosition());
			velocity_.x = temps.y;
			velocity_.y = temps.x;
		}
		else {
			velocity_ = focusdirection(velocity_, player->getPosition()); //rejoind le joueur
		}
	}
	return(nullptr);
}