#pragma once
#include <SDL.h>
#include <cmath>

SDL_Point sum(SDL_Point a, SDL_Point b);
SDL_Point diff(SDL_Point end, SDL_Point start);
bool inRange(SDL_Point a, SDL_Point b, int range);
int sqareRange(SDL_Point a, SDL_Point b);
float norme(SDL_Point v);
SDL_Point UnitVector(SDL_Point v);
SDL_Point construcVector(SDL_Point referecne_point, SDL_Point other_point);
SDL_Point focusdirection(SDL_Point reference, SDL_Point focus);
SDL_Point mult(float scalare, SDL_Point b);
SDL_Point div(float scalare, SDL_Point b);