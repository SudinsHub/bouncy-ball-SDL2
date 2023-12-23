#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "application.h"
#include "ball.h"
#include "controller.h"
#include "main.h"
#include "brick.h"
#include "score.h"

const int WIDTH = 640;
const int HEIGHT = 480;
const int CONTROLLER_WIDTH = 125;
const int CONTROLLER_HEIGHT = 20;
const int RADIUS = 10;
int SCORE = 0;
int SPACE_FLAG = 0;
SDL_Event event;
int startTime = SDL_GetTicks(); 
int brickDelay = 4000; //ms 
int currentTextureIndex = 0;


void over(Application& application, Score& score){
	int overFlag = 1;
	while (overFlag){
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
			Application::closed = true;
			overFlag = 0;
			}
			else if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym) {
					case SDLK_KP_ENTER:
						overFlag = 0;
						break;
				}
				switch (event.key.keysym.scancode) {
					case SDL_SCANCODE_RETURN:
						overFlag = 0;
						break;
				}
			}
		}
		SDL_RenderClear(application.get_renderer());					
		SDL_RenderCopy(application.get_renderer(), application.over, nullptr, nullptr);
		score.renderScore(application.get_renderer());
		SDL_RenderPresent(application.get_renderer());
	}
	SPACE_FLAG = 0;
	SCORE = 0;
}

void game(Application& application, Ball& ball, Controller& controller, Brick& brick, Score& score, int flag){
	SDL_RenderClear(application.get_renderer());
	brick.loadBrick();
	application.gameOn = true;
	while (application.is_gameOn()){
		while(SDL_PollEvent(&event)){
			controller.poll_events(event);
		}
		application.render(application.get_renderer(), ball, controller, brick, flag);
	}
	
	over(application, score);
}

void stageSelect(Application& application, Ball& ball, Controller& controller, Brick& brick, Score& score){
	int stageFlag = 1;
	while (stageFlag){
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym) {
					case SDLK_1:
					case SDLK_KP_1:
						stageFlag = 0;
						game(application, ball, controller, brick, score, 0);
						break;
					case SDLK_2:
					case SDLK_KP_2:
						stageFlag = 0;
						game(application, ball, controller, brick, score, 1);
						break;
					case SDLK_3:
					case SDLK_KP_3:
						stageFlag = 0;
						game(application, ball, controller, brick, score, 2);
						break;
					case SDLK_4:
					case SDLK_KP_4:
						stageFlag = 0;
						game(application, ball, controller, brick, score, 3);
						break;
					case SDLK_5:
					case SDLK_KP_5:
						stageFlag = 0;
						game(application, ball, controller, brick, score, 4);
						break;
				}
			}
		}
		SDL_RenderClear(application.get_renderer());					
		SDL_RenderCopy(application.get_renderer(), application.stage, nullptr, nullptr);
		SDL_RenderPresent(application.get_renderer());
	}
}

void inst(Application& application){
	int instFlag = 1;
	while (instFlag){
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym) {
					case SDLK_ESCAPE:
						instFlag = 0;
						break;
				}
			}
		}
		SDL_RenderClear(application.get_renderer());					
		SDL_RenderCopy(application.get_renderer(), application.inst, nullptr, nullptr);
		SDL_RenderPresent(application.get_renderer());
	}
}

void menu(Application& application, Ball& ball, Controller& controller, Brick& brick, Score& score){
	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_QUIT) {
			Application::closed = true;
		} else if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
				case SDLK_DOWN:
					currentTextureIndex = (currentTextureIndex + 1) % 4;
					break;
				case SDLK_UP:
					currentTextureIndex = (currentTextureIndex - 1 + 4) % 4;
					break;
				case SDLK_KP_ENTER:
					if (currentTextureIndex == 0)
					{
						stageSelect(application, ball, controller, brick, score);
						break;
					} 
					else if(currentTextureIndex == 3){
						application.closed = true;
						break;
					}
					else if(currentTextureIndex == 2){
						inst(application);
					}
			}
			// handle general enter
			switch(event.key.keysym.scancode) {
				case SDL_SCANCODE_RETURN:
					if (currentTextureIndex == 0)
					{
						stageSelect(application, ball, controller, brick, score);
						break;
					} 
					else if(currentTextureIndex == 3){
						application.closed = true;
						break;
					}
					else if(currentTextureIndex == 2){
						inst(application);
					}
				}
		}
    }
	SDL_Texture** tex = application.get_texture();
	SDL_RenderClear(application.get_renderer());
	SDL_RenderCopy(application.get_renderer(), tex[currentTextureIndex], nullptr, nullptr);
	SDL_RenderPresent(application.get_renderer());
}

int main(int argc, char *argv[])
{	
	Application application("Bouncing Ball", WIDTH, HEIGHT);
	Ball ball(CONTROLLER_LEFT+CONTROLLER_WIDTH/2, HEIGHT-CONTROLLER_HEIGHT-RADIUS, RADIUS);
	Controller controller;
	Brick brick;
	Score score;
	// for(int i=0; i<COL; i++){
	// 	for(int j=0; j<ROW; j++){
	// 		cout << ARRAY[2][i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	if (SDL_PollEvent(&event)) {
		cout << "Buffer Cleared" << endl;
    }
	while (!application.is_closed())
	{
		menu(application, ball, controller, brick, score);
	}

	SDL_Quit();

	return 0;
}