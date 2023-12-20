//
// Created by mfati on 12/20/2023.
//

#include <algorithm>
#include "../../include/engine/GameRenderer.h"
#include "../../include/Constants.h"
SDL_Renderer* GameRenderer::m_main_renderer;
SDL_Window* GameRenderer::m_window;
GameRenderer::GameRenderer() {
    try{
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            throw SDL_GetError();
        }
        m_window = SDL_CreateWindow("GAME",
                                           SDL_WINDOWPOS_CENTERED,
                                           SDL_WINDOWPOS_CENTERED,
                                           WINDOW_WIDTH, WINDOW_HEIGHT, 0);
        Uint32 render_flags = SDL_RENDERER_ACCELERATED;
        m_main_renderer = SDL_CreateRenderer(m_window, -1, render_flags);
    }
    catch (char* ex){
        printf("error initializing SDL: %s\n", ex);
    }
}

void GameRenderer::make_render_loop() {
    SDL_RenderClear(m_main_renderer);
    for(Renderer* renderer: m_renderers){
        renderer->update();
    }
    SDL_RenderPresent(m_main_renderer);
    SDL_Delay(1000/WINDOW_FPS);
}

void GameRenderer::add_renderer(Renderer *renderer) {
    m_renderers.push_back(renderer);
}

void GameRenderer::remove_renderer(Renderer *renderer) {
    auto it = find(m_renderers.begin(), m_renderers.end(),
                   renderer);
    if (it != m_renderers.end()) {
        m_renderers.erase(it);
        renderer->end();
        delete renderer;
    }
}

SDL_Renderer *GameRenderer::get_main_renderer() {
    return m_main_renderer;
}

SDL_Window *GameRenderer::get_window() {
    return m_window;
}

void GameRenderer::clear_all() {
    for(Renderer* renderer: m_renderers){
        renderer->end();
        delete renderer;
    }
    SDL_DestroyRenderer(m_main_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

