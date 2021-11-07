#pragma once
#include "Game.hpp"

namespace zoo {
	constexpr SDL_KeyCode upKey = SDLK_z;
	constexpr SDL_KeyCode downKey = SDLK_s;
	constexpr SDL_KeyCode leftKey = SDLK_q;
	constexpr SDL_KeyCode rightKey = SDLK_d;

	enum dir
	{
		up,
		right,
		left,
		down,
		click
	};

	bool inputDown[4] = { 0,0,0,0 };

	SDL_Point dir = { 0,0 };
	SDL_Point mouse = { 0,0 };

	bool manageEvent()
	{
		//Event handler
		SDL_Event e;
		bool r = false;

		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
				r = true;
			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case(leftKey):
					inputDown[left] = 1;
					break;
				case(rightKey):
					inputDown[right] = 1;
					break;
				case(upKey):
					inputDown[up] = 1;
					break;
				case(downKey):
					inputDown[down] = 1;
					break;
				default:
					break;
				}
			}
			else if (e.type == SDL_KEYUP)
			{
				switch (e.key.keysym.sym)
				{
				case(leftKey):
					inputDown[left] = 0;
					break;
				case(rightKey):
					inputDown[right] = 0;
					break;
				case(upKey):
					inputDown[up] = 0;
					break;
				case(downKey):
					inputDown[down] = 0;
					break;
				default:
					break;
				}
			}
			else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
			{
				std::cout << "click(" << mouse.x << "," << mouse.y << ")" << std::endl;
			}
			else if (e.type == SDL_MOUSEMOTION)
			{
				mouse = { e.motion.x, e.motion.y };
			}
		}
		return(r);
	}
}

Game::Game() 
    : quit(false),screenHeight(frame_height), screenWidth(frame_width), framePerSecond(frame_rate), tempsPrecedent(0),tempsActuel(0),mainWindow(nullptr), mainSurface(nullptr), ground_(ground(NULL))
{
    init();
    

    mainWindow = SDL_CreateWindow("Zoo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenHeight, screenWidth, 0);
    if (!mainWindow) {
        // si la window n'est pas créer correctement
        std::cout << ("Could not create window: %s", SDL_GetError()) << std::endl;
    }
    mainSurface = SDL_GetWindowSurface(mainWindow);
    SDL_FillRect(mainSurface, NULL, SDL_MapRGB(mainSurface->format, 0, 127, 0));

    this->ground_.setScreen_ptr(mainSurface);

    //animal
    std::srand((unsigned)time(nullptr));// initialise l'aléatoire des position x et y de l'animal;
    for (int i = 0; i < nb_sheep; i++) {
        SDL_Point position_ = {std::rand() % (screenWidth - frame_boundary) + frame_boundary, std::rand() % (screenHeight - 2 * frame_boundary) + frame_boundary };
        Sheep* sheep_ = new Sheep(position_,mainSurface);
        sheep_->draw();

        this->ground_.add_animal(sheep_);
    }

    for (int i = 0; i < nb_wolf; i++) {
        SDL_Point position_ = { std::rand() % (screenWidth - 2 * frame_boundary) + frame_boundary, std::rand() % (screenHeight - 2 * frame_boundary) + frame_boundary };
        Wolf* Wolf_ = new Wolf(position_, mainSurface);
        Wolf_->draw();
        this->ground_.add_animal(Wolf_);
    }

     //todo window_event_

    SDL_UpdateWindowSurface(mainWindow);
}


bool Game::init() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0) {
        throw std::runtime_error("init():" + std::string(SDL_GetError()));
        return false;
    }


    // Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        throw std::runtime_error("init(): SDL_image could not initialize! SDL_image Error: " + std::string(IMG_GetError()));
        return false;
    }
    return true;
}

Game::~Game() {
	SDL_FreeSurface(mainSurface);
	SDL_DestroyWindow(mainWindow);
	ground_.~ground();
	
}

bool Game::loop() {

    //While application is running
	double frametime = 1 / framePerSecond;
    while (!quit)
    {
        std::cout << " up: " << zoo::inputDown[zoo::up] << " down: " << zoo::inputDown[zoo::down] << " right: " << zoo::inputDown[zoo::right] << " leeft: " << zoo::inputDown[zoo::left] << std::endl;
    
    
		this->tempsActuel = SDL_GetTicks();
        if (this->tempsActuel - this->tempsPrecedent >= frametime) {
            this->ground_.update();
            SDL_UpdateWindowSurface(mainWindow);
            
        }
        else
        {
            SDL_Delay(frametime - (this->tempsActuel - this->tempsPrecedent));
        }

        this->tempsPrecedent = this->tempsActuel;

        quit = zoo::manageEvent();
    }



    return 0;
}