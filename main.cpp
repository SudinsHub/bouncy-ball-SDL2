#include <iostream>
#include <SDL2/SDL.h>

#include "application.h"
#include "ball.h"
#include "controller.h"
#include "main.h"
#include "brick.h"

const int WIDTH = 640;
const int HEIGHT = 480;
const int CONTROLLER_WIDTH = 100;
const int CONTROLLER_HEIGHT = 20;
const int RADIUS = 5;
SDL_Event event;
int startTime = SDL_GetTicks(); 
int brickDelay = 4000; //ms 

int main(int argc, char *argv[])
{	
	Application application("Bouncing Ball", WIDTH, HEIGHT);
	Ball ball(100, 100, RADIUS);
	Controller controller;
	Brick brick;

	brick.loadBrick();

	while (!application.is_closed())
	{
		while(SDL_PollEvent(&event))
		{
			// application.poll_events(event);
			controller.poll_events(event);
		}
		// int currentTime = SDL_GetTicks();
		// if(currentTime-startTime >= brickDelay){
		// 	brick.update();
		// 	startTime = SDL_GetTicks();
		// } 
		brick.render(application.get_renderer());
		application.render(application.get_renderer());
		ball.update();
		ball.render(application.get_renderer(), ball.get_x(), ball.get_y(), RADIUS, 0xFF, 0x00, 0xFF, 0xFF);
		controller.render(application.get_renderer());
		SDL_Delay(10); 
	}

	SDL_Quit();

	return 0;
}