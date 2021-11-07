#pragma once
#include "definitions.h"
#include "Animal.h"
#include "Sheep.h"
#include"Wolf.h"
#include <vector>
#include <string>

class ground {
private:
	// Attention, NON-OWNING ptr, again to the screen
	SDL_Surface* window_surface_ptr_;

	std::vector<Animal*> aZoo;

public:
	ground(SDL_Surface* window_surface_ptr);
	~ground();  

	//méthode 
	void update(); 
	Sheep* offspring(Animal* pPair);
	//modificateur
	
	void add_animal(Animal* pAnimal);
	void setScreen_ptr(SDL_Surface* window_surface_ptr);
};