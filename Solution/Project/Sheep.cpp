#include "Sheep.h"
#include "definitions.h"
#include "tools.h"
#include "Wolf.h"
#include <random>
#include <cmath>

Sheep::Sheep(SDL_Point position, SDL_Surface* window) :
	Animal(position, "./media/sheep.png", window), maturityCounter_(frame_rate*4), restCounter_(frame_rate * 4)
{
	scale_ = 0.5;
	addTag("sheep");
	addTag("prey");

	int speed = 4;
	velocity_.x = (std::rand() % speed) - (speed / 2);
	velocity_.y = (std::rand() % speed) - (speed / 2);

	//Coin Toss
	if (std::rand() % 2 == 0)
	{
		addTag("male");
	}
	else {
		addTag("female");
	}
}

void Sheep::move() {
	
	if (hasTag("alive"))
	{
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
		if (maturityCounter_ == 0)
		{
			grow();
		}
		if (restCounter_ == 0)
		{
			ready();
		}

		if (maturityCounter_ > 0) maturityCounter_--;
		if (restCounter_ > 0) restCounter_--;
	}
	else if (hasTag("dead"))
	{
		removeTag("dead");
		image_ = load_surface_for("./media/sheep_d.png", window_);
		auto color_key = SDL_MapRGB(image_->format, 0, 0, 0);
		SDL_SetColorKey(image_, SDL_TRUE, color_key);
	}
}

Animal* Sheep::interact(Interacting_object* obj)
{
	Animal* r = nullptr;
	if (obj->hasTag("predator")&&obj->hasTag("alive"))
	{
		Rendered_object* predator = dynamic_cast<Rendered_object*>(obj);
		SDL_Point predatorPos = predator->getPosition();

		if (inRange(position_, predatorPos, 100))
		{
			//TODO: meilleure formule?
			SDL_Point dir = diff(position_, predatorPos);
			velocity_ = dirAndLenght(dir, 3);
		}

	}
	else if (hasTag("female") && hasTag("grown") && hasTag("rested"))
	{
		if (obj->hasTag("sheep") && obj->hasTag("male") && obj->hasTag("grown") && obj->hasTag("alive"));
		{
			Rendered_object* partner = dynamic_cast<Rendered_object*>(obj);

			if (inRange(position_, partner->getPosition(), 50))
				r = mate();
		}
	}
	return(r);
}

void Sheep::grow()
{
	addTag("grown");
	scale_ = 1;
	maturityCounter_ = -1;
}

void Sheep::ready()
{
	addTag("rested");
	restCounter_ == -1;
}

Animal* Sheep::mate()
{
	//TODO: create new sheep
	Animal* r;
	r = new Sheep(position_, window_);
	removeTag("rested");
	restCounter_ = frame_rate * 5;
	return(r);
}

