#pragma once
#include "interacting_object.h"
#include <SDL.h>

class Rendered_object :
	public Interacting_object
{
public:
	//Contructor
	Rendered_object(SDL_Point position, const std::string& image_path, SDL_Surface* window);

	//Destructor
	~Rendered_object();

	//Accessors
	SDL_Point getPosition();
	SDL_Surface getSurface();

	//méthode
	void draw();
	
protected:
	// used to have smaller images if needed
	float scale_;

	SDL_Surface* image_;
	SDL_Surface* window_;

	//SDL_Point = 2dimensional vector
	SDL_Point position_;
};

