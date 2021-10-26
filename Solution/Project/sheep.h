#pragma once

#include "animal.h"

class sheep : public animal {
	
public:
	sheep(SDL_Surface* sheep_surf);
	~sheep();

	//méthode
	void move() override;
};