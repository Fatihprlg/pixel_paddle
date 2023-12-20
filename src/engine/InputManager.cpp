//
// Created by mfati on 12/20/2023.
//

#include <iostream>
#include "../../include/engine/InputManager.h"
#include "SDL_events.h"


void InputManager::handle_Input() const {
    SDL_Event e;
    bool quit = false;
    while (!quit && SDL_PollEvent(&e)) {
        switch(e.type) {
            case SDL_QUIT:
                m_event_handlers.quit();
                quit = true;
                break;
            case SDL_KEYDOWN:
                m_event_handlers.keydown(e.key.keysym.sym);
                break;
            case SDL_KEYUP:
                m_event_handlers.keyup(e.key.keysym.sym);
                break;
        }
    }
}

InputManager::InputManager() {

    m_event_handlers.quit = []() { std::cout << "Default quit handler called." << std::endl; };
    m_event_handlers.keydown = [](SDL_Keycode key) { std::cout << "Default keydown handler called with key: " << key << std::endl; };
    m_event_handlers.keyup = [](SDL_Keycode key) { std::cout << "Default keyup handler called with key: " << key << std::endl; };
}

void InputManager::set_quit_handler(quit_handler_t handler) {
    m_event_handlers.quit = handler;
}

void InputManager::set_key_up_handler(keyup_handler_t handler) {
    m_event_handlers.keyup = handler;
}

void InputManager::set_key_down_handler(keydown_handler_t handler) {
    m_event_handlers.keydown = handler;
}
