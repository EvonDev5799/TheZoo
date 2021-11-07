#include "Playable_character.h"
#include "inputManager.h"
#include "tools.h"

void Playable_character::move()
{
	SDL_Point dir = { 0, 0 };
	if (zoo::InputManager::up())
		dir.y--;
	if (zoo::InputManager::left())
		dir.x--;
	if (zoo::InputManager::right())
		dir.x++;
	if (zoo::InputManager::down())
		dir.y++;

	unsigned playerSpeed = 5;
	velocity_ = dirAndLenght(dir, playerSpeed);
}
