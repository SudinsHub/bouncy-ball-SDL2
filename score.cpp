#include"score.h"



void Score::renderScore(SDL_Renderer *renderer){
    std::string text = std::to_string(SCORE);
        if(TTF_Init() == -1){
        std::cout << "Could not initailize SDL2_ttf, error: " << TTF_GetError() << std::endl; 
    }


    TTF_Font* ourFont = TTF_OpenFont("resources/darkforest.ttf",32);
    if(ourFont == nullptr){
        std::cout << "Could not load font" << std::endl;
        exit(1);
    }
    // Pixels from our text
    SDL_Surface* surfaceText = TTF_RenderText_Solid(ourFont,text.c_str(),{255,255,255});

    // Setup the texture
    SDL_Texture* textureText = SDL_CreateTextureFromSurface(renderer,surfaceText);

    // Free the surface
    SDL_FreeSurface(surfaceText); 

    // a rectangle to draw on
    SDL_Rect rectangle;
    rectangle.x = 10;
    rectangle.y = 10;
    rectangle.w = 400;
    rectangle.h = 100;
    SDL_RenderCopy(renderer,textureText,NULL,&rectangle);

}