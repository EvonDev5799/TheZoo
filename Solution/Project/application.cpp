#pragma once
#include "application.h"
#include "inputManager.h"
#include "Shepherd.h"
#include "ShepherdDogs.h"





application::application(int n_sheep, int n_wolf,int n_shepherd)
    : timeTarget_(0), ground_(nullptr) {

    //window
    window_ptr_ = SDL_CreateWindow("Zoo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, frame_width, frame_height,0);
    if (!window_ptr_) {
        // si la window n'est pas créer correctement
        std::cout << ("Could not create window: %s", SDL_GetError()) << std::endl;
        SDL_Delay(10000);
    }
    window_surface_ptr_ = SDL_GetWindowSurface(window_ptr_);
    
    ground_ = new Ground(window_surface_ptr_);

    ground_->add(new Shepherd({200,200}, window_surface_ptr_));
    //animal
    std::srand((unsigned)time(nullptr));// initialise l'aléatoire des position x et y de l'animal;
    for (int i = 0; i < n_sheep; i++) {
        SDL_Point position_ = { std::rand() % (frame_width - 2*frame_boundary) + frame_boundary,std::rand() % (frame_height - 2*frame_boundary) + frame_boundary };
        Sheep* sheep_ = new Sheep(position_,window_surface_ptr_);        
        ground_->add(sheep_);
    }
    
    for (int i = 0; i < n_wolf; i++) {
        SDL_Point position_ = { std::rand() % (frame_width - 2*frame_boundary) + frame_boundary,std::rand() % (frame_height - 2*frame_boundary) + frame_boundary };
        Wolf* wolf_ = new Wolf(position_,window_surface_ptr_);
        ground_->add(wolf_);
    }
    for (int i = 0; i < n_shepherd; i++) {
        SDL_Point position_ = { std::rand() % (frame_width - 2 * frame_boundary) + frame_boundary,std::rand() % (frame_height - 2 * frame_boundary) + frame_boundary };
        ShepherdDogs* shepherdDog_ = new ShepherdDogs(position_,window_surface_ptr_);
        ground_->add(shepherdDog_);
    }
    //todo window_event_
    SDL_UpdateWindowSurface(window_ptr_);
    timeTarget_ = SDL_GetTicks();
    
}

application::~application() { 
    SDL_FreeSurface(window_surface_ptr_);
    SDL_DestroyWindow(window_ptr_);
    free(ground_);
    SDL_Quit();

    // window_envent ?
}

int application::loop(unsigned period) {
    while (SDL_GetTicks() < period) {
        if (SDL_GetTicks() >= timeTarget_) {
            timeTarget_ += (frame_time * 1000);
            SDL_FillRect(window_surface_ptr_, NULL, SDL_MapRGB(window_surface_ptr_->format, 0, 127, 0));

            zoo::InputManager::update();
            ground_->update();

            SDL_UpdateWindowSurface(window_ptr_);
        } 
        else 
        {
            SDL_Delay(timeTarget_ - SDL_GetTicks());
           
        }       
    } 
    std::cout << "Score : " << ground_->gerScore() << std::endl;
    

    return 0;
}

