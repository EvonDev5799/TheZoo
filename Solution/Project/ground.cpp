#include "ground.h"
#include "definition.h"


ground::ground(SDL_Surface* window_surface_ptr)
    : window_surface_ptr_(window_surface_ptr), zoo_(std::vector<animal*>()) {}

ground::~ground() {
    for (auto animal_ : this->zoo_) {
        animal_->~animal();
    }
}

void ground::add_animal(animal* animal_) { this->zoo_.push_back(animal_); }

void ground::update() {
    SDL_FillRect(this->window_surface_ptr_, NULL, SDL_MapRGB(this->window_surface_ptr_->format, 0, 127, 0));
    for (animal* animal_ : this->zoo_) {
        animal_->move();
        animal_->draw();
    }

}

void ground::setScreen_ptr(SDL_Surface* window_surface_ptr) {
    this->window_surface_ptr_ = window_surface_ptr;
}
