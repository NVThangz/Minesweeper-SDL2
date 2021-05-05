#include "MINESWEEPER.h"

int main(int argc, char* argv[])
{
    srand(time(NULL));
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    bool turnoff = false;
    bool isFullscreen = false;
    BoardInfo Info;

    //initSDL
    initSDL(window, renderer);

    //initTTF
    if (TTF_Init() < 0)
	{
		SDL_Log("%s", TTF_GetError());
		return -1;
	}
    //initMix
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
	{
		printf("%s", Mix_GetError());
		turnoff = true;
	}

	//bắt đầu chơi game
    while(!turnoff)
    {
        Menu(turnoff, isFullscreen, renderer, window);
        if(turnoff) break;
        Info = ChooseDifferent(turnoff, renderer);
        if(turnoff) break;
        PlayMineSweeper(turnoff, renderer, Info);
    }

    //tắt game
    quitSDL(window, renderer);
    return 0;
}
