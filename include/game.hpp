#pragma once
#include <text.hpp>
#include <player.hpp>
#define WINDOW_TITLE "Hello World!"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

struct Game {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *background;
    struct Text *text;
    struct Player *player;
    Mix_Chunk *c_sound;
    Mix_Chunk *sdl_sound;
    Mix_Music *music;
    SDL_Event event;
    bool is_running;
};
void game_toggle_music();
bool game_init_sdl(struct Game *g);

bool game_new(struct Game *g);

bool game_run(struct Game *g);

void game_render_sdl(struct Game *g);

void game_events(struct Game *g);
void game_update(struct Game *g);
void game_free(struct Game *g);

void game_draw(struct Game *g);

bool game_load_media(struct Game *g);
void game_render_color(struct Game *g);
