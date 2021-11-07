#include "Playable_character.h"
#include "inputManager.h"
#include "tools.h"

Playable_character::Playable_character(SDL_Point position, std::string image_path, SDL_Surface* window) :
	Moving_object(position, image_path, window)
{
}

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
