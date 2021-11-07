#include "Shepherd.h"
#include "tools.h"

Shepherd::Shepherd(SDL_Point position, SDL_Surface* window) :
	Playable_character(position, "./media/link.png", window)
{
	addTag("alive");
	addTag("shepherd");
}

Moving_object* Shepherd::interact(Interacting_object* obj)
{
	if (obj->hasTag("alive") ) {
		Rendered_object* animal_ = dynamic_cast<Rendered_object*>(obj);
		auto animal_pos = animal_->getPosition();
		int range = sqareRange(position_, animal_pos);
		
		if (range <= 20 && obj->hasTag("predator")) {
			obj->removeTag("alive") ;
			obj->addTag("dead");
		}

	}
	return nullptr;
}

