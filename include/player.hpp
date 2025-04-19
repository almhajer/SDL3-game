#pragma once
#include <precompiled.hpp>

struct Player {
    SDL_Renderer *renderer;
    SDL_Texture *image;
    SDL_FRect rect;
    const bool *keystate;
};

bool player_new(struct Player **player, SDL_Renderer *renderer);

void player_free( struct Player **player);

void player_update(struct Player *p);

void player_draw(struct Player *p);
