//
// Created by mfati on 1/2/2024.
//

#ifndef PIXELPADDLE_MOVEPROVIDER_H
#define PIXELPADDLE_MOVEPROVIDER_H


#include "SDL_keycode.h"
#include "Component.h"
#include "InputManager.h"

class MoveProvider: public Component {
private:
    int m_speed;
    SDL_Scancode m_up;
    SDL_Scancode m_down;
    SDL_Scancode m_left;
    SDL_Scancode m_right;
    Transform* m_game_object_transform;
    void* handle_move_input(SDL_Scancode key);
    InputManager* m_input_manager;
public:
    MoveProvider();
    MoveProvider(int speed);
    MoveProvider(int speed, SDL_Scancode up, SDL_Scancode down, SDL_Scancode left, SDL_Scancode right);
    void set_speed(int speed);
    void set_action_keys(SDL_Scancode up = SDL_SCANCODE_UP, SDL_Scancode down= SDL_SCANCODE_DOWN, SDL_Scancode left= SDL_SCANCODE_LEFT, SDL_Scancode right = SDL_SCANCODE_RIGHT);
};


#endif //PIXELPADDLE_MOVEPROVIDER_H
