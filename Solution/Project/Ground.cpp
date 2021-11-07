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
	std::vector<Animal*> toAdd;
	for (auto first : zoo_)
	{
		if (first->hasTag("alive"))
		{
			first->move();
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
		add_animal(a);
	}
}

void Ground::add_animal(Animal* pAnimal)
{
	zoo_.push_back(pAnimal);
}



