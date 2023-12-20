#include"brick.h"
#include "application.h"


const int ROW =16, COL = 24; //number of brick in row and col
int ARRAY[100][100];

void Brick::loadBrick(){
    ifstream fIle("brick.csv");

    int i = 0;
    string line;

    while (getline(fIle, line) && i < COL) {
        istringstream iss(line);
        string brickInd;

        int j = 0;
        while (getline(iss, brickInd, ',') && j < ROW) {
            ARRAY[i][j] = stoi(brickInd);
            j++;
        }

        // Move to the next row
        i++;
    }

}

// void Brick::update(){
//     for(int i=0; i<ROW; i++){
//         if (ARRAY[COL-1][i] == 1)
//             Application::closed = true;        
//     }
//     for(int i=COL-2; i>=0; i--){
//         for (int j = 0; j < ROW; j++){
//             ARRAY[i+1][j] =ARRAY[i][j];
//         }
//     }
//     for (int i = 0; i < ROW; i++)
//     {
//         ARRAY[0][i] = 1;
//     }    
// }

void Brick::render(SDL_Renderer *renderer){
    for(int i = 0; i < COL; i++){
        for (int j = 0; j < ROW; j++){
            if (ARRAY[i][j] == 1)
            {
                SDL_Rect r{j*(WIDTH/ROW), i*(HEIGHT/COL), WIDTH/ROW, HEIGHT/COL};
                
                // setting a rect in it
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderDrawRect(renderer, &r);		
            }
            
        }
    }
}