#include "rendered_object.h"

Rendered_object::Rendered_object(SDL_Point position, SDL_Surface* image) : posisiton_(position), image_(image)
{
}

Rendered_object::~Rendered_object()
{
	SDL_FreeSurface(image_);
}

SDL_Point Rendered_object::getPosition()
{
	return(posisiton_);
}

SDL_Surface Rendered_object::getSurface()
{
	return(*image_);
}
