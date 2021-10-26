#pragma once

#include "animal.h"

class wolf : public animal {

public:
	wolf(SDL_Surface* sheep_surf);
	~wolf();

	//méthode
	void move() override;
};
