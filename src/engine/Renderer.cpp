//
// Created by mfati on 12/20/2023.
//

#include <utility>
#include "SDL_image.h"
#include "../../include/engine/Renderer.h"

Renderer::Renderer(const char *image, Vector2 size, SDL_Renderer* main_renderer): m_size(size), m_img_path(image), m_main_renderer(main_renderer) {
    m_position = new SDL_Rect();
    m_position->x = 0;
    m_position->y = 0;
    m_position->w = size.x;
    m_position->h = size.y;
    m_surface = IMG_Load(image);
    m_texture = SDL_CreateTextureFromSurface(main_renderer, m_surface);
    SDL_FreeSurface(m_surface);
    SDL_QueryTexture(m_texture, nullptr, nullptr, &m_position->w, &m_position->h);
}

void Renderer::set_size(Vector2 size) {
    m_size = size;
    m_position->w = size.x;
    m_position->h = size.y;
}

void Renderer::set_position(Vector2 pos) {
    m_position->x = pos.x;
    m_position->y = pos.y;
}

void Renderer::set_texture(const char *image) {
    m_img_path = image;
    m_surface = IMG_Load(image);
    m_texture = SDL_CreateTextureFromSurface(m_main_renderer, m_surface);
    SDL_FreeSurface(m_surface);
    SDL_QueryTexture(m_texture, nullptr, nullptr, &m_position->w, &m_position->h);
}

void Renderer::update() {
    SDL_RenderCopy(m_main_renderer, m_texture, nullptr, m_position);
}

void Renderer::end() {
    SDL_DestroyTexture(m_texture);
}

void Renderer::set_main_renderer(SDL_Renderer *main_renderer) {
    m_main_renderer = main_renderer;
}

