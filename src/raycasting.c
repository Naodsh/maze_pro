#include <SDL2/SDL.h>
#include "../inc/maze.h"

/* Render scene using raycasting */
void renderScene(SDL_Renderer *renderer, Player *player, int map[MAP_WIDTH][MAP_HEIGHT]) {
    // Clear the renderer with black color
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Example of drawing walls with white color
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int x = 0; x < SCREEN_WIDTH; x++) {
        // Perform raycasting calculations to determine the height of walls at this column (x)
        // This is a simplified example and will need to be replaced with actual raycasting logic

        // Dummy wall height based on column position
        int wallHeight = (x % 100) + 50;

        // Calculate top and bottom of the wall
        int wallTop = (SCREEN_HEIGHT / 2) - (wallHeight / 2);
        int wallBottom = (SCREEN_HEIGHT / 2) + (wallHeight / 2);

        // Draw a vertical line for the wall
        SDL_RenderDrawLine(renderer, x, wallTop, x, wallBottom);
    }

    // Render the floor and ceiling (for simplicity, this example does not render floor and ceiling)

    // Draw a red rectangle in the center of the screen for debugging
    SDL_Rect rect;
    rect.x = SCREEN_WIDTH / 2 - 50;
    rect.y = SCREEN_HEIGHT / 2 - 50;
    rect.w = 100;
    rect.h = 100;
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}