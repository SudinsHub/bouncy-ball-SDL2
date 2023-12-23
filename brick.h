#pragma once

#include<SDL2/SDL.h>
#include<iostream>
#include"main.h"
#include<fstream>
#include<string>
#include <sstream>

using namespace std;


class Brick{
public:

	void loadBrick();
	void render(SDL_Renderer *renderer, int flag);

};