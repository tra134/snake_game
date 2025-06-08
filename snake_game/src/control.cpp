#include<iostream>
#include "control.h"
#include <SDL2/SDL.h>

void Controller::HandleInput(bool& running, Snake& snake) {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) break;
		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
			case SDLK_UP:
				ChangeDirection(Snake & snake, Snake::Direction up, Snake::Direction down);
				break;

			case SDLK_DOWN:
				ChangeDirection(Snake & snake, Snake::Direction down, Snake::Direction up);
				break;

			case SDLK_LEFT:
				ChangeDirection(Snake & snake, Snake::Direction left, Snake::Direction right);
				break;

			case SDLK_RIGHT:
				ChangeDirection(Snake & snake, Snake::Direction right, Snake::Direction left);
				break;

			}
		}
	}
}

void Controller::ChangeDirection(Snake& snake, Snake::Direction input, Snake::Direction opposite)
{
}

void ChangeDirection(Snake& snake, Snake::Direction input, Snake::Direction opposite) {
	if (snake.direction == opposite) snake.direction = input;
	return;
}