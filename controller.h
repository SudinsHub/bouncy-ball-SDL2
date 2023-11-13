#pragma once

#include <SDL2/SDL.h>

class Controller
{
	public:
		Controller();
		~Controller();

		void poll_events(SDL_Event &event);
		void render(SDL_Renderer *renderer);
		

	
		int x;
		int y;
		int h;
        int w;
		SDL_Rect r;
};