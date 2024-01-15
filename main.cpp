#include <iostream>
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "include/engine/GameManager.h"
#include "include/Constants.h"
#include "include/engine/Collider.h"
#include "include/engine/MoveProvider.h"

int main(int argc, char* argv[]) {
    // Setup Game Env
    auto* gm = new GameManager();
    gm->setup_game();
    auto* game_renderer = gm->get_game_renderer();
    // Adding Game Objects
    // Player1
    auto* player1_renderer = new Renderer(PLAYER_IMG_PATH, game_renderer->get_main_renderer());
    auto* player1_collider = new Collider();
    auto* player1_move_provider = new MoveProvider(15);
    auto* player1 = new GameObject(0, Vector2(0,PLAYER_HEIGHT + 20), Vector2(PLAYER_WIDTH, PLAYER_HEIGHT));
    player1->add_component(player1_renderer);
    player1->add_component(player1_collider);
    player1->add_component(player1_move_provider);
    gm->add_game_object(player1);
    game_renderer->add_renderer(player1_renderer);
    // Player2
    auto* player2_renderer = new Renderer(PLAYER_IMG_PATH,  game_renderer->get_main_renderer());
    auto* player2_collider = new Collider();
    auto* player2_move_provider = new MoveProvider(15);
    player2_move_provider->set_action_keys(SDL_SCANCODE_W, SDL_SCANCODE_S, SDL_SCANCODE_A, SDL_SCANCODE_D);
    auto* player2 = new GameObject(1, Vector2(0,WINDOW_WIDTH - PLAYER_WIDTH -20), Vector2(PLAYER_WIDTH, PLAYER_HEIGHT));
    player2->add_component(player2_renderer);
    player2->add_component(player2_collider);
    player2->add_component(player2_move_provider);
    gm->add_game_object(player2);
    game_renderer->add_renderer(player2_renderer);
    // ball
    auto* ball_renderer = new Renderer(BALL_IMG_PATH,  game_renderer->get_main_renderer());
    auto* ball_collider = new Collider();
    auto* ball = new GameObject(2, Vector2(WINDOW_WIDTH/2,WINDOW_HEIGHT/2), Vector2(BALL_WIDTH, BALL_HEIGHT));
    ball->add_component(ball_renderer);
    ball->add_component(ball_collider);
    gm->add_game_object(ball);
    game_renderer->add_renderer(ball_renderer);
    
    //Game Loop
    gm->game_loop();

    //Shutdown
    gm->shutdown();
    return 0;
}


