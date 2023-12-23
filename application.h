#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "application.h"
#include "ball.h"
#include "controller.h"
#include "main.h"
#include "brick.h"
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
		inline bool is_gameOn() {
			return gameOn;
		}
		
		void poll_events(SDL_Event &event);
		void render(SDL_Renderer *renderer, Ball& ball, Controller& controller, Brick& brick, int flag);

		SDL_Renderer* get_renderer();
		SDL_Texture** get_texture();

	// private:
		bool init();

		SDL_Window *window = nullptr;
		SDL_Renderer *renderer = nullptr;
		SDL_Texture* gTextures[4];
		SDL_Texture* inst;
		SDL_Texture* bg;
		SDL_Texture* over;
		SDL_Texture* stage;
		SDL_Texture* high;

		std::string title;
		int width = 640;
		int height = 480;
		static bool closed;
		static bool gameOn;
};