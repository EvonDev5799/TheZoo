#pragma once
#include "animal.h"
#include <vector>


class ground {
private:
	// Attention, NON-OWNING ptr, again to the screen
	SDL_Surface* window_surface_ptr_;

	std::vector<animal*> zoo_;

public:
	ground(SDL_Surface* window_surface_ptr);
	~ground();  

	//méthode 
	void update(); 

	//modificateur
	void add_animal(animal* ani);
	void setScreen_ptr(SDL_Surface* window_surface_ptr);
};