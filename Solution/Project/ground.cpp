#include "ground.h"
#include <vector>

ground::ground(SDL_Surface* window_surface_ptr)
    : window_surface_ptr_(window_surface_ptr), aZoo(std::map<animal*, const char*>{}) {}

ground::~ground() {
    for (auto pair_ : this->aZoo) {
        pair_.first->~animal();
        delete(pair_.second);
    }
}

//modificateur
void ground::setScreen_ptr(SDL_Surface* window_surface_ptr) {
    this->window_surface_ptr_ = window_surface_ptr;
}


//méthode 
void ground::update() {

    SDL_FillRect(this->window_surface_ptr_, NULL, SDL_MapRGB(this->window_surface_ptr_->format, 0, 127, 0));
    auto babys_sheep = std::vector<sheep*>();
    for (auto pair_ : this->aZoo) {
        
        pair_.first->move();
        babys_sheep.push_back(offspring(pair_)); //creer des enfants si possible et le stocke
        pair_.first->draw();
        
    }

    for (auto vSheep : babys_sheep) {
        if (vSheep != nullptr) {
            
            this->add_animal(vSheep); //on ne modifie pas l'attribu pendant qu'on le parcours 
            vSheep->draw();
            std::cout << "draw" << std::endl;
        }
    }

}

sheep* ground::offspring(std::pair<animal*, const char*> pPair) {
    if (pPair.second != "sheep") { return nullptr; }
    for (auto pair_ : this->aZoo) {
        if (pair_.second == "sheep" && pair_.first != pPair.first) {
            sheep* vSheep1 = (sheep*)pair_.first;
            sheep* vSheep2 = (sheep*)pPair.first;
            if (vSheep1->getSex() != vSheep2->getSex()) {
                bool bol_relative_x = abs(pPair.first->getPosX() - pair_.first->getPosX()) <= pair_.first->getimage()->w * 0.7;
                bool bol_relative_y = abs(pPair.first->getPosY() - pair_.first->getPosY()) <= pair_.first->getimage()->h * 0.7;
                if (bol_relative_x && bol_relative_y) {
                    std::cout << "proche" << std::endl;
                    if (vSheep1->getSex() == 0 && vSheep1->getCHC() >= vSheep1->getTimeMin()) {
                        std::cout << "sheep::offspring::enfants_start" << std::endl;
                        vSheep1->setHavaCheildren(0);
                        sheep* vCheild = new sheep(this->window_surface_ptr_);
                        vCheild->setPosX(vSheep1->getPosX() + 10);
                        vCheild->setPosY(vSheep1->getPosY() + 10);
                        return vCheild;
                    }
                    else if (vSheep2->getSex() == 0 && vSheep2->getCHC() >= vSheep2->getTimeMin()) {
                        std::cout << "sheep::offspring::enfants_start" << std::endl;
                        vSheep2->setHavaCheildren(0);
                        sheep* vCheild = new sheep(this->window_surface_ptr_);
                        vCheild->setPosX(vSheep2->getPosX() + 10);
                        vCheild->setPosY(vSheep2->getPosY() + 10);
                        return vCheild;
                    }
                }

            }

        }
    }
    return nullptr;
}
/*
void ground::wolfprofimity(std::pair<animal*, const char*> pPair){
    if (pPair.second != "wolf") { return; }
    if 
}

*/
   

