#include "tools.h"

SDL_Point sum(SDL_Point a, SDL_Point b)
{
	SDL_Point r;
	r.x = a.x + b.x;
	r.y = a.y + b.y;
	return(r);
}

SDL_Point diff(SDL_Point end, SDL_Point start)
{
	SDL_Point r;
	r.x = end.x - start.x;
	r.y = end.y - start.y;
	return(r);
}

bool inRange(SDL_Point a, SDL_Point b, int range)
{
	return((sqareRange(a, b) < range));
}

int sqareRange(SDL_Point a, SDL_Point b)
{
	int xRange = abs(a.x - b.x);
	int yRange = abs(a.y - b.y);
	return(std::min(xRange, yRange));
}


SDL_Point UnitVecteur(SDL_Point) {
	float 

}