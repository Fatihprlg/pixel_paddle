//
// Created by mfati on 12/20/2023.
//

#ifndef PIXELPADDLE_GAMERENDERER_H
#define PIXELPADDLE_GAMERENDERER_H

#include "SDL.h"
#include "Renderer.h"
#include <string>
#include <vector>

class GameRenderer {
private:
    SDL_Renderer* m_main_renderer;
    SDL_Window* m_window;
    std::vector<Renderer*> m_renderers;
public:
    GameRenderer();
    void make_render_loop();
    void add_renderer(Renderer* renderer);
    void remove_renderer(Renderer* renderer);
    void clear_all();
    SDL_Renderer* get_main_renderer();
    SDL_Window* get_window();
};


#endif //PIXELPADDLE_GAMERENDERER_H
