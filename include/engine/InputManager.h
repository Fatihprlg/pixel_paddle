//
// Created by mfati on 12/20/2023.
//

#ifndef PIXELPADDLE_INPUTMANAGER_H
#define PIXELPADDLE_INPUTMANAGER_H

#include <vector>
#include "SDL.h"
#include <functional>

typedef void (*quit_handler_t)();
typedef std::function<void(SDL_Scancode)> keydown_handler_t;
typedef std::function<void(SDL_Scancode)> keyup_handler_t;
typedef std::function<void(SDL_Scancode)> keyhold_handler_t;
class InputManager {
private:

    struct {
        std::vector<quit_handler_t>    quit;
        std::vector<keydown_handler_t> keydown;
        std::vector<keyup_handler_t>   keyup;
        std::vector<keyhold_handler_t>   keyhold;
    } m_event_handlers;
public:
    InputManager();

    void handle_Input() const;
    void add_quit_handler(const quit_handler_t& handler);
    void add_key_up_handler(const keyup_handler_t& handler);
    void add_key_down_handler(const keydown_handler_t& handler);
    void add_key_hold_handler(const keyhold_handler_t& handler);
    void remove_quit_handler(const quit_handler_t& handler);
    void remove_key_up_handler(const keyup_handler_t& handler);
    void remove_key_down_handler(const keydown_handler_t& handler);
    void remove_key_hold_handler(const keyhold_handler_t& handler);
};


#endif //PIXELPADDLE_INPUTMANAGER_H
