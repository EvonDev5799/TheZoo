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

	//méthode 
	void update();
	//modificateur

	void add(Moving_object* pAnimal);

private:
	// Attention, NON-OWNING ptr, again to the screen
	SDL_Surface* window_surface_ptr_;

	std::vector<Moving_object*> zoo_;
};

