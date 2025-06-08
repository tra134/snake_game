#pragma once

#include "snake.h"

class Controller {

private:
	void HandleInput(bool& running, Snake& snake);
	void ChangeDirection(Snake& snake, Snake::Direction input, Snake::Direction opposite);
};
