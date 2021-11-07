#pragma once
#include "application.h"
#include "inputManager.h"





application::application(int n_sheep, int n_wolf,int n_shepherd)
    : timeTarget_(0), ground_(nullptr) {

    init();

    //window
    window_ptr_ = SDL_CreateWindow("Zoo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, frame_width, frame_height,0);
    if (!window_ptr_) {
        // si la window n'est pas créer correctement
        std::cout << ("Could not create window: %s", SDL_GetError()) << std::endl;
        SDL_Delay(10000);
    }
    window_surface_ptr_ = SDL_GetWindowSurface(window_ptr_);
    SDL_FillRect(window_surface_ptr_, NULL,SDL_MapRGB(window_surface_ptr_->format, 0, 127, 0));
    
    ground_ = new Ground(window_surface_ptr_);

    //animal
    std::srand((unsigned)time(nullptr));// initialise l'aléatoire des position x et y de l'animal;
    for (int i = 0; i < n_sheep; i++) {
        SDL_Point position_ = { std::rand() % (frame_width - frame_boundary) + frame_boundary,std::rand() % (frame_height - frame_boundary) + frame_boundary };
        Sheep* sheep_ = new Sheep(position_,window_surface_ptr_);        
        ground_->add_animal(sheep_);
    }
    
    for (int i = 0; i < n_wolf; i++) {
        SDL_Point position_ = { std::rand() % (frame_width - frame_boundary) + frame_boundary,std::rand() % (frame_height - frame_boundary) + frame_boundary };
        Wolf* wolf_ = new Wolf(position_,window_surface_ptr_);
        ground_->add_animal(wolf_);
    }
    /*
    for (int i = 0; i < n_shepherd; i++) {
        sherpherdDog* sherpherdDog_ = new sherpherdDog(window_surface_ptr_);
        ground_.add_animal(sherpherdDog_);
    }
    */
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
    Uint32 currentTime_ = SDL_GetTicks();
    while (currentTime_ < period) {
        if (currentTime_ >= timeTarget_) {
            timeTarget_ += (frame_time * 1000);
            zoo::InputManager::update();
            ground_->update();
            SDL_UpdateWindowSurface(window_ptr_);
        } 
        else 
        {
            SDL_Delay(timeTarget_ - currentTime_);
        }       
    }   
    return 0;
}


 void application::init() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0)
        throw std::runtime_error("init():" + std::string(SDL_GetError()));

    // Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
        throw std::runtime_error("init(): SDL_image could not initialize! "
            "SDL_image Error: " +
            std::string(IMG_GetError()));


    std::cout << "Done with initilization" << std::endl;
}