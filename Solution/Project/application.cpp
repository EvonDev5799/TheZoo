#pragma once
#include "application.h"
#include "animal.h"
#include "sheep.h"
#include "wolf.h"
#include "definition.h"




application::application(unsigned n_sheep, unsigned n_wolf)
    : tempsActuel(0), tempsPrecedent(0), ground_(ground(NULL)) {

    //window
    this->window_ptr_ = SDL_CreateWindow("Zoo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, frame_width, frame_height,0);
    if (!this->window_ptr_) {
        // si la window n'est pas créer correctement
        std::cout << ("Could not create window: %s", SDL_GetError()) << std::endl;
        SDL_Delay(10000);
    }
    this->window_surface_ptr_ = SDL_GetWindowSurface(this->window_ptr_);
    SDL_FillRect(this->window_surface_ptr_, NULL,SDL_MapRGB(this->window_surface_ptr_->format, 0, 127, 0));
    
    this->ground_.setScreen_ptr(this->window_surface_ptr_);

    //animal
    std::srand((unsigned)time(nullptr));// initialise l'aléatoire des position x et y de l'animal;
    for (int i = 0; i < n_sheep; i++) {
        sheep* sheep_ = new sheep(this->window_surface_ptr_);
        sheep_->draw();
        
        this->ground_.add_animal(sheep_);
    }
    
    for (int i = 0; i < n_wolf; i++) {
        wolf* wolf_ = new wolf(this->window_surface_ptr_);
        wolf_->draw();
        this->ground_.add_animal(wolf_);
    }
    //todo window_event_

    
    SDL_UpdateWindowSurface(this->window_ptr_);
}

application::~application() { 
    SDL_FreeSurface(this->window_surface_ptr_);
    SDL_DestroyWindow(this->window_ptr_);
    this->ground_.~ground();
    SDL_Quit();

    // window_envent ?
}

int application::loop(unsigned period) {
    while (this->tempsActuel < period) {
        this->tempsActuel = SDL_GetTicks();
        if (this->tempsActuel - this->tempsPrecedent >= frame_time) {
            this->ground_.update();
            SDL_UpdateWindowSurface(this->window_ptr_);
        } 
        else 
        {
            SDL_Delay(frame_time - (this->tempsActuel - this->tempsPrecedent));
        }
        
        this->tempsPrecedent = this->tempsActuel;
       
    }

   
    return 0;
}


