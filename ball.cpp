#include <iostream>
#include <cstdlib>
#include <string>
#include <SDL2/SDL.h>
#include "main.h"
#include "ball.h"
#include"application.h"

Ball::Ball(int x, int y, int radius)
{
	this->x = x;
	this->y = y;
	this->radius = radius;

	this->x_speed = 4;
	this->y_speed = 4;
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
	//midpoint circle algorithm
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
	

	if (x <= RADIUS || x >= WIDTH - RADIUS)
	{
		x_speed *= -1;
		// std::cout << "X: " << this->get_x() << std::endl;
	}
	if (y <= RADIUS || y >= HEIGHT - RADIUS - CONTROLLER_HEIGHT)
	{
		if(y >= HEIGHT - RADIUS - CONTROLLER_HEIGHT){
			int xPosition = this->get_x();
			if(!((xPosition > CONTROLLER_LEFT) && (xPosition < CONTROLLER_LEFT+CONTROLLER_WIDTH))){
		// std::cout << "x: " << this->get_x() << " " << CONTROLLER_LEFT << std::endl;
				Application::closed = true;
			}
		}
		y_speed *= -1;
	}
}
