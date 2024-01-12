//
// Created by mfati on 12/20/2023.
//

#ifndef PIXELPADDLE_RENDERER_H
#define PIXELPADDLE_RENDERER_H


#include <string>
#include "Vector2.h"
#include "SDL_render.h"
#include "Component.h"
#include "Transform.h"

class Renderer : public Component{
private:
    SDL_Renderer* m_main_renderer;
    SDL_Rect* m_rect;
    std::string m_img_path;
    SDL_Texture* m_texture;
    SDL_Surface* m_surface;
public:
    Renderer(const char *image, SDL_Renderer* main_renderer);
    void set_texture(const char *image);
    void set_main_renderer(SDL_Renderer* main_renderer);
    void render();
    void end() override;
};


#endif //PIXELPADDLE_RENDERER_H
