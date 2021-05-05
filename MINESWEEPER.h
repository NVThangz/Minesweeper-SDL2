#ifndef MINESWEEPER_H_INCLUDED
#define MINESWEEPER_H_INCLUDED

#include "SDL_UTILITIES.h"

#define MAXBG 90
#define DELAYBG 5

#define LOGO_WIDTH 318
#define LOGO_HEIGHT 158

#define BEGINNER_SIDE 9
#define INTERMEDIATE_SIDE 12
#define EXPERT_SIDE 16
#define BEGINNER_MINES 10
#define INTERMEDIATE_MINES 30
#define EXPERT_MINES 50
#define BEGINNER_MULTILYSCORE 1
#define INTERMEDIATE_MULTILYSCORE 1.5
#define EXPERT_MULTILYSCORE 2

#define SAFEMINE 3

#define SIDE 32
#define COUNTSIDE 48
#define MAX_WIDTH 16
#define MAX_HEIGHT 16
#define DEFAULT_X ( SCREEN_HEIGHT - ( MAX_HEIGHT * SIDE ) ) / 2
#define DEFAULT_COUNT_Y DEFAULT_X + MAX_HEIGHT*SIDE + COUNTSIDE/2 + 10

#define TIMELIMIT 999

struct Tile
{
    bool isMine = false;
    char n =  0 ;  // Neighbors
    bool isRevealed = false;
    bool isFlag = false;
    bool MouseIn = false;
};

struct BoardInfo
{
    int Board_Height;
    int Board_Width;
    int Mines;
    float MultiplyScore;
};


void Menu(bool &turnoff, bool &isFullscreen, SDL_Renderer* renderer , SDL_Window* window);

BoardInfo ChooseDifferent(bool &turnoff, SDL_Renderer* renderer);

void PlayMineSweeper(bool &turnoff, SDL_Renderer* renderer, BoardInfo Info);

#endif // MINESWEEPER_H_INCLUDED
