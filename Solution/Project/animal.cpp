#pragma once

#include "animal.h"
#include "definition.h"
#include "SDL_init.h"



animal::animal(const std::string& file_path, SDL_Surface* window_surface_ptr)
    : window_surface_ptr_(window_surface_ptr), v_x_(0), v_y_(0), pos_x_(0), pos_y_(0) {
    this->image_ptr_ = load_surface_for(file_path, window_surface_ptr);
    this->pos_x_ = std::rand() % (frame_width - 2 * frame_boundary - image_ptr_->w) + frame_boundary;
    this->pos_y_ = std::rand() % (frame_height - 2 * frame_boundary - image_ptr_->h) + frame_boundary;


    //gère le alpha de l'image
    auto color_key = SDL_MapRGB(this->image_ptr_->format, 0, 0, 0);
    SDL_SetColorKey(this->image_ptr_, SDL_TRUE, color_key);
};

animal::~animal() {
    SDL_FreeSurface(this->image_ptr_);
    delete (this);
};

void animal::draw() {
    SDL_Rect area;
    area.x = this->pos_x_;
    area.y = this->pos_y_;
    area.w = this->image_ptr_->w;
    area.h = this->image_ptr_->h;
    SDL_BlitScaled(this->image_ptr_, NULL, this->window_surface_ptr_, &area);
}

SDL_Surface* animal::getwindow() {
    return this->window_surface_ptr_;
}

SDL_Surface* animal::getimage() {
    return this->image_ptr_;
}