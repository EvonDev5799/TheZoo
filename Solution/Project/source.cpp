#include <SDL.h>
#include <iostream>
#include <string>
#include "Game.hpp"


int main(int argc)
{
	
	Game* Game_ = new Game();

	//While application is running
	
	Game_->loop();
	Game_->~Game();

	return 0;
}