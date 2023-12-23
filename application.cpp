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
bool Application::gameOn = false;

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

	gTextures[0] = IMG_LoadTexture(renderer, "resources/start.png");
    gTextures[1] = IMG_LoadTexture(renderer, "resources/score.png");
    gTextures[2] = IMG_LoadTexture(renderer, "resources/inst.png");
    gTextures[3] = IMG_LoadTexture(renderer, "resources/exit.png");
	inst = IMG_LoadTexture(renderer, "resources/instDtls.png");
	bg = IMG_LoadTexture(renderer, "resources/bg.png");
	over = IMG_LoadTexture(renderer, "resources/gameOver.png");
	stage = IMG_LoadTexture(renderer, "resources/stages.png");
	return true;

}

void Application::render(SDL_Renderer *renderer, Ball& ball, Controller& controller, Brick& brick, int flag)
{
	SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, bg, nullptr, nullptr);
    ball.update(flag);
    brick.render(renderer, flag);
    ball.render(renderer, ball.get_x(), ball.get_y(), RADIUS, 166, 5, 5, 0xFF);
    controller.render(renderer);
    SDL_RenderPresent(renderer);
}

SDL_Renderer* Application::get_renderer()
{
	return renderer;
}

SDL_Texture** Application::get_texture()
{
	return gTextures;
}