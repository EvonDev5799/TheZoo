#pragma once
#include "interacting_object.h"
#include <SDL.h>

class Rendered_object :
	public Interacting_object
{
public:
	//Contructor
	Rendered_object(SDL_Point position, SDL_Surface* image);

	//Destructor
	~Rendered_object();

	//Accessors
	SDL_Point getPosition();
	SDL_Surface getSurface();

protected:
	SDL_Surface* image_;
	SDL_Point posisiton_;
};

