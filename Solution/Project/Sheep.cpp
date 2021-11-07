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



	int speed = 12;
	velocity_.x = (std::rand()%speed) - (speed/2);
	velocity_.y = (std::rand()%speed) - (speed/2);
}

void Sheep::interact(Interacting_object* obj)
{
	if (obj->hasTag("wolf"))
	{
		Wolf* wolf = dynamic_cast<Wolf*>(obj);
		SDL_Point wolfPos = wolf->getPosition();

		if (inRange(position_, wolfPos, 30))
		{
			//TODO: meilleure formule?
			velocity_.x = position_.x - wolfPos.x;
			velocity_.y = position_.y - wolfPos.y;
		}

	}
	
}

Sheep* Sheep::reproduction(Animal* obj) {
	if ( hasTag("grown") && hasTag("rested")) //hasTag("female"), on c'est que ça vrai, vérifier dans le ground)
	{
		if (obj->hasTag("sheep") && obj->hasTag("male") && obj->hasTag("grown") && obj->hasTag("alive")){
			if (inRange(position_, obj->getPosition(), reproduction_Distance)) {
				mate();
				return new Sheep(sum(position_, { 10,10 }), window_);
			}
				
		}
	}
	return nullptr;
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

void Sheep::mate()
{
	//TODO: create new sheep
	removeTag("rested");
	restCounter_ = frame_rate * 5;
}


