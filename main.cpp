#include <iostream>
#include <SDL.h>

#include "application.h"
#include "ball.h"

static const int WIDTH = 640;
static const int HEIGHT = 480;

void poll_all_events(Application &application, Ball &ball)
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		application.poll_events(event);
		ball.poll_events(event);
	}
}

int main(int argc, char *argv[])
{
	Application application("Bouncing Ball", WIDTH, HEIGHT);
	Ball ball(100, 100, 20);

	while (!application.is_closed())
	{
		poll_all_events(application, ball);
		application.render();
		ball.update();
		ball.render(application.get_renderer(), ball.get_x(), ball.get_y(), 20, 0xFF, 0x00, 0xFF, 0xFF);
	}

	return 0;
}