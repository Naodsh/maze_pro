#ifndef MAZE_H
#define MAZE_H

#include <SDL2/SDL.h>
#include <stdbool.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define MAP_WIDTH 10
#define MAP_HEIGHT 10

typedef struct {
    float x, y; // Player position
    float dirX, dirY; // Player direction
    float planeX, planeY; // Camera plane
} Player;

void initSDL(SDL_Window **window, SDL_Renderer **renderer);
void closeSDL(SDL_Window *window, SDL_Renderer *renderer);
void renderScene(SDL_Renderer *renderer, Player *player, int map[MAP_WIDTH][MAP_HEIGHT]);

#endif // MAZE_H
