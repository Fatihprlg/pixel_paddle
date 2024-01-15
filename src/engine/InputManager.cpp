//
// Created by mfati on 12/20/2023.
//

#include <iostream>
#include <utility>
#include "../../include/engine/InputManager.h"
#include "SDL_events.h"
#include <algorithm>


void InputManager::handle_Input() const {
    SDL_Event e;
    bool quit = false;
    bool key_holding = false;
    while (!quit && SDL_PollEvent(&e)) {
        switch(e.type) {
            case SDL_QUIT:
                for (const auto& quit_handler: m_event_handlers.quit) {
                    quit_handler();
                }
                quit = true;
                key_holding = false;
                break;
            case SDL_KEYDOWN:
                for (const auto& keydown_handler: m_event_handlers.keydown) {
                    keydown_handler(e.key.keysym.scancode);
                }
                key_holding = true;
                break;
            case SDL_KEYUP:
                for (const auto& keyup_handler: m_event_handlers.keyup) {
                    keyup_handler(e.key.keysym.scancode);
                }
                key_holding = false;
                break;
        }
        if(key_holding){
            for (const auto& keyhold_handler: m_event_handlers.keyhold) {
                keyhold_handler(e.key.keysym.scancode);
            }
        }
    }
}

InputManager::InputManager() = default;

void InputManager::add_quit_handler(const quit_handler_t& handler) {
    m_event_handlers.quit.push_back(handler);
}

void InputManager::add_key_up_handler(const keyup_handler_t& handler) {
    m_event_handlers.keyup.push_back(handler);
}

void InputManager::add_key_down_handler(const keydown_handler_t& handler) {
    m_event_handlers.keydown.push_back(handler);
}

void InputManager::add_key_hold_handler(const keyhold_handler_t& handler) {
    m_event_handlers.keyhold.push_back(handler);
}

void InputManager::remove_quit_handler(const quit_handler_t& handler) {
    /*auto it = find(m_event_handlers.quit.begin(), m_event_handlers.quit.end(),
                   handler);
    if (it != m_event_handlers.quit.end()) {
        m_event_handlers.quit.erase(it);
    }*/
}
void InputManager::remove_key_up_handler(const keyup_handler_t& handler) {
    /*auto it = find(m_event_handlers.keyup.begin(), m_event_handlers.keyup.end(),
                   handler);
    if (it != m_event_handlers.keyup.end()) {
        m_event_handlers.keyup.erase(it);
    }*/
}
void InputManager::remove_key_down_handler(const keydown_handler_t& handler) {
    /*auto it = find(m_event_handlers.keydown.begin(), m_event_handlers.keydown.end(),
                   handler);
    if (it != m_event_handlers.keydown.end()) {
        m_event_handlers.keydown.erase(it);
    }*/
}
void InputManager::remove_key_hold_handler(const keyhold_handler_t& handler) {
    /*auto it = find(m_event_handlers.keyhold.begin(), m_event_handlers.keyhold.end(),
                   handler);
    if (it != m_event_handlers.keyhold.end()) {
        m_event_handlers.keyhold.erase(it);
    }*/
}

