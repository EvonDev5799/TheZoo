#include "moving_object.h"

Moving_object::Moving_object(SDL_Point position, SDL_Surface* image) : Rendered_object(position, image), velocity_({ 0,0 })
{
}

void Moving_object::step()
{
	posisiton_.x += velocity_.x;
	posisiton_.y += velocity_.y;
}
