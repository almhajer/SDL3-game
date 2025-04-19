#pragma once
#include <precompiled.hpp>
#define TEXT_SIZE 100
#define WHITE_COLOR (SDL_Color){255, 255, 255, 255}
#define BLUE_COLOR (SDL_Color){137, 180, 250, 255}
#define TEXT_STR "حسن"
#define TEXT_VEL 3
struct Text {
    SDL_Renderer* renderer;
    SDL_Texture *image;
    SDL_FRect rect;
    float x_vel;
    float y_vel;
};

bool text_new( struct Text **text, SDL_Renderer *renderer);
void text_free( struct Text **text);
void text_update(struct Text *t,Mix_Chunk *sdl_chunk);
void text_draw(const struct Text *t);