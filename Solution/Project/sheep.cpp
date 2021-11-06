#include "sheep.h"
#include "definition.h"


sheep::sheep(SDL_Surface* sheep_surf)
    : animal(std::string("./media/sheep.png"), sheep_surf), aCanHaveChieldren(0), aTimeMin(5000){

    //généreer un vitesse entre -13 et +13
    this->v_x_ = std::rand() % 26 - 13; 
    this->v_y_ = std::rand() % 26 - 13;

    //génération du sex
    this->aSex = std::rand()%2; //génère 0 ou 1
}

sheep::~sheep() {}

//méthode
void sheep::move() {
    this->pos_x_ += (frame_time * this->v_x_);
    this->pos_y_ += (frame_time * this->v_y_);
    int w_ = this->getwindow()->w - frame_boundary - this->getimage()->w;
    int h_ = this->getwindow()->h - frame_boundary - this->getimage()->h;

    if (this->pos_x_ <= frame_boundary) {
        this->pos_x_ = frame_boundary;
        this->v_x_ = std::abs(this->v_x_);
    }
    if (this->pos_y_ <= frame_boundary) {
        this->pos_y_ = frame_boundary;
        this->v_y_ = std::abs(this->v_y_);
    }
    if (this->pos_x_ >= w_) {
        this->pos_x_ = w_;
        this->v_x_ = -std::abs(this->v_x_);
    }
    if (pos_y_ >= h_) {
        this->pos_y_ = h_;
        this->v_y_ = -std::abs(this->v_y_);
    }
    sheepUpdate();
}

void sheep::sheepUpdate() {
    if (this->aSex == 0) {//si femelle
        if (this->aCanHaveChieldren < this->aTimeMin)
            this->aCanHaveChieldren++;

    }
}



