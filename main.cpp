#include <iostream>
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "include/engine/GameManager.h"

int main(int argc, char* argv[]) {
    auto* gm = new GameManager();
    gm->setup_game();
    gm->game_loop();
    gm->shutdown();
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Quit();
    return 0;
}

