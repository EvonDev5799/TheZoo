#pragma once
#include "definitions.h"
#include "Animal.h"
#include "Sheep.h"
#include"Wolf.h"
#include <vector>
#include <string>

class Ground {

public:
	Ground(SDL_Surface* window_surface_ptr);
	~Ground();

	//m�thode 
	void update();
	//modificateur

	void add_animal(Animal* pAnimal);

private:
	// Attention, NON-OWNING ptr, again to the screen
	SDL_Surface* window_surface_ptr_;

	std::vector<Animal*> zoo_;
};
