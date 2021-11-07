#include "moving_object.h"
#include "definitions.h"

Moving_object::Moving_object(SDL_Point position, const std::string& image_path, SDL_Surface* window) :
	Rendered_object(position, image_path, window), velocity_({ 0,0 })
{
}

void Moving_object::step()
{
	position_.x += velocity_.x;
	position_.y += velocity_.y;

    if (position_.x <= frame_boundary) {
        position_.x = frame_boundary;
    }
    if (position_.y <= frame_boundary) {
        position_.y = frame_boundary;
    }
    if (position_.x >= frame_width - frame_boundary) {
        position_.x = 0;
    }
    if (position_.y >= frame_height - frame_boundary) {
        position_.y = 0;
    }
}
