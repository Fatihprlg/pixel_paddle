//
// Created by mfati on 12/20/2023.
//

#ifndef PIXELPADDLE_INPUTMANAGER_H
#define PIXELPADDLE_INPUTMANAGER_H
#include "SDL.h"

typedef void (*quit_handler_t)();
typedef void (*keydown_handler_t)(SDL_Keycode);
typedef void (*keyup_handler_t)(SDL_Keycode);

class InputManager {
private:
    struct {
        quit_handler_t    quit;
        keydown_handler_t keydown;
        keyup_handler_t   keyup;
    } m_event_handlers;
public:
    InputManager();

    void handle_Input() const;
    void set_quit_handler(quit_handler_t handler);
    void set_key_up_handler(keyup_handler_t handler);
    void set_key_down_handler(keydown_handler_t handler);
};


#endif //PIXELPADDLE_INPUTMANAGER_H
