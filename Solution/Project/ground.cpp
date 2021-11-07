#include "ground.h"
#include <vector>

ground::ground(SDL_Surface* window_surface_ptr)
    : window_surface_ptr_(window_surface_ptr), aZoo(std::vector<Animal*>{}) {}

ground::~ground() {
    for (auto vAnimal : this->aZoo) {
        vAnimal->~Animal();
    }
}

//modificateur
void ground::setScreen_ptr(SDL_Surface* window_surface_ptr) {
    this->window_surface_ptr_ = window_surface_ptr;
}

void ground::add_animal(Animal* pAnimal) {
    this->aZoo.push_back(pAnimal);
}

//méthode 
void ground::update() {

    SDL_FillRect(this->window_surface_ptr_, NULL, SDL_MapRGB(this->window_surface_ptr_->format, 0, 127, 0));
    auto babys_sheep = std::vector<Sheep*>();
    for (auto vAnimal1 : this->aZoo) {

        vAnimal1->move();
        for (auto vAnimal2 : this->aZoo) {
            babys_sheep.push_back(offspring((vAnimal1)));
            if (vAnimal1 != vAnimal2) {
                vAnimal1->interact(vAnimal2);
            }
        }
        vAnimal1->draw();
        
    }

    for (auto vSheep : babys_sheep) {
        if (vSheep != nullptr) {
            
            this->add_animal(vSheep); //on ne modifie pas l'attribu pendant qu'on le parcours 
            vSheep->draw();
        }
    }

}

Sheep* ground::offspring(Animal* pAnimal) {
    if (pAnimal->hasTag("sheep") && pAnimal->hasTag("femelle")) {
        Sheep* vSheep = dynamic_cast<Sheep*>(pAnimal);
        Sheep* vCheild;
        for (auto vAnimal : this->aZoo) {
            vCheild = vSheep->reproduction(vAnimal);
            if (vCheild != nullptr) return vCheild;
        }
    }
    return nullptr;
}


