#pragma once
#include "definitions.h"
#include "Animal.h"
#include "Sheep.h"
#include"Wolf.h"
#include <map>
#include <string>

class ground {
private:
	// Attention, NON-OWNING ptr, again to the screen
	SDL_Surface* window_surface_ptr_;

	std::map<Animal*,const char*> aZoo;

public:
	ground(SDL_Surface* window_surface_ptr);
	~ground();  

	//méthode 
	void update(); 
	Sheep* offspring(std::pair<Animal*, const char*> pPair);
	//modificateur
	
	void add_animal(Sheep* ani) { 
		this->aZoo.emplace(ani, "sheep");
	}
	void add_animal(Wolf* ani) { 
		this->aZoo.emplace(ani, "wolf");
	}
	void add_animal(Animal* ani) {
		this->aZoo.emplace(ani, "animal");
	}

	void setScreen_ptr(SDL_Surface* window_surface_ptr);
};