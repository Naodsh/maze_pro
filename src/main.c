// #include <stdio.h>
// #include <SDL2/SDL.h>
// int main(int argc, char* args[]) {
//     SDL_Init(SDL_CreateWindow);
//     printf("Hello");
// }

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "../inc/maze.h"
#include <stdio.h>

/* Initialize SDL2 */
void initSDL(SDL_Window **window, SDL_Renderer **renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    } else {
        *window = SDL_CreateWindow("Maze Project",
                                   SDL_WINDOWPOS_CENTERED,
                                   SDL_WINDOWPOS_CENTERED,
                                   SCREEN_WIDTH, SCREEN_HEIGHT,
                                   SDL_WINDOW_SHOWN);
        if (*window == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        } else {
            *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
            if (*renderer == NULL) {
                printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
            }
        }
    }
}

/* Close SDL2 */
void closeSDL(SDL_Window *window, SDL_Renderer *renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

/* Main function */
int main(int argc, char* args[]) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    printf("Initializing SDL...\n");
    initSDL(&window, &renderer);
    if (window == NULL || renderer == NULL) {
        printf("Failed to initialize SDL.\n");
        return 1;
    }

    /* Player setup */
    Player player = {5.0, 5.0, -1.0, 0.0, 0.0, 0.66};

    /* Sample map */
    int map[MAP_WIDTH][MAP_HEIGHT] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    /* Main loop flag */
    bool quit = false;
    SDL_Event e;

    printf("Entering main loop...\n");
    while (!quit) {
        /* Handle events */
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        /* Render scene */
        printf("Rendering scene...\n");
        renderScene(renderer, &player, map);
        SDL_RenderPresent(renderer);
        SDL_Delay(100);  // Delay to reduce CPU usage
    }

    printf("Cleaning up and exiting...\n");
    closeSDL(window, renderer);
    return 0;
}
