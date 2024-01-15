//
// Created by mfati on 1/2/2024.
//

#include <functional>
#include "MoveProvider.h"
#include "../Constants.h"
#include "GameManager.h"

MoveProvider::MoveProvider() {
    m_speed = 5;
    m_up = SDL_SCANCODE_UP;
    m_down = SDL_SCANCODE_DOWN;
    m_left = SDL_SCANCODE_LEFT;
    m_right = SDL_SCANCODE_RIGHT;
    m_input_manager = GameManager::get_input_manager();
    auto wrapper = std::bind(&MoveProvider::handle_move_input, this,std::placeholders::_1);
    m_input_manager->add_key_hold_handler(wrapper);
}

MoveProvider::MoveProvider(int speed) {
    m_speed = speed;
    m_up = SDL_SCANCODE_UP;
    m_down = SDL_SCANCODE_DOWN;
    m_left = SDL_SCANCODE_LEFT;
    m_right = SDL_SCANCODE_RIGHT;
    m_input_manager = GameManager::get_input_manager();
    auto wrapper = std::bind(&MoveProvider::handle_move_input, this,std::placeholders::_1);
    m_input_manager->add_key_hold_handler(wrapper);
}

MoveProvider::MoveProvider(int speed, SDL_Scancode up, SDL_Scancode down, SDL_Scancode left, SDL_Scancode right) {
    m_speed = speed;
    m_up = up;
    m_down = down;
    m_left = left;
    m_right = right;
    m_input_manager = GameManager::get_input_manager();
    MoveProvider mp = *this;
    auto wrapper = std::bind(&MoveProvider::handle_move_input, mp,std::placeholders::_1);
    m_input_manager->add_key_hold_handler(wrapper);
}

void *MoveProvider::handle_move_input(SDL_Scancode key) {
    m_game_object_transform = this->m_parent->get_transform();
    Vector2 new_pos =  m_game_object_transform->get_position();
    if(key == m_up){
        new_pos -= Vector2(0, m_speed);
    }
    else if (key == m_down){
        new_pos += Vector2(0, m_speed);
    }
    else if(key == m_left){
        new_pos -= Vector2(m_speed, 0);
    }
    else if(key == m_right){
        new_pos += Vector2(m_speed, 0);
    }
    m_game_object_transform->set_position(new_pos);
    return nullptr;
}

void MoveProvider::set_speed(int speed) {
    m_speed = speed;
}

void MoveProvider::set_action_keys(SDL_Scancode up, SDL_Scancode down, SDL_Scancode left, SDL_Scancode right) {
    m_up = up;
    m_down = down;
    m_left = left;
    m_right = right;
}



