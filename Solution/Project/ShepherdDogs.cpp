#include "ShepherdDogs.h"
#include "definitions.h"
#include "tools.h"

ShepherdDogs::ShepherdDogs(SDL_Point position, SDL_Surface* window) :
	Animal(position, "./media/shepherdDog_.png", window), closestRange(frame_height + frame_width)
{
	addTag("dog");
}

void ShepherdDogs::move() {
	
}

Animal* ShepherdDogs::interact(Interacting_object* obj) {
	if (obj->hasTag("player")) {
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