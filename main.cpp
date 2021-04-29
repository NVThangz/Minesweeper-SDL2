#include "MINESWEEPER.h"

int main(int argc, char* argv[])
{
    srand(time(NULL));
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    //khi nao dung game
    bool turnoff = false;
    //thong tin man choi
    BoardInfo Info;

    //init SDL
    initSDL(window, renderer);
    //khoi tao TTF
    if (TTF_Init() < 0)
	{
		SDL_Log("%s", TTF_GetError());
		return -1;
	}

    //bat dau choi
    while(!turnoff)
    {
        Menu(turnoff, renderer, window);
        if(turnoff) break;
        Info = ChooseDifferent(turnoff, renderer);
        if(turnoff) break;
        PlayMineSweeper(turnoff, renderer, Info);
    }


   // waitUntilKeyPressed();
   //tat cua so
    quitSDL(window, renderer);
    return 0;
}
