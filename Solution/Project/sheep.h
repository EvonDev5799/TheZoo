#pragma once

#include "animal.h"

class sheep : public animal {
private:
	int aSex;
	int aCanHaveChieldren;
	int aTimeMin;
public:
	sheep(SDL_Surface* sheep_surf);
	~sheep();

	//accesseur
	int getSex() { return this->aSex; }
	int getCHC() { return this->aCanHaveChieldren; }
	int getTimeMin() { return this->aTimeMin; }

	//modificateur
	void setHavaCheildren(int pInt) { this->aCanHaveChieldren = pInt; }

	//méthode
	void move() override;
	void sheepUpdate();
};