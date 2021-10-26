#include "wolf.h"
#include "definition.h"



wolf::wolf(SDL_Surface* wolf_surf)
    : animal(std::string("./media/wolf.png"), wolf_surf) {
    this->v_x_ = std::rand() % 50 - 25; // vitesse entre -10 et 10
    this->v_y_ = std::rand() % 50 - 25;
}

wolf::~wolf() {}

void wolf::move() {

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
}