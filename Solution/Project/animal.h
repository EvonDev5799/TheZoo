#pragma once

#include <iostream>
#include <SDL_image.h>

class animal {
private:
    SDL_Surface* window_surface_ptr_; // ptr to the surface on which we want the animal to be drawn, also non-owning
    SDL_Surface* image_ptr_; // The texture of the sheep (the loaded image), use load_surface_for

protected:
    double v_x_, v_y_, pos_x_, pos_y_;

public:
    animal(const std::string& file_path, SDL_Surface* window_surface_ptr); 
    ~animal(); 

    //méthode
    void draw(); 
    virtual void move() = 0; 

    //accesseur
    SDL_Surface* getwindow();
    SDL_Surface* getimage();
};