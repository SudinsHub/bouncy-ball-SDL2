#include <iostream>
#include <cstdlib>
#include <string>
#include <SDL.h>

#include "ball.h"

Ball::Ball(int x, int y, int radius)
{
	this->x = x;
	this->y = y;
	this->radius = radius;

	this->x_speed = 3;
	this->y_speed = 3;
}

Ball::~Ball()
{
}

void Ball::poll_events(SDL_Event &event)
{
}

void Ball::render(SDL_Renderer *renderer, int cx, int cy, int radius, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	static const int BPP = 4;

	for (double dy = 1; dy <= radius; dy += 1.0)
	{
		double dx = floor(sqrt((2.0 * radius * dy) - (dy * dy)));
		int x = (cx - dx);
	
		SDL_SetRenderDrawColor(renderer, r, g, b, a);
		SDL_RenderDrawLine(renderer, (cx - dx), cy + dy - radius, (cx + dx), cy + dy - radius);
		SDL_RenderDrawLine(renderer, (cx - dx), cy - dy + radius, (cx + dx), cy - dy + radius);
	}
}

void Ball::update()
{
	x += x_speed;
	y += y_speed;

	if (x <= 20 || x >= 640 - 20)
	{
		x_speed *= -1;
		std::cout << "X: " << this->get_x() << std::endl;
	}
	if (y <= 20 || y >= 480 - 20)
	{
		y_speed *= -1;
		std::cout << "Y: " << this->get_y() << std::endl;
	}
}
