#include "Shepherd.h"

Shepherd::Shepherd(SDL_Point position, SDL_Surface* window) :
	Playable_character(position, "./media/link.png", window)
{
	addTag("alive");
}

Moving_object* Shepherd::interact(Interacting_object* obj)
{
	return nullptr;
}

