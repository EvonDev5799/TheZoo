#pragma once

#include "animal.h"

class wolf : public animal {

public:
	wolf(SDL_Surface* sheep_surf);
	~wolf();

	//m�thode
	void move() override;
};
