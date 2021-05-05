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
#define MAX_WIDTH 30
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

/*
void PlaceFlag(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width, int Mines, int Tile_x, int Tile_y);
void PlaceMine(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width, int Mines);
int BombLeft(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width, int Mines);
void CountNeighbors(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width);
void RevealNeighbors(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width, int x, int y);
void ClearBoard(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width);
void MakeNewBoard(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width, int Mines, SDL_Renderer* renderer);


void ShowBoard(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width, int Mines, int countbomb, int timer, char clicksafe, int button, SDL_Renderer* renderer);

void ShowTrueBoard(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width, int countbomb, int Mines, int timer, char clicksafe, int button, SDL_Renderer* renderer);

void PlayAgain(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width, int Mines, int countbomb, int timer, char clicksafe, int button, bool &isstarttimer, bool &ingame, bool &turnoff, SDL_Renderer* renderer);


void IfYouWin(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width, int Mines, bool &ingame, bool &turnoff, SDL_Renderer* renderer);
void IfYouLose(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width, int Mines, bool &ingame, bool &turnoff, SDL_Renderer* renderer);

bool IsWin(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width, int Mines);
bool IsLose (Tile board[][MAX_WIDTH], int Board_Height, int Board_Width, int timer);
void CheckWinOrLose(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width, int Mines, int countbomb, int timer, float MultiplyScore, bool &isstarttimer, bool &ingame, bool &turnoff, char &clicksafe, int button,SDL_Renderer* renderer);
void MouseClear(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width);
void MouseInGame(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width, int &countbomb, int &button, bool &ingame, bool &turnoff, char &clicksafe, Mix_Chunk* flag, Mix_Chunk* unflag, Mix_Chunk* click, Mix_Chunk* wrong);
int CountTime(bool &isstarttimer, int &starttime);*/
void PlayMineSweeper(bool &turnoff, SDL_Renderer* renderer, BoardInfo Info);
//void RevealNeighbors(int x, int y);
#endif // MINESWEEPER_H_INCLUDED
