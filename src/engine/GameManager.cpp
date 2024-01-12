//
// Created by mfati on 12/20/2023.
//

#include "../../include/engine/GameManager.h"
#include "../../include/Constants.h"
#include <algorithm>
void GameManager::setup_game() {
    m_game_renderer = new GameRenderer();
    m_input_manager = new InputManager();
    m_input_manager->set_quit_handler(reinterpret_cast<quit_handler_t>(quit_handler()));
    m_is_quitting = false;
}

void GameManager::update_frame() {
    m_input_manager->handle_Input();
    for(GameObject* go: m_game_objects){
        go->update();
    }
    m_game_renderer->make_render_loop();
}

void GameManager::shutdown() {
    for(GameObject* go: m_game_objects){
        go->end();
        delete go;
    }
    m_game_renderer->clear_all();
    delete m_game_renderer;
    delete m_input_manager;
}

void GameManager::add_game_object(GameObject* go) {
    auto it = find(m_game_objects.begin(), m_game_objects.end(),
                   go);
    if (it != m_game_objects.end()) {
        printf("Game Object already exists.");
    }
    else m_game_objects.push_back(go);
}

void GameManager::remove_game_object(GameObject *go) {
    auto it = find(m_game_objects.begin(), m_game_objects.end(),
                   go);
    if (it != m_game_objects.end()) {
        m_game_objects.erase(it);
        go->end();
        delete go;
    }
}

GameRenderer *GameManager::get_game_renderer() {
    return m_game_renderer;
}

void GameManager::game_loop() {
    while(!m_is_quitting){
        update_frame();
        SDL_Delay(1000/WINDOW_FPS);
    }
}

InputManager *GameManager::get_input_manager() {
    return m_input_manager;
}

void * GameManager::quit_handler() {
    m_is_quitting = true;
    return nullptr;
}
