#pragma once

#include "animal.h"

class sherpherdDog : public animal {
public :
	sherpherdDog(SDL_Surface* sheep_surf);
	~sherpherdDog();

	//m�thode
	void move();

};