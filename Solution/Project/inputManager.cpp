#include "inputManager.h"
#include <iostream>

SDL_Point zoo::InputManager::mousePos = { 0,0 };
bool zoo::InputManager::currentState[keys] = {0};
bool zoo::InputManager::quit = false;

void zoo::InputManager::update()
{

	//Event handler
	SDL_Event e;

	while (SDL_PollEvent(&e) != 0)
	{
		//User requests quit
		if (e.type == SDL_QUIT)
			quit = true;
		else if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{
			case(leftKey):
				currentState[zoo::left] = true;
				break;
			case(rightKey):
				currentState[zoo::right] = true;
				break;
			case(upKey):
				currentState[zoo::up] = true;
				break;
			case(downKey):
				currentState[zoo::down] = true;
				break;
			default:
				break;
			}
		}
		else if (e.type == SDL_KEYUP)
		{
			switch (e.key.keysym.sym)
			{
			case(leftKey):
				currentState[zoo::left] = false;
				break;
			case(rightKey):
				currentState[zoo::right] = false;
				break;
			case(upKey):
				currentState[zoo::up] = false;
				break;
			case(downKey):
				currentState[zoo::down] = false;
				break;
			default:
				break;
			}
		}
		else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
		{
			currentState[zoo::click] = true;
		}
		else if (e.type == SDL_MOUSEMOTION)
		{
			mousePos = { e.motion.x, e.motion.y };
		}
	}
}

bool zoo::InputManager::end()
{
	return (quit);
}

bool zoo::InputManager::up()
{
	return currentState[zoo::up];
}

bool zoo::InputManager::right()
{
	return currentState[zoo::right];
}

bool zoo::InputManager::left()
{
	return currentState[zoo::left];
}

bool zoo::InputManager::down()
{
	return currentState[zoo::down];
}

bool zoo::InputManager::click()
{
	return currentState[zoo::click];
}

int zoo::InputManager::x()
{
	return mousePos.x;
}

int zoo::InputManager::y()
{
	return mousePos.y;
}