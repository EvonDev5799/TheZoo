#include "Ground.h"

Ground::Ground(SDL_Surface* window_surface_ptr) :
	window_surface_ptr_(window_surface_ptr), zoo_({})
{}

Ground::~Ground()
{
	for (auto a : zoo_)
		delete(a);
}

void Ground::update()
{
	std::vector<Moving_object*> toAdd;
	for (auto first : zoo_)
	{
		first->move();

		if (first->hasTag("alive"))
		{
			for (auto second : zoo_)
			{
				if (first != second)
				{
					auto newAnimal = first->interact(second);
					if (newAnimal != nullptr)
						toAdd.push_back(newAnimal);
				}
			}
			first->step();
		}
		first->draw();
	}

	for (auto a : toAdd)
	{
		add(a);
		a->draw();
	}
}

void Ground::add(Moving_object* pAnimal)
{
	zoo_.push_back(pAnimal);
}

int Ground::gerScore() {
	int score = 0;
	for (auto a : zoo_) {
		if (a->hasTag("prey") && a->hasTag("alive") ){
			score++;
		}
	}
	return score;
}

