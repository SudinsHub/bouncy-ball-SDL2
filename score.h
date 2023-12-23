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
#include <SDL2/SDL_ttf.h>

class Score
{
public:

    void renderScore(SDL_Renderer *renderer);
    void hiScore();
};