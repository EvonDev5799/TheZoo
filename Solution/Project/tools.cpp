#include "tools.h"

SDL_Point sum(SDL_Point a, SDL_Point b)
{
	SDL_Point r;
	r.x = a.x + b.x;
	r.y = a.y + b.y;
	return(r);
}

SDL_Point mult(float scalare , SDL_Point b)
{
	SDL_Point r;
	r.x = scalare * b.x;
	r.y = scalare * b.y;
	return(r);
}
SDL_Point div(float scalare, SDL_Point b)
{
	SDL_Point r;
	r.x = scalare / b.x;
	r.y = scalare / b.y;
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

float norme(SDL_Point v) {
	float pytagore = v.x * v.x + v.y * v.y;
	float norme = std::sqrt(pytagore);
	return norme;
}

SDL_Point construcVector(SDL_Point referecne_point, SDL_Point other_point) {
	SDL_Point r;
	r.x =  other_point.x - referecne_point.x;
	r.y = other_point.y - referecne_point.y;
	return r;
	
}

SDL_Point focusdirection(SDL_Point reference, SDL_Point focus) {
	float norme_reference = norme(reference);
	SDL_Point new_velocity = construcVector(reference, focus);
	new_velocity = div(norme(new_velocity), new_velocity);
	return mult(norme_reference,new_velocity);
}

SDL_Point dirAndLenght(SDL_Point dir, int length)
{
	SDL_Point r;
	auto norme_ = norme(dir);
	r.x = (dir.x*length) / norme_;
	r.y = (dir.y*length) / norme_;
	return(r);
}