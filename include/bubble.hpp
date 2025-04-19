#pragma once
#define PLAYER_VEL 5
#define BUBBLE_RADIUS 15

SDL_Surface *bubble_surface(SDL_Surface *src_surf, int radius, SDL_Color outer_color);
SDL_Surface *bubble_create_text(const char *str,float size,int radius ,SDL_Color inner_color,SDL_Color outer_color);
SDL_Surface *solid_color_surface(SDL_Surface*src_surf,SDL_Color color);
void blit_symmetric_points(SDL_Surface *src_surf, SDL_Surface *target_surf,
                           int radius, int x, int y);