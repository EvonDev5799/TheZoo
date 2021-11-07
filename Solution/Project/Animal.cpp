#pragma once
#include "Animal.h"

Animal::Animal(SDL_Point position, const std::string& image_path, SDL_Surface* window)
	: Moving_object(position, image_path, window)
{
	addTag("alive");
}
Animal::~Animal() {
	SDL_FreeSurface(image_);
}