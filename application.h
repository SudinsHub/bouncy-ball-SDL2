#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include <cstdlib>
#include <string>

class Application
{
	public:
		Application(const std::string &title, int width, int height);
		~Application();

		inline bool is_closed() {
			return closed;
		}

		void poll_events(SDL_Event &event);
		void render(SDL_Renderer *renderer);

		SDL_Renderer* get_renderer();

	// private:
		bool init();

		SDL_Window *window = nullptr;
		SDL_Renderer *renderer = nullptr;

		std::string title;
		int width = 640;
		int height = 480;
		static bool closed;
};