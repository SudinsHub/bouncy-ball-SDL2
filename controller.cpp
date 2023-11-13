#include<SDL2/SDL.h>
#include<iostream>
#include"controller.h"
#include "application.h"
#include"main.h"
  

Controller::Controller() : x(WIDTH/2), y(HEIGHT-20), w(CONTROLLER_WIDTH), h(CONTROLLER_HEIGHT), r{x, y, w, h} {
}
int CONTROLLER_LEFT = (WIDTH/2);

Controller :: ~Controller(){}

void Controller :: poll_events(SDL_Event &e){

    if (e.type == SDL_QUIT)
    {
        Application::closed = true;
    }
    else if(e.type == SDL_KEYDOWN){
        switch (e.key.keysym.sym)
        {
        case SDLK_RIGHT:
            //cout << r.x << endl;
            if(r.x >= WIDTH - w) break;
            r.x += 20;
            CONTROLLER_LEFT = r.x;
            // std::cout <<  CONTROLLER_LEFT << std::endl;
            break;
        case SDLK_LEFT:
            //cout << r.x << endl;
            if(r.x <= 0) break;
            r.x -= 20;
            CONTROLLER_LEFT = r.x;
            // std::cout <<  CONTROLLER_LEFT << std::endl;
            break;
        }
    }    


        

}
   
void Controller :: render(SDL_Renderer *renderer){
        // setting a rect in it
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &r);
}       

