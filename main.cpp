#include <iostream>
#include <SDL2/SDL.h>

#include "application.h"
#include "ball.h"
#include "controller.h"
#include "main.h"

const int WIDTH = 640;
const int HEIGHT = 480;
const int CONTROLLER_WIDTH = 100;
const int CONTROLLER_HEIGHT = 20;
const int RADIUS = 10;
SDL_Event event;


int main(int argc, char *argv[])
{	
	Application application("Bouncing Ball", WIDTH, HEIGHT);
	Ball ball(100, 100, RADIUS);
	Controller controller;

	while (!application.is_closed())
	{
		while(SDL_PollEvent(&event))
		{
			// application.poll_events(event);
			controller.poll_events(event);
		}

		application.render(application.get_renderer());
		ball.update();
		ball.render(application.get_renderer(), ball.get_x(), ball.get_y(), RADIUS, 0xFF, 0x00, 0xFF, 0xFF);
		controller.render(application.get_renderer());
		SDL_Delay(10); 
	}

	SDL_Quit();

	return 0;
}