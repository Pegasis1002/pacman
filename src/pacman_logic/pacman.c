#include "pacman.h"
#include <SDL2/SDL.h>

#define PACMAN_SPEED 5

void movePacman(SDL_Rect *pacman, SDL_Keycode key){

    switch (key) {
        case SDLK_UP:
            pacman->y -= PACMAN_SPEED;
            break;
        case SDLK_DOWN:
            pacman->y += PACMAN_SPEED;
            break;
        case SDLK_LEFT:
            pacman->x -= PACMAN_SPEED;
            break;
        case SDLK_RIGHT:
            pacman->x += PACMAN_SPEED;
            break;
        default:
            break;
    }
}
