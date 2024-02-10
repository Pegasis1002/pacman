#include <SDL2/SDL.h>
#include "pacman_logic/pacman.h"

// Constants
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define PACMAN_SIZE 20

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Pac-Man Clone", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Rect pacman = {WINDOW_WIDTH / 2 - PACMAN_SIZE / 2, WINDOW_HEIGHT / 2 - PACMAN_SIZE / 2, PACMAN_SIZE, PACMAN_SIZE};

    SDL_Event event;
    int quit = 0;

    while (!quit) {
        // Poll for events
        while (SDL_PollEvent(&event)) {
            // Handle quit event
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
            else if (event.type == SDL_KEYDOWN) {
                movePacman(&pacman, event.key.keysym.sym);
            }
        }

        // Clear the renderer
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw Pac-Man
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        SDL_RenderFillRect(renderer, &pacman);

        // Present the renderer
        SDL_RenderPresent(renderer);
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
