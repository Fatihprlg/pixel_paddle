//
// Created by mfati on 12/20/2023.
//

#ifndef PIXELPADDLE_RENDERER_H
#define PIXELPADDLE_RENDERER_H


#include <string>
#include "Vector2.h"
#include "SDL_render.h"
#include "Component.h"

class Renderer : public Component{
private:
    SDL_Renderer* m_main_renderer;
    SDL_Rect* m_position;
    std::string m_img_path;
    Vector2 m_size;
    SDL_Texture* m_texture;
    SDL_Surface* m_surface;
public:
    Renderer(const char *image, Vector2 size, SDL_Renderer* main_renderer);
    void set_size(Vector2 size);
    void set_position(Vector2 pos);
    void set_texture(const char *image);
    void set_main_renderer(SDL_Renderer* main_renderer);
    void update() override;
    void end() override;
};


#endif //PIXELPADDLE_RENDERER_H
