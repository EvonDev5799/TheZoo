#pragma once

#include "animal.h"

class sheep : public animal {
	
public:
	sheep(SDL_Surface* sheep_surf);
	~sheep();

	//m�thode
	void move() override;
};