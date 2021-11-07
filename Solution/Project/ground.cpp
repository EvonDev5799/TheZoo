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
	for (auto main : zoo_) {
		main->move();

	for(auto first : zoo_)
		for (auto second : zoo_)
		{
			if (first != second)
			{
				auto newAnimal = first->interact(second);
				if (newAnimal != nullptr)
					add_animal(newAnimal);
			}
		}
}

void Ground::add_animal(Animal* pAnimal)
{
	zoo_.push_back(pAnimal);
}



