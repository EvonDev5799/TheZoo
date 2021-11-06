#include <SDL.h>
#include <iostream>
#include <string>

namespace zoo {
	constexpr SDL_KeyCode upKey = SDLK_z;
	constexpr SDL_KeyCode downKey = SDLK_s;
	constexpr SDL_KeyCode leftKey = SDLK_q;
	constexpr SDL_KeyCode rightKey = SDLK_d;

	enum dir
	{
		up,
		right,
		left,
		down,
		click
	};

	bool inputDown[4] = { 0,0,0,0 };

	SDL_Point dir = { 0,0 };
	SDL_Point mouse = { 0,0 };

	bool manageEvent()
	{
		//Event handler
		SDL_Event e;
		bool r = false;

		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
				r = true;
			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case(leftKey):
					inputDown[left] = 1;
					break;
				case(rightKey):
					inputDown[right] = 1;
					break;
				case(upKey):
					inputDown[up] = 1;
					break;
				case(downKey):
					inputDown[down] = 1;
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
					inputDown[left] = 0;
					break;
				case(rightKey):
					inputDown[right] = 0;
					break;
				case(upKey):
					inputDown[up] = 0;
					break;
				case(downKey):
					inputDown[down] = 0;
					break;
				default:
					break;
				}
			}
			else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
			{	
				std::cout << "click(" << mouse.x << "," << mouse.y << ")" << std::endl;
			}
			else if (e.type == SDL_MOUSEMOTION)
			{
				mouse = { e.motion.x, e.motion.y };
			}
		}
		return(r);
	}
}
int main(int argc, char* args[])
{
	SDL_Window* mainWindow = nullptr;
	SDL_Surface* mainSurface = nullptr;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "failed to init SDL, error: " << SDL_GetError() << std::endl;
		return(1);
	}
	else
	{
		mainWindow = SDL_CreateWindow("Title", 100, 100, 500, 300, SDL_WINDOW_SHOWN);
		if (mainWindow == nullptr)
		{
			std::cout << "couldn't create window, error: " << SDL_GetError() << std::endl;
			return(1);
		}
		else
		{
			mainSurface = SDL_GetWindowSurface(mainWindow);
		}
	}

	bool quit = false;


	//While application is running
	while (!quit)
	{
		SDL_Delay(100);
		quit = zoo::manageEvent();
		SDL_UpdateWindowSurface(mainWindow);
		std::cout << " up: " << zoo::inputDown[zoo::up] << " down: " << zoo::inputDown[zoo::down] << " right: " << zoo::inputDown[zoo::right] << " leeft: " << zoo::inputDown[zoo::left] << std::endl;
	}

	SDL_FreeSurface(mainSurface);
	SDL_DestroyWindow(mainWindow);

	return 0;
}