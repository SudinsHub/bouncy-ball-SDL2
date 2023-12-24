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

    SDL_Surface* surfaceText = TTF_RenderText_Solid(ourFont,text.c_str(),{0, 0, 0});

    SDL_Texture* textureText = SDL_CreateTextureFromSurface(renderer,surfaceText);

    SDL_FreeSurface(surfaceText); 

    SDL_Rect rectangle;
    rectangle.x = 450;
    rectangle.y = 150;
    rectangle.w = 100;
    rectangle.h = 80;
    SDL_RenderCopy(renderer,textureText,NULL,&rectangle);

}


void Score::renderHiScore(SDL_Renderer *renderer){
    // render
    
    if(TTF_Init() == -1){
        std::cout << "Could not initailize SDL2_ttf, error: " << TTF_GetError() << std::endl; 
    }


    TTF_Font* ourFont = TTF_OpenFont("resources/darkforest.ttf",32);
    if(ourFont == nullptr){
        std::cout << "Could not load font" << std::endl;
    }

    SDL_Surface* surfaceText = TTF_RenderText_Solid(ourFont,hiScore.c_str(),{0, 0, 0});

    SDL_Texture* textureText = SDL_CreateTextureFromSurface(renderer,surfaceText);

    SDL_FreeSurface(surfaceText); 

    SDL_Rect rectangle;
    rectangle.x = 245;
    rectangle.y = 150;
    rectangle.w = 150;
    rectangle.h = 100;
    SDL_RenderCopy(renderer,textureText,NULL,&rectangle);

}
int Score::loadHiScore(){
 // Open
    ifstream inputFile("resources/score.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
    }

    // Read
    getline(inputFile, hiScore);

    // Close
    inputFile.close();

    return stoi(hiScore);
}

void Score::updateHiScore(){
    if(SCORE > MAX_SCORE){
        ofstream myfile;
        myfile.open ("resources/score.txt");
        myfile << SCORE;
        myfile.close();
    }
}