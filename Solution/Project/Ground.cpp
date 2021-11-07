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
	for (auto a : zoo_)
	{
		a->move();
	}

	for(auto main : zoo_)
		for (auto secondary : zoo_)
		{
			if (main != secondary)
			{
				auto newAnimal = main->interact(secondary);
				if (newAnimal != nullptr)
					add_animal(newAnimal);
			}
		}

	for (auto a : zoo_)
	{
		a->step();
	}
}

void Ground::add_animal(Animal* pAnimal)
{
	zoo_.push_back(pAnimal);
}



