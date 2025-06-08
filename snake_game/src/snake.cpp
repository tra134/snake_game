#include "snake.h"
#include <cmath>
#include <iostream>

void Snake::Update() {
	SDL_Point prev_head{
	static_cast<int>(head_x),
	static_cast<int>(head_y)
	};

	UpdateHead();

	SDL_Point curr_head{
	static_cast<int>(head_x),
	static_cast<int>(head_y)
	};

	if (curr_head.x != prev_head.x || curr_head.y != prev_head.y) {
		UpdateBody(curr_head, prev_head);
	}



}

void Snake::UpdateHead() {
	switch (direction) {
	case Direction::up:
		head_y -= speed;

	case Direction::down:
		head_y += speed;

	case Direction::left:
		head_x -= speed;

	case Direction::right:
		head_x += speed;
	}

	head_x = fmod(head_x + grid_width, grid_width);
	head_x = fmod(head_y + grid_height, grid_height);
}

void Snake::UpdateBody(SDL_Point& curr_head, SDL_Point& prev_head) {
	body.push_back(prev_head);

	if (!growing) {
		body.erase(body.begin());
	}
	else {
		growing = false;
		size++;
	}

	for (const auto& it : body) {
		if (curr_head.x == it.x && curr_head.y == it.y) alive = false;
	}
}

void Snake::GrowBody() { growing = true; }

bool Snake::SnakeCell(int x, int y) {
	if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y)) {
		return true;
	}
	for (auto const& item : body) {
		if (x == item.x && y == item.y) {
			return true;
		}
	}
	return false;
}
