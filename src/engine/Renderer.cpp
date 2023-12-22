//
// Created by mfati on 12/20/2023.
//

#include <utility>
#include "SDL_image.h"
#include "../../include/engine/Renderer.h"

Renderer::Renderer(const char *image, SDL_Renderer* main_renderer): m_img_path(image), m_main_renderer(main_renderer) {
    m_rect = new SDL_Rect();
    m_transform = new Transform;
    m_rect->x = 0;
    m_rect->y = 0;
    m_rect->w = 1;
    m_rect->h = 1;
    m_surface = IMG_Load(image);
    m_texture = SDL_CreateTextureFromSurface(main_renderer, m_surface);
    SDL_FreeSurface(m_surface);
    SDL_QueryTexture(m_texture, nullptr, nullptr, &m_rect->w, &m_rect->h);
}

void Renderer::set_texture(const char *image) {
    m_img_path = image;
    m_surface = IMG_Load(image);
    m_texture = SDL_CreateTextureFromSurface(m_main_renderer, m_surface);
    SDL_FreeSurface(m_surface);
    SDL_QueryTexture(m_texture, nullptr, nullptr, &m_rect->w, &m_rect->h);
}

void Renderer::render() {
    m_transform = m_parent->get_transform();
    m_rect->w = m_transform->get_size().x;
    m_rect->h = m_transform->get_size().y;
    m_rect->x = m_transform->get_position().x;
    m_rect->y = m_transform->get_position().y;
    SDL_RenderCopy(m_main_renderer, m_texture, nullptr, m_rect);
}

void Renderer::end() {
    SDL_DestroyTexture(m_texture);
}

void Renderer::set_main_renderer(SDL_Renderer *main_renderer) {
    m_main_renderer = main_renderer;
}




