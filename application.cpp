#include "application.h"

Application::Application(const std::string &title, int width, int height)
{
	this->title = title;
	this->width = width;
	this->height = height;

	this->closed = !init();
}

Application::~Application()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

bool Application::closed = false;

bool Application::init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cerr << SDL_GetError() << std::endl;
		return false;
	}

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

	if (window == nullptr)
	{
		std::cerr << SDL_GetError() << std::endl;
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr)
	{
		std::cerr << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}

void Application::render(SDL_Renderer *renderer)
{
	SDL_RenderPresent(renderer);
	SDL_SetRenderDrawColor(renderer, 50, 50, 150, 255);
	SDL_RenderClear(renderer);
}

SDL_Renderer* Application::get_renderer()
{
	return renderer;
}
