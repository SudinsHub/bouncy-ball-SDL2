#include <iostream>
#include <cstdlib>
#include <string>
#include <SDL2/SDL.h>
#include "main.h"
#include "ball.h"
#include"application.h"
#include"controller.h"
#include"score.h"

Ball::Ball(int x, int y, int radius)
{
	this->x = x;
	this->y = y;
	this->radius = radius;

	this->x_speed = 4;
	this->y_speed = -4;

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

void Ball::update(int flag)
{
	if(SPACE_FLAG == 1){		
		x += x_speed;
		y += y_speed;
		
		int BrickWidth = WIDTH/ROW;
		int BrickHeight = HEIGHT/COL;

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

					Application::gameOn = false;
				}
			}
			y_speed *= -1;
		}

		if(x%BrickWidth <= RADIUS){
			if((x_speed < 0) && (ARRAY[flag][y/BrickHeight][(x/BrickWidth)-1] == 1)){
				x_speed *= -1;
				ARRAY[flag][y/BrickHeight][(x/BrickWidth)-1] = 0;
				SCORE += 10;
			}
			else if((x_speed > 0) && (ARRAY[flag][y/BrickHeight][x/BrickWidth] == 1)){
				x_speed *= -1;
				ARRAY[flag][y/BrickHeight][x/BrickWidth] = 0;
				SCORE += 10;
			}
		}
		
		if((y%BrickHeight <= RADIUS)){
			if((y_speed < 0) && (ARRAY[flag][(y/BrickHeight)-1][(x/BrickWidth)] == 1)){
				y_speed *= -1;
				ARRAY[flag][(y/BrickHeight)-1][(x/BrickWidth)] = 0;
				SCORE += 10;
			}
			else if((y_speed > 0) && (ARRAY[flag][y/BrickHeight][(x/BrickWidth)] == 1)){
				y_speed *= -1;
				ARRAY[flag][y/BrickHeight][(x/BrickWidth)] = 0;
				SCORE += 10;
			}
		}
	}
	else if(SPACE_FLAG == 0){
		x = CONTROLLER_LEFT+CONTROLLER_WIDTH/2;
		y = HEIGHT-CONTROLLER_HEIGHT-RADIUS;
		
	}
}
