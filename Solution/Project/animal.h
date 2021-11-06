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
    SDL_Surface* getwindow() { return window_surface_ptr_; }
    SDL_Surface* getimage() { return image_ptr_; }        
    double getPosX() { return pos_x_; }
    double getPosY() { return pos_y_; }
    double getSpeedX() { return v_x_; }
    double getSpeedY() { return v_y_; }

    //modificateur
    void setPosX(double pDouble) { pos_x_ = pDouble; }
    void setPosY(double pDouble) { pos_y_ = pDouble; }
    void setSpeedX(double pDouble) { v_x_ = pDouble; }
    void setSpeedY(double pDouble) { v_y_ = pDouble; }
};