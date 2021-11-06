#pragma once
#include "definition.h"
#include "animal.h"
#include "sheep.h"
#include"wolf.h"
#include <map>
#include <string>

class ground {
private:
	// Attention, NON-OWNING ptr, again to the screen
	SDL_Surface* window_surface_ptr_;

	std::map<animal*,const char*> aZoo;

public:
	ground(SDL_Surface* window_surface_ptr);
	~ground();  

	//méthode 
	void update(); 

	//modificateur
	void add_animal(animal* ani);
	void setScreen_ptr(SDL_Surface* window_surface_ptr);
};