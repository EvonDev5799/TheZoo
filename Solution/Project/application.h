#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "ground.h"
#include "Animal.h"
#include "sheep.h"
#include "wolf.h"
//#include "shepherdDog.h"
#include "definitions.h"



class application {

private:
	// The following are OWNING ptrs
	SDL_Window* window_ptr_;
	SDL_Surface* window_surface_ptr_;
	//SDL_Event window_event_;

	// Other attributes here, for example an instance of ground
	Ground* ground_;
	uint32_t timeTarget_;
   
public:
	application(int n_sheep, int n_wolf,int n_shepherdDog); 
	~application();                                 

	int loop(unsigned period); 
	static void init();
};