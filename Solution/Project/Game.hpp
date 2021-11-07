#pragma once
#include <SDL_image.h>
#include "Game.hpp"
#include "ground.h"
#include <string>
#include <iostream>
#include "definitions.h"

class Game
{
public:
	Game();
	~Game();
	bool init();
	bool loop();

private:
	unsigned framePerSecond;
	unsigned screenWidth;
	unsigned screenHeight;
	unsigned tempsPrecedent;
	unsigned tempsActuel;
	SDL_Window* mainWindow ;
	SDL_Surface* mainSurface ;
	ground ground_;
	bool quit;

};

