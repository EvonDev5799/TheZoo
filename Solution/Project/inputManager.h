#pragma once
#include <SDL.h>

namespace zoo {

	constexpr unsigned keys = 5;

	constexpr SDL_KeyCode upKey = SDLK_z;
	constexpr SDL_KeyCode downKey = SDLK_s;
	constexpr SDL_KeyCode leftKey = SDLK_q;
	constexpr SDL_KeyCode rightKey = SDLK_d;

	enum keycodes {
		up,
		right,
		left,
		down,
		click
	};

	class InputManager
	{
	public:	
		static void update();
		static bool end();

		static bool up();
		static bool right();
		static bool left();
		static bool down();
		static bool click();

		static int x();
		static int y();

	private:
		InputManager() = delete;

		static SDL_Point mousePos;
		static bool currentState[keys];
		static bool quit;
	};
}

