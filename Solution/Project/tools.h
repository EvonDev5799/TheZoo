#pragma once
#include <SDL.h>
#include <cmath>

SDL_Point sum(SDL_Point a, SDL_Point b);
SDL_Point diff(SDL_Point end, SDL_Point start);
bool inRange(SDL_Point a, SDL_Point b, int range);
int sqareRange(SDL_Point a, SDL_Point b);