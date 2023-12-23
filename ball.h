#pragma once

#include <SDL2/SDL.h>

class Ball
{
	public:
		Ball(int x, int y, int radius);
		~Ball();

		void poll_events(SDL_Event &event);
		void render(SDL_Renderer *renderer, int cx, int cy, int radius, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

		inline int get_x() const { return x; }
		inline int get_y() const { return y; }

		void update(int flag);

	private:
		int x;
		int y;
		int radius;
		int x_speed;
		int y_speed;
};