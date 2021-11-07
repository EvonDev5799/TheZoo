#include "Sheep.h"
#include "definitions.h"
#include "tools.h"
#include "Wolf.h"
#include <random>
#include <cmath>

Sheep::Sheep(SDL_Point position, SDL_Surface* window) :
	Animal(position, "./media/sheep.png", window), maturityCounter_(frame_rate*5), restCounter_(0)
{
	scale_ = 0.5;
	addTag("sheep");
	addTag("prey");

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



	int speed = 11;
	velocity_.x = (std::rand()%speed) - (speed/2);
	velocity_.y = (std::rand()%speed) - (speed/2);
}

Animal* Sheep::interact(Interacting_object* obj)
{
	Animal* r = nullptr;
	if (obj->hasTag("predator"))
	{
		Rendered_object* predator = dynamic_cast<Rendered_object*>(obj);
		SDL_Point predatorPos = predator->getPosition();

		if (inRange(position_, predatorPos, 30))
		{
			//TODO: meilleure formule?
			velocity_ = diff(position_, predatorPos);
		}

	}
	else if (hasTag("female") && hasTag("grown") && hasTag("rested"))
	{
		if (obj->hasTag("sheep") && obj->hasTag("male") && obj->hasTag("grown") && obj->hasTag("alive"));
		{
			Rendered_object* partner = dynamic_cast<Rendered_object*>(obj);

			if (inRange(position_, partner->getPosition(), 15))
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
	Rendered_object* r;
	r = new Sheep(position_, window_);
	removeTag("rested");
	restCounter_ = frame_rate * 5;
	return(r);
}

