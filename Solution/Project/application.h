<<<<<<< HEAD
﻿#pragma once

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
	ground ground_;
	uint32_t tempsPrecedent, tempsActuel;
   
public:
	application(unsigned n_sheep, unsigned n_wolf,unsigned n_shepherdDog); 
	~application();                                 

	int loop(unsigned period); 
	static void init();
=======
﻿#pragma once

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
	ground ground_;
	uint32_t tempsPrecedent, tempsActuel;
   
public:
	application(unsigned n_sheep, unsigned n_wolf,unsigned n_shepherdDog); 
	~application();                                 

	int loop(unsigned period); 
	static void init();
>>>>>>> 196898030368d2f1c50421f17de1cb8e91b26d6c
};