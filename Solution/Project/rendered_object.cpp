#include "rendered_object.h"
#include <cmath>

SDL_Surface* load_surface_for(const std::string& path, SDL_Surface* window_surface_ptr);

Rendered_object::Rendered_object(SDL_Point position, const std::string& image_path, SDL_Surface* window) :
	position_(position), image_(load_surface_for(image_path, window)), window_(window), scale_(1)
{

}

Rendered_object::~Rendered_object()
{
	SDL_FreeSurface(image_);
}

SDL_Point Rendered_object::getPosition()
{
	return(position_);
}

SDL_Surface Rendered_object::getSurface()
{
	return(*image_);
}

void Rendered_object::draw()
{
	SDL_Rect area;
	area.w = floor(image_->w * scale_);
	area.h = floor(image_->h * scale_);
	area.x = position_.x - area.w /2;
	area.y = position_.y - area.h/2;
	SDL_BlitScaled(image_, NULL, window_, &area);
}
