#include"brick.h"
#include "application.h"


const int ROW =16, COL = 24; //number of brick in row and col
int ARRAY[5][100][100];
void loader(string str, int p){
    ifstream fIle(str);

    int i = 0;
    string line;

    while (getline(fIle, line) && i < COL) {
        istringstream iss(line);
        string brickInd;

        int j = 0;
        while (getline(iss, brickInd, ',') && j < ROW) {
            ARRAY[p][i][j] = stoi(brickInd);
            j++;
        }

        // Move to the next row
        i++;
    }

}
void Brick::loadBrick(){
    loader("resources/stages/level1.csv", 0);
    loader("resources/stages/level2.csv", 1);
    loader("resources/stages/level3.csv", 2);
    loader("resources/stages/level4.csv", 3);
    loader("resources/stages/level5.csv", 4);


    ifstream fIle("resources/stages/level3.csv");

    // int i = 0;
    // string line;

    // while (getline(fIle, line) && i < COL) {
    //     istringstream iss(line);
    //     string brickInd;

    //     int j = 0;
    //     while (getline(iss, brickInd, ',') && j < ROW) {
    //         ARRAY[2][i][j] = stoi(brickInd);
    //         j++;
    //     }

    //     // Move to the next row
    //     i++;
    // }
}

void Brick::render(SDL_Renderer *renderer, int flag){
    for(int i = 0; i < COL; i++){
        for (int j = 0; j < ROW; j++){
            if (ARRAY[flag][i][j] == 1)
            {
                SDL_Rect r{j*(WIDTH/ROW), i*(HEIGHT/COL), WIDTH/ROW, HEIGHT/COL};
                
                // setting a rect in it
                SDL_SetRenderDrawColor(renderer, 165, 42, 42, 255);
                SDL_RenderFillRect(renderer, &r);	
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderDrawRect(renderer, &r);	
            }
            
        }
    }
}