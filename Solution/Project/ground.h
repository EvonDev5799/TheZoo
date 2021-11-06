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
	sheep* offspring(std::pair<animal*, const char*> pPair);
	void wolfprofimity(std::pair<animal*, const char*> pPair);

	//modificateur
	
	void add_animal(sheep* ani) { 
		this->aZoo.emplace(ani, "sheep");
	}
	void add_animal(wolf* ani) { 
		this->aZoo.emplace(ani, "wolf");
	}
	void add_animal(animal* ani) {
		this->aZoo.emplace(ani, "animal");
	}

	void setScreen_ptr(SDL_Surface* window_surface_ptr);
};