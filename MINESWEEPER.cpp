#include "MINESWEEPER.h"

//Giao diện Menu
void Menu(bool &turnoff, bool &isFullscreen, SDL_Renderer* renderer , SDL_Window* window)
{
    SDL_Texture *Play = LoadTextFont("Play",  "font//bitmap.TTF", renderer, 80, ORANGE_R, ORANGE_G, ORANGE_B);
    SDL_Texture *PlayIn = LoadTextFont("Play",  "font//bitmap.TTF", renderer, 80, LIGHTGRAY_RGB, LIGHTGRAY_RGB, LIGHTGRAY_RGB);
    SDL_Texture *Logo = loadTexture("img//LOGO.BMP", renderer);
    SDL_Texture *Fullscreenlogo = loadJPGTexture("img//fullscreen.jpg", renderer);
    SDL_Texture *Exitfullscreenlogo = loadJPGTexture("img//exitfullscreen.jpg", renderer);


    int countbg = 0;
    int delaycountbg = 0;
    bool inPlay = false;

    SDL_Event e;

    Mix_Music *music = NULL;

    int timestart;
    int timeframe = 1000/FPS;

    if(Logo == NULL || Play == NULL ||PlayIn == NULL ||Fullscreenlogo == NULL ||Exitfullscreenlogo == NULL)
    {
        cout << "Error :" << SDL_GetError() << endl;
        turnoff = true;
    }

    music = Mix_LoadMUS("Sound//background_music.wav");
	if (music == NULL)
	{
		printf("%s", Mix_GetError());
		turnoff = true;
	}


    Mix_PlayMusic(music, -1);
    Mix_VolumeMusic(MIX_MAX_VOLUME);

    while(!turnoff)
    {
        timestart = SDL_GetTicks();
        if( SDL_PollEvent( &e ) != 0 )
        {
            if (e.type == SDL_QUIT)
            {
                turnoff = true;
                break;
            }

            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
            {
                turnoff = true;
                break;
            }

            ChooseTextClickable(SCREEN_WIDTH/2-TextWidth("Play", 80)/2 , SCREEN_HEIGHT/2+SCREEN_HEIGHT/4-25, TextWidth("Play", 80), 80, inPlay, e);

            if(ClickText(SCREEN_WIDTH/2-TextWidth("Play", 80)/2 , SCREEN_HEIGHT/2+SCREEN_HEIGHT/4-25, TextWidth("Play", 80), 80, e))
            {
                break;
            }
            if(ClickText(20, SCREEN_HEIGHT - 100, 80, 80, e))
            {
                if(!isFullscreen)
                {
                    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
                    isFullscreen = true;
                }
                else
                {
                    SDL_SetWindowFullscreen(window, 0);
                    isFullscreen = false;
                }
            }
        }
        if(countbg > MAXBG) countbg = 0;
        string gbackground = "img//GBackground//frame (" + std::to_string(countbg) + ").jpg" ;
        SDL_Texture *Background = loadJPGTexture(gbackground, renderer);
        renderTexture(Background, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        renderTexture(Logo, renderer, SCREEN_WIDTH/2-LOGO_WIDTH/2 , SCREEN_HEIGHT/2-SCREEN_HEIGHT/4-LOGO_HEIGHT/2, LOGO_WIDTH, LOGO_HEIGHT);
        if(!isFullscreen)
            renderTexture(Fullscreenlogo, renderer, 20 , SCREEN_HEIGHT - 100, 80, 80);
        else
            renderTexture(Exitfullscreenlogo, renderer, 20 , SCREEN_HEIGHT - 100, 80, 80);
        RenderTextClickable(Play, PlayIn, renderer, SCREEN_WIDTH/2-TextWidth("Play", 80)/2 , SCREEN_HEIGHT/2+SCREEN_HEIGHT/4-25, TextWidth("Play", 80), 80, inPlay);
        SDL_RenderPresent(renderer);
        delaycountbg ++;
        if(delaycountbg == DELAYBG)
        {
            countbg ++;
            delaycountbg = 0;
        }

        SDL_DestroyTexture(Background);


        SDL_Delay(delaytime(timestart, timeframe));

    }
    SDL_DestroyTexture(Play);
    SDL_DestroyTexture(PlayIn);
    SDL_DestroyTexture(Logo);
    SDL_DestroyTexture(Fullscreenlogo);
    SDL_DestroyTexture(Exitfullscreenlogo);
    SDL_RenderClear(renderer);
    return;
}

//Giao diện chọn độ khó
BoardInfo ChooseDifferent(bool &turnoff, SDL_Renderer* renderer)
{
    SDL_Texture *Beginner = LoadTextFont("Beginner",  "font//bitmap.TTF", renderer, 50, ORANGE_R, ORANGE_G, ORANGE_B);
    SDL_Texture *BeginnerIn = LoadTextFont("Beginner",  "font//bitmap.TTF", renderer, 50, LIGHTGRAY_RGB, LIGHTGRAY_RGB, LIGHTGRAY_RGB);
    SDL_Texture *Intermediate = LoadTextFont("Intermediate",  "font//bitmap.TTF", renderer, 50, ORANGE_R, ORANGE_G, ORANGE_B);
    SDL_Texture *IntermediateIn = LoadTextFont("Intermediate",  "font//bitmap.TTF", renderer, 50, LIGHTGRAY_RGB, LIGHTGRAY_RGB, LIGHTGRAY_RGB);
    SDL_Texture *Expert = LoadTextFont("Expert",  "font//bitmap.TTF", renderer, 50, ORANGE_R, ORANGE_G, ORANGE_B);
    SDL_Texture *ExpertIn = LoadTextFont("Expert",  "font//bitmap.TTF", renderer, 50, LIGHTGRAY_RGB, LIGHTGRAY_RGB, LIGHTGRAY_RGB);
    SDL_Texture *Choosedifferent = LoadTextFont("Choose Different",  "font//bitmap.TTF", renderer, 80, ORANGE_R, ORANGE_G, ORANGE_B);



    SDL_Event e;


    BoardInfo Info;

    int countbg = 0;
    int delaycountbg = 0;

    int timestart;
    int timeframe = 1000/FPS;

    bool inBeginner = false;
    bool inIntermediate = false;
    bool inExpert = false;

    while(!turnoff)
    {
        timestart = SDL_GetTicks();
        if(SDL_PollEvent( &e ) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                turnoff = true;
                break;
            }

            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
            {
                turnoff = true;
                break;
            }
            if(ClickText(SCREEN_WIDTH/4-TextWidth("Beginner", 50)/2 , SCREEN_HEIGHT/2-SCREEN_HEIGHT/4+50, TextWidth("Beginner", 50), 50, e))
            {
                Info.Board_Height = BEGINNER_SIDE;
                Info.Board_Width = BEGINNER_SIDE;
                Info.Mines = BEGINNER_MINES;
                Info.MultiplyScore = BEGINNER_MULTILYSCORE;
                break;
            }
            if(ClickText(SCREEN_WIDTH/4-TextWidth("Intermediate", 50)/2 , SCREEN_HEIGHT/2+50, TextWidth("Intermediate", 50), 50, e))
            {
                Info.Board_Height = INTERMEDIATE_SIDE;
                Info.Board_Width = INTERMEDIATE_SIDE;
                Info.Mines = INTERMEDIATE_MINES;
                Info.MultiplyScore = INTERMEDIATE_MULTILYSCORE;
                break;
            }
            if(ClickText(SCREEN_WIDTH/4-TextWidth("Expert", 50)/2 , SCREEN_HEIGHT/2+SCREEN_HEIGHT/4+50, TextWidth("Expert", 50), 50, e))
            {
                Info.Board_Height = EXPERT_SIDE;
                Info.Board_Width = EXPERT_SIDE;
                Info.Mines = EXPERT_MINES;
                Info.MultiplyScore = EXPERT_MULTILYSCORE;
                break;
            }
            ChooseTextClickable(SCREEN_WIDTH/4-TextWidth("Beginner", 50)/2 , SCREEN_HEIGHT/2-SCREEN_HEIGHT/4+50, TextWidth("Beginner", 50), 50, inBeginner, e);
            ChooseTextClickable(SCREEN_WIDTH/4-TextWidth("Intermediate", 50)/2 , SCREEN_HEIGHT/2+50, TextWidth("Intermediate", 50), 50, inIntermediate, e);
            ChooseTextClickable(SCREEN_WIDTH/4-TextWidth("Expert", 50)/2 , SCREEN_HEIGHT/2+SCREEN_HEIGHT/4+50, TextWidth("Expert", 50), 50, inExpert, e);

        }
        if(countbg > MAXBG) countbg = 0;
        string gbackground = "img//GBackground//frame (" + std::to_string(countbg) + ").jpg" ;
        SDL_Texture *Background = loadJPGTexture(gbackground, renderer);
        renderTexture(Background, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        renderTexture(Choosedifferent, renderer, SCREEN_WIDTH/2-TextWidth("Intermediate", 80)/2, 20, TextWidth("Intermediate", 80), 80);
        RenderTextClickable(Beginner, BeginnerIn, renderer, SCREEN_WIDTH/4-TextWidth("Beginner", 50)/2 , SCREEN_HEIGHT/2-SCREEN_HEIGHT/4+50, TextWidth("Beginner", 50), 50, inBeginner);
        if(inBeginner)
        {
            SDL_Texture *Boardheight = LoadTextFont("Board Height : " + std::to_string(BEGINNER_SIDE),  "font//bitmap.TTF", renderer, 40, 255, 255, 0);
            SDL_Texture *Boardwidth = LoadTextFont("Board Width : " + std::to_string(BEGINNER_SIDE),  "font//bitmap.TTF", renderer, 40, 255, 255, 0);
            SDL_Texture *Mines = LoadTextFont("Mines : " + std::to_string(BEGINNER_MINES),  "font//bitmap.TTF", renderer, 40, 255, 255, 0);
            renderTexture(Boardheight, renderer, SCREEN_WIDTH/2 , SCREEN_HEIGHT/2 - SCREEN_HEIGHT/4+50);
            renderTexture(Boardwidth, renderer, SCREEN_WIDTH/2 , SCREEN_HEIGHT/2+50);
            renderTexture(Mines, renderer, SCREEN_WIDTH/2 , SCREEN_HEIGHT/2 + SCREEN_HEIGHT/4+50);
            SDL_DestroyTexture(Boardheight);
            SDL_DestroyTexture(Boardwidth);
            SDL_DestroyTexture(Mines);
        }
        RenderTextClickable(Intermediate, IntermediateIn, renderer, SCREEN_WIDTH/4-TextWidth("Intermediate", 50)/2 , SCREEN_HEIGHT/2+50, TextWidth("Intermediate", 50), 50, inIntermediate);
        if(inIntermediate)
        {
            SDL_Texture *Boardheight = LoadTextFont("Board Height : " + std::to_string(INTERMEDIATE_SIDE),  "font//bitmap.TTF", renderer, 40, 255, 255, 0);
            SDL_Texture *Boardwidth = LoadTextFont("Board Width : " + std::to_string(INTERMEDIATE_SIDE),  "font//bitmap.TTF", renderer, 40, 255, 255, 0);
            SDL_Texture *Mines = LoadTextFont("Mines : " + std::to_string(INTERMEDIATE_MINES),  "font//bitmap.TTF", renderer, 40, 255, 255, 0);
            renderTexture(Boardheight, renderer, SCREEN_WIDTH/2 , SCREEN_HEIGHT/2 - SCREEN_HEIGHT/4+50);
            renderTexture(Boardwidth, renderer, SCREEN_WIDTH/2 , SCREEN_HEIGHT/2+50);
            renderTexture(Mines, renderer, SCREEN_WIDTH/2 , SCREEN_HEIGHT/2 + SCREEN_HEIGHT/4+50);
            SDL_DestroyTexture(Boardheight);
            SDL_DestroyTexture(Boardwidth);
            SDL_DestroyTexture(Mines);
        }
        RenderTextClickable(Expert, ExpertIn, renderer, SCREEN_WIDTH/4-TextWidth("Expert", 50)/2 , SCREEN_HEIGHT/2+SCREEN_HEIGHT/4+50, TextWidth("Expert", 50), 50, inExpert);
        if(inExpert)
        {
            SDL_Texture *Boardheight = LoadTextFont("Board Height : " + std::to_string(EXPERT_SIDE),  "font//bitmap.TTF", renderer, 40, 255, 255, 0);
            SDL_Texture *Boardwidth = LoadTextFont("Board Width : " + std::to_string(EXPERT_SIDE),  "font//bitmap.TTF", renderer, 40, 255, 255, 0);
            SDL_Texture *Mines = LoadTextFont("Mines : " + std::to_string(EXPERT_MINES),  "font//bitmap.TTF", renderer, 40, 255, 255, 0);
            renderTexture(Boardheight, renderer, SCREEN_WIDTH/2 , SCREEN_HEIGHT/2 - SCREEN_HEIGHT/4+50);
            renderTexture(Boardwidth, renderer, SCREEN_WIDTH/2 , SCREEN_HEIGHT/2+50);
            renderTexture(Mines, renderer, SCREEN_WIDTH/2 , SCREEN_HEIGHT/2 + SCREEN_HEIGHT/4+50);
            SDL_DestroyTexture(Boardheight);
            SDL_DestroyTexture(Boardwidth);
            SDL_DestroyTexture(Mines);
        }
        SDL_RenderPresent(renderer);
        delaycountbg ++;
        if(delaycountbg == DELAYBG)
        {
            countbg ++;
            delaycountbg = 0;
        }

        SDL_DestroyTexture(Background);


        SDL_Delay(delaytime(timestart, timeframe));

    }
    Mix_HaltMusic();
    SDL_DestroyTexture(Beginner);
    SDL_DestroyTexture(BeginnerIn);
    SDL_DestroyTexture(Intermediate);
    SDL_DestroyTexture(IntermediateIn);
    SDL_DestroyTexture(Expert);
    SDL_DestroyTexture(ExpertIn);
    SDL_DestroyTexture(Choosedifferent);
    SDL_RenderClear(renderer);
    return Info;
}

//xử lý cờ
void PlaceFlag(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width, char &countbomb, int Tile_x, int Tile_y, Mix_Chunk* flag, Mix_Chunk* unflag)
{
    if(!board[Tile_y][Tile_x].isRevealed)
    {
        if(!board[Tile_y][Tile_x].isFlag)
        {
            Mix_PlayChannel (-1, flag, 0);
            board[Tile_y][Tile_x].isFlag = true;
            countbomb--;
            return;
        }
        else
        {
            Mix_PlayChannel (-1, unflag, 0);
            board[Tile_y][Tile_x].isFlag = false;
            countbomb++;
            return;
        }
    }
    return;
}

//rải mìn ngẫu nhiên
void PlaceMine(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width, int Mines)
{
    int m = 0;
    while(m < Mines)
    {
        int x=rand() % Board_Width;
        int y=rand() % Board_Height;
        if (board[y][x].isMine)
            continue;
        else
        {
            board[y][x].isMine=true;
            m++;
        }
    }
    return;
}

//đếm số mìn còn lại
int BombLeft(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width, int Mines)
{
    int countflag = Mines;
    for (int i = 0; i < Board_Height; i++)
    {
        for (int j = 0; j < Board_Width; j++)
        {
            if (board[i][j].isFlag)
            {
                countflag --;
            }
        }
    }
    return countflag;
}

//đếm số mìn xung quang ô
void CountNeighbors(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width)
{
    for (int i = 0; i < Board_Height; i++)
    {
        for (int j = 0; j < Board_Width; j++)
        {
        // If this is mine, skip it
        if (board[i][j].isMine)
        {
            continue;
        }
        int n=0;
        // Calculate all neighbors on 3x3 grid around tile
        for (int y = -1; y <= 1; y++)
        {
            for (int x = -1; x <= 1; x++)
            {
                int xoff=j+x;
                int yoff=i+y;
            // Do not count outside array
                if (xoff < 0 || xoff > Board_Width - 1 || yoff < 0 || yoff > Board_Height - 1)
                    continue;
                if (board[yoff][xoff].isMine)
                    n++;
            }
            // Update neighbor count to the struct
        board[i][j].n=n;
        }
        }
    }
}

//mở ô khi ấn vào ô số 0
void RevealNeighbors(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width, int x, int y)
{
    if(x < 0 || x > Board_Width - 1 || y < 0 || y > Board_Height - 1)
        return;
    if(board[y][x].isRevealed || board[y][x].isFlag)
    {
        return;
    }
    board[y][x].isRevealed = true;
    if(board[y][x].isMine || board[y][x].n != 0)
    {
        return;
    }
    for (int i = -1; i <= 1; i++)
        {
        for (int j = -1; j <= 1; j++)
            {
                int xoff=x+j;
                int yoff=y+i;
                if (xoff<0 || xoff > Board_Width - 1 || yoff < 0 || yoff > Board_Height - 1)
                    continue;
                RevealNeighbors(board, Board_Height, Board_Width, xoff, yoff);
            }
        }
}

//xóa bảng chơi
void ClearBoard(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width)
{
    for (int i = 0; i < Board_Height; i++)
    {
        for (int j = 0; j < Board_Width; j++)
        {
            board[i][j].isRevealed = false;
            board[i][j].isMine = false;
            board[i][j].isFlag = false;
            board[i][j].n = 0;
        }
    }
    return;
}

//làm mới bảng chơi
void MakeNewBoard(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width, int Mines, SDL_Renderer* renderer)
{
    ClearBoard(board, Board_Height, Board_Width);
    PlaceMine(board, Board_Height, Board_Width, Mines);
    CountNeighbors(board, Board_Height, Board_Width);
}

//hàm hiện thị bảng chơi
void ShowBoard(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width, int Mines, char countbomb, int timer, char clicksafe, int button, SDL_Renderer* renderer)
{
    //load texture
    SDL_Texture *img0 = loadTexture("img//0.bmp", renderer);
    SDL_Texture *img1 = loadTexture("img//1.bmp", renderer);
    SDL_Texture *img2 = loadTexture("img//2.bmp", renderer);
    SDL_Texture *img3 = loadTexture("img//3.bmp", renderer);
    SDL_Texture *img4 = loadTexture("img//4.bmp", renderer);
    SDL_Texture *img5 = loadTexture("img//5.bmp", renderer);
    SDL_Texture *img6 = loadTexture("img//6.bmp", renderer);
    SDL_Texture *img7 = loadTexture("img//7.bmp", renderer);
    SDL_Texture *img8 = loadTexture("img//8.bmp", renderer);
    SDL_Texture *imgmine = loadTexture("img//MINE.bmp", renderer);
    SDL_Texture *imgflag = loadTexture("img//FLAG.bmp", renderer);
    SDL_Texture *imgup = loadTexture("img//UP.bmp", renderer);
    SDL_Texture *imgtray = loadTexture("img//TRAY.bmp", renderer);
    SDL_Texture *imgclock = loadTexture("img//CLOCK.bmp", renderer);
    SDL_Texture *gBackground = loadTexture("img//gBackground.BMP", renderer);
    SDL_Texture *textminesleft = LoadNumberFont(countbomb,  "font//bitmap.TTF", renderer, COUNTSIDE, ORANGE_R, ORANGE_G, ORANGE_B);
    SDL_Texture *square = loadTexture("img//REDSQUARE.bmp", renderer);
    SDL_Texture *gtimer = LoadNumberFont(timer,  "font//bitmap.TTF", renderer, COUNTSIDE, ORANGE_R, ORANGE_G, ORANGE_B);
    SDL_Texture *safe = LoadNumberFont(clicksafe,  "font//bitmap.TTF", renderer, COUNTSIDE, ORANGE_R, ORANGE_G, ORANGE_B);
    SDL_Texture *Menu = loadJPGTexture("img//menu.jpg", renderer);

    int x = DEFAULT_X;
    int y = SCREEN_HEIGHT/2 - Board_Height/2*SIDE;

    //vẽ background
    renderTexture(gBackground, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    renderTexture(imgtray, renderer, DEFAULT_X-10, SCREEN_HEIGHT/2 - Board_Height/2*SIDE-10, Board_Width*SIDE+20, Board_Height*SIDE+20);

    //vẽ bảng chơi
    for (int i = 0; i < Board_Height; i++, y += SIDE)
    {
        for (int j = 0; j < Board_Width; j++, x += SIDE)
        {
            if(board[i][j].isFlag)
            {
                renderTexture(imgflag, renderer, x, y, SIDE, SIDE);
                if(board[i][j].MouseIn)
                {
                    renderTexture(square, renderer, x, y, SIDE, SIDE);
                }
            }
            else
            {
                if(!board[i][j].isRevealed)
                {
                    renderTexture(imgup, renderer, x, y, SIDE, SIDE);
                    if(board[i][j].MouseIn)
                    {
                        renderTexture(square, renderer, x, y, SIDE, SIDE);
                    }
                }
                else
                {
                    if(board[i][j].isMine)
                    {
                        renderTexture(imgmine, renderer, x, y, SIDE, SIDE);
                    }
                    else
                    {
                        int neighbor = board[i][j].n;
                        if(neighbor == 0) renderTexture(img0, renderer, x, y, SIDE, SIDE);
                        if(neighbor == 1) renderTexture(img1, renderer, x, y, SIDE, SIDE);
                        if(neighbor == 2) renderTexture(img2, renderer, x, y, SIDE, SIDE);
                        if(neighbor == 3) renderTexture(img3, renderer, x, y, SIDE, SIDE);
                        if(neighbor == 4) renderTexture(img4, renderer, x, y, SIDE, SIDE);
                        if(neighbor == 5) renderTexture(img5, renderer, x, y, SIDE, SIDE);
                        if(neighbor == 6) renderTexture(img6, renderer, x, y, SIDE, SIDE);
                        if(neighbor == 7) renderTexture(img7, renderer, x, y, SIDE, SIDE);
                        if(neighbor == 8) renderTexture(img8, renderer, x, y, SIDE, SIDE);
                    }
                }
            }
        }
        x = DEFAULT_X;
    }
    x = DEFAULT_X;
    y = SCREEN_HEIGHT/2 - Board_Height/2*SIDE;

    //hiển thị số mìn còn lại
    renderTexture(imgtray, renderer, DEFAULT_X-10, DEFAULT_COUNT_Y-10, COUNTSIDE+20, COUNTSIDE+20);
    renderTexture(imgmine, renderer, DEFAULT_X, DEFAULT_COUNT_Y, COUNTSIDE, COUNTSIDE);
    renderTexture(imgtray, renderer, DEFAULT_X-10+COUNTSIDE+20, DEFAULT_COUNT_Y-10, COUNTSIDE*2+10, COUNTSIDE+20);
    renderTexture(textminesleft, renderer, DEFAULT_X+COUNTSIDE+20, DEFAULT_COUNT_Y);

    //hiển thị số lần an toàn
    renderTexture(imgtray, renderer, DEFAULT_X-10, 10, COUNTSIDE+20, COUNTSIDE+20);
    renderTexture(imgflag, renderer, DEFAULT_X, 20, COUNTSIDE, COUNTSIDE);
    renderTexture(imgtray, renderer, DEFAULT_X-10+COUNTSIDE+20, 10, COUNTSIDE+20, COUNTSIDE+20);
    renderTexture(safe, renderer, DEFAULT_X+COUNTSIDE+20, 20);

    //hiển thị đếm giờ
    renderTexture(imgtray, renderer, DEFAULT_X-4*COUNTSIDE-25+EXPERT_SIDE*SIDE, DEFAULT_COUNT_Y-10, COUNTSIDE+20, COUNTSIDE+20);
    renderTexture(imgclock, renderer, DEFAULT_X-4*COUNTSIDE-15+EXPERT_SIDE*SIDE, DEFAULT_COUNT_Y, COUNTSIDE, COUNTSIDE);
    renderTexture(imgtray, renderer, DEFAULT_X-3*COUNTSIDE-5+EXPERT_SIDE*SIDE, DEFAULT_COUNT_Y-10, COUNTSIDE*3+15, COUNTSIDE+20);
    renderTexture(gtimer, renderer, DEFAULT_X-3*COUNTSIDE+5+EXPERT_SIDE*SIDE, DEFAULT_COUNT_Y);

    //hiển thị nút menu
    renderTexture(Menu, renderer, SCREEN_WIDTH - 100 + button, 40 + button, 60 - button*2, 60 - button*2);

    //xoá màn hình
    SDL_RenderPresent(renderer);

    //xóa texture
    SDL_DestroyTexture(img0);
    SDL_DestroyTexture(img1);
    SDL_DestroyTexture(img2);
    SDL_DestroyTexture(img3);
    SDL_DestroyTexture(img4);
    SDL_DestroyTexture(img5);
    SDL_DestroyTexture(img6);
    SDL_DestroyTexture(img7);
    SDL_DestroyTexture(img8);
    SDL_DestroyTexture(imgmine);
    SDL_DestroyTexture(imgflag);
    SDL_DestroyTexture(imgup);
    SDL_DestroyTexture(imgtray);
    SDL_DestroyTexture(gBackground);
    SDL_DestroyTexture(textminesleft);
    SDL_DestroyTexture(square);
    SDL_DestroyTexture(gtimer);
    SDL_DestroyTexture(safe);
    SDL_DestroyTexture(Menu);
    return;
}

//hiển thị số mìn trong bảng chơi
void ShowTrueBoard(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width, char countbomb, int Mines, int timer, char clicksafe, int button, SDL_Renderer* renderer)
{
    for (int i = 0; i < Board_Height; i++)
    {
        for (int j = 0; j < Board_Width; j++)
            {
                if(board[i][j].isMine)
                {
                    board[i][j].isFlag = false;
                    board[i][j].isRevealed = true;
                }
            }
    }
    ShowBoard(board, Board_Height, Board_Width, Mines, countbomb, timer, clicksafe, button, renderer);
}

//hàm giao diện chơi lại
void PlayAgain(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width, int Mines, char countbomb, int timer, char clicksafe, int button, bool &isstarttimer, bool &ingame, bool &turnoff, SDL_Renderer* renderer)
{
    SDL_Texture *Playagain = LoadTextFont("Play Again?",  "font//bitmap.TTF", renderer, 50, ORANGE_R, ORANGE_G, ORANGE_B);
    SDL_Texture *YesIn = LoadTextFont("Yes",  "font//bitmap.TTF", renderer, 30, LIGHTGRAY_RGB, LIGHTGRAY_RGB, LIGHTGRAY_RGB);
    SDL_Texture *Yes = LoadTextFont("Yes",  "font//bitmap.TTF", renderer, 30, ORANGE_R, ORANGE_G, ORANGE_B);
    SDL_Texture *NoIn = LoadTextFont("No",  "font//bitmap.TTF", renderer, 30, LIGHTGRAY_RGB, LIGHTGRAY_RGB, LIGHTGRAY_RGB);
    SDL_Texture *No = LoadTextFont("No",  "font//bitmap.TTF", renderer, 30, ORANGE_R, ORANGE_G, ORANGE_B);

    SDL_Event e;

    int timestart;
    int timeframe = 1000/FPS;
    bool inYes = false;
    bool inNo = false;

    renderTexture(Playagain, renderer, SCREEN_WIDTH/2+SCREEN_WIDTH/4-TextWidth("Play Again?", 50)/2 , SCREEN_HEIGHT/2-SCREEN_HEIGHT/16, TextWidth("Play Again?", 50), 50);


    while (!turnoff)
    {
        timestart = SDL_GetTicks();
        if(SDL_PollEvent( &e ) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                turnoff = true;
                break;
            }

            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
            {
                turnoff = true;
                break;
            }
            if(ClickText(SCREEN_WIDTH/2+SCREEN_WIDTH/4-TextWidth("Play Again?", 50)/4-TextWidth("Yes", 30)/2 , SCREEN_HEIGHT/2+SCREEN_HEIGHT/16, TextWidth("Yes", 30), 30, e))
            {
                ingame = true;
                isstarttimer = true;
                MakeNewBoard(board, Board_Height, Board_Width, Mines, renderer);
                SDL_RenderClear(renderer);
                ShowBoard(board, Board_Height, Board_Width, Mines, countbomb, timer, clicksafe, button, renderer);
                break;
            }
            if(ClickText(SCREEN_WIDTH/2+SCREEN_WIDTH/4+TextWidth("Play Again?", 50)/4-TextWidth("No", 30)/2 , SCREEN_HEIGHT/2+SCREEN_HEIGHT/16, TextWidth("No", 30), 30, e))
            {
                ingame = false;
                isstarttimer = true;
                SDL_RenderClear(renderer);
                break;
            }
            ChooseTextClickable(SCREEN_WIDTH/2+SCREEN_WIDTH/4-TextWidth("Play Again?", 50)/4-TextWidth("Yes", 30)/2 , SCREEN_HEIGHT/2+SCREEN_HEIGHT/16, TextWidth("Yes", 30), 30, inYes, e);
            ChooseTextClickable(SCREEN_WIDTH/2+SCREEN_WIDTH/4+TextWidth("Play Again?", 50)/4-TextWidth("No", 30)/2 , SCREEN_HEIGHT/2+SCREEN_HEIGHT/16, TextWidth("No", 30), 30, inNo, e);
        }

        RenderTextClickable(Yes, YesIn, renderer, SCREEN_WIDTH/2+SCREEN_WIDTH/4-TextWidth("Play Again?", 50)/4-TextWidth("Yes", 30)/2 , SCREEN_HEIGHT/2+SCREEN_HEIGHT/16, TextWidth("Yes", 30), 30, inYes);
        RenderTextClickable(No, NoIn, renderer, SCREEN_WIDTH/2+SCREEN_WIDTH/4+TextWidth("Play Again?", 50)/4-TextWidth("No", 30)/2 , SCREEN_HEIGHT/2+SCREEN_HEIGHT/16, TextWidth("No", 30), 30, inNo);

        SDL_RenderPresent(renderer);
        SDL_Delay(delaytime(timestart, timeframe));

    }
    SDL_DestroyTexture(Playagain);
    SDL_DestroyTexture(YesIn);
    SDL_DestroyTexture(Yes);
    SDL_DestroyTexture(NoIn);
    SDL_DestroyTexture(No);

    return;
}

//kiểm tra nếu thắng
bool IsWin(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width, int Mines)
{
    int count = 0;
    for (int i = 0; i < Board_Height; i++)
    {
        for (int j = 0; j < Board_Width; j++)
        {
            if(board[i][j].isRevealed && !board[i][j].isMine)
                count ++;
        }
    }
    return count == Board_Height*Board_Width - Mines;
}


//kiểm tra nếu thua
bool IsLose (Tile board[][MAX_WIDTH], int Board_Height, int Board_Width, int timer)
{
    for (int i = 0; i < Board_Height; i++)
    {
        for (int j = 0; j < Board_Width; j++)
        {
            if(board[i][j].isRevealed && board[i][j].isMine)
                return true;
        }
    }
    if(timer <= 0) return true;
    return false;
}


//kiểm tra nếu kết thúc
void CheckWinOrLose(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width, int Mines, char &countbomb, int timer, float MultiplyScore, bool &isstarttimer, bool &ingame, bool &turnoff, char &clicksafe, int button,SDL_Renderer* renderer)
{
    if(IsWin(board, Board_Height, Board_Width, Mines))
    {
        SDL_Texture *YouWin = LoadTextFont("You Win!",  "font//bitmap.TTF", renderer, 50, 0, 255    , 0);

        int scorepoint = timer * MultiplyScore;
        string strscore = "Score : " + std::to_string(scorepoint + clicksafe*200);
        SDL_Texture *score = LoadTextFont(strscore,  "font//bitmap.TTF", renderer, COUNTSIDE, ORANGE_R, ORANGE_G, ORANGE_B);


        Mix_Chunk* win_soundeffect = Mix_LoadWAV("Sound//win_soundeffect.wav");
        if (win_soundeffect == NULL)
        {
            printf("%s", Mix_GetError());
            turnoff = true;
        }

        Mix_HaltMusic();
        Mix_PlayChannel (-1, win_soundeffect, -1);

        ShowTrueBoard(board, Board_Height, Board_Width, Mines, countbomb, timer, clicksafe, button,renderer);
        renderTexture(YouWin, renderer, SCREEN_WIDTH/2+SCREEN_WIDTH/4-TextWidth("You Win!", 50)/2 , SCREEN_HEIGHT/2-SCREEN_HEIGHT/4, TextWidth("You Win!", 50), 50);
        renderTexture(score, renderer, SCREEN_WIDTH/2+SCREEN_WIDTH/4-TextWidth(strscore, 40)/2 , SCREEN_HEIGHT/2+SCREEN_HEIGHT/4, TextWidth(strscore, 40), 40);
        PlayAgain(board, Board_Height, Board_Width, Mines, countbomb, timer, clicksafe, button, isstarttimer, ingame, turnoff, renderer);

        countbomb = Mines;
        clicksafe = SAFEMINE;

        Mix_HaltChannel(-1);

        SDL_DestroyTexture(score);
        SDL_DestroyTexture(YouWin);
        Mix_FreeChunk(win_soundeffect);
    }
    else
    {
        if(IsLose(board, Board_Height, Board_Width, timer))
        {
            SDL_Texture *YouLose = LoadTextFont("You Lose!",  "font//bitmap.TTF", renderer, 50, 255, 0, 0);
            Mix_Chunk* lose_soundeffect = Mix_LoadWAV("Sound//lose_soundeffect.wav");
            if (lose_soundeffect == NULL)
            {
                printf("%s", Mix_GetError());
                turnoff = true;
            }


            Mix_HaltMusic();
            Mix_PlayChannel (-1, lose_soundeffect, -1);

            ShowTrueBoard(board, Board_Height, Board_Width, Mines, countbomb, timer, clicksafe, button,renderer);

            if(timer <=0)
            {
                SDL_Texture *TimeOver = LoadTextFont("Time Over",  "font//bitmap.TTF", renderer, 50, 0, 0, 0);
                renderTexture(TimeOver, renderer, SCREEN_WIDTH/2+SCREEN_WIDTH/4-TextWidth("Time Over", 50)/2 , SCREEN_HEIGHT/2-SCREEN_HEIGHT/6, TextWidth("Time Over", 50), 50);
                SDL_DestroyTexture(TimeOver);
            }
            renderTexture(YouLose, renderer, SCREEN_WIDTH/2+SCREEN_WIDTH/4-TextWidth("You Lose!", 50)/2 , SCREEN_HEIGHT/2-SCREEN_HEIGHT/4, TextWidth("You Lose!", 50), 50);
            PlayAgain(board, Board_Height, Board_Width, Mines, countbomb, timer, clicksafe, button, isstarttimer, ingame, turnoff, renderer);

            countbomb = Mines;
            clicksafe = SAFEMINE;

            Mix_HaltChannel(-1);

            SDL_DestroyTexture(YouLose);
            Mix_FreeChunk(lose_soundeffect);
        }
    }
}

//xóa chuột
void MouseClear(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width)
{
    for (int i = 0; i < Board_Height; i++)
    {
        for (int j = 0; j < Board_Width; j++)
        {
            if(board[i][j].MouseIn)
                board[i][j].MouseIn = false;
        }
    }
    return;
}

//xử lí chuột
void MouseInGame(Tile board[][MAX_WIDTH], int Board_Height, int Board_Width, char &countbomb, int &button, bool &ingame, bool &turnoff, char &clicksafe, Mix_Chunk* flag, Mix_Chunk* unflag, Mix_Chunk* click, Mix_Chunk* wrong)
{
    SDL_Event e;
    if( SDL_PollEvent( &e ) != 0 )
    {
        if (e.type == SDL_QUIT)
        {
            turnoff = true;
        }

        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
        {
            turnoff = true;
        }
        if(turnoff) return;
        int default_y = SCREEN_HEIGHT/2 - Board_Height/2*SIDE;
        int mouse_x = e.button.x - DEFAULT_X;
        int mouse_y = e.button.y - default_y;
        int Tile_y = mouse_y/SIDE;
        int Tile_x = mouse_x/SIDE;
        MouseClear(board, Board_Height, Board_Width);
        if( Tile_x >= 0 && Tile_x < Board_Width && Tile_y >= 0 && Tile_y < Board_Height)
        {
            board[Tile_y][Tile_x].MouseIn = true;
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                if (e.button.button == SDL_BUTTON_LEFT && !board[Tile_y][Tile_x].isFlag)
                {
                    if(!board[Tile_y][Tile_x].isRevealed)
                    {
                        if(board[Tile_y][Tile_x].isMine)
                        {
                            Mix_PlayChannel (-1, wrong, 0);
                            board[Tile_y][Tile_x].isFlag = true;
                            clicksafe--;
                            countbomb--;
                            if(clicksafe < 0)
                            {
                                board[Tile_y][Tile_x].isRevealed = true;
                                clicksafe = 0;
                            }
                        }
                        else
                        {
                            Mix_PlayChannel (-1, click, 0);
                            if(board[Tile_y][Tile_x].n == 0 && !board[Tile_y][Tile_x].isMine)
                            {
                                RevealNeighbors(board, Board_Height, Board_Width, Tile_x, Tile_y);

                            }
                            else
                            {
                                board[Tile_y][Tile_x].isRevealed = true;
                            }
                        }
                    }
                }
                if (e.button.button == SDL_BUTTON_RIGHT)
                {
                    PlaceFlag(board, Board_Height, Board_Width, countbomb, Tile_x, Tile_y, flag, unflag);
                }

            }
        }
    if(e.button.x < SCREEN_WIDTH - 40 && e.button.x > SCREEN_WIDTH - 100 && e.button.y > 40 && e.button.y < 100)
        {
            if(button < 10)
                button ++ ;
            if(e.button.button == SDL_BUTTON_LEFT)
                ingame = false;
        }
    else
        if(e.button.x > SCREEN_WIDTH - 40 || e.button.x < SCREEN_WIDTH - 100 || e.button.y < 40 || e.button.y > 100)
            if(button > 0)
                button --;
    }
    return;
}

//đếm thời gian
int CountTime(bool &isstarttimer, int &starttime)
{
    if(isstarttimer)
    {
        starttime = SDL_GetTicks();
        isstarttimer = false;
    }
    return (SDL_GetTicks() - starttime) / 1000;
}

//chơi game
void PlayMineSweeper(bool &turnoff, SDL_Renderer* renderer, BoardInfo Info)
{
    //lấy thông tin màn chơi
    int Board_Width = Info.Board_Width;
    int Board_Height = Info.Board_Height;
    int Mines = Info.Mines;
    float MultiplyScore = Info.MultiplyScore;

    Tile board[MAX_HEIGHT][MAX_WIDTH];

    bool ingame = true;
    bool isstarttimer = true;

    int ctimer;//thời gian bắt đầu s
    int timer;//thời gian còn lại
    int starttime;//thời gian bắt đầu ms
    char clicksafe = SAFEMINE;//số lần an toàn còn lại
    char countbomb = Mines;//đếm số mìn còn lại
    int button = 0;//nút

    //Sound effect
    Mix_Chunk* flag = Mix_LoadWAV("Sound//flag.wav");
    Mix_Chunk* unflag = Mix_LoadWAV("Sound//unflag.wav");
    Mix_Chunk* click = Mix_LoadWAV("Sound//click.wav");
    Mix_Chunk* wrong = Mix_LoadWAV("Sound//wrong.wav");


	//Background Music
	Mix_Music* gmusic = NULL;

	//Load Music
	gmusic = Mix_LoadMUS("Sound//backgroundgame_music.wav");
	if (gmusic == NULL)
	{
		printf("%s", Mix_GetError());
		turnoff = true;
	}

	//làm màn chơi mới
    MakeNewBoard(board, Board_Height, Board_Width, Mines, renderer);

    while (ingame && !turnoff)
    {
        //bắt đầu đếm giờ
        ctimer = CountTime(isstarttimer, starttime);
        timer = TIMELIMIT - ctimer;

        //mở nhạc
        if (!Mix_PlayingMusic())
            Mix_PlayMusic(gmusic, -1);

        //xử lí chuột
        MouseInGame(board, Board_Height, Board_Width, countbomb, button, ingame, turnoff, clicksafe, flag, unflag, click, wrong);

        //hiển thị bảng chơi
        ShowBoard(board, Board_Height, Board_Width, Mines, countbomb, timer, clicksafe, button, renderer);

        //kiểm tra kết thúc
        CheckWinOrLose(board, Board_Height, Board_Width, Mines, countbomb, timer, MultiplyScore, isstarttimer, ingame, turnoff, clicksafe, button, renderer);
    }
    //xóa âm thanh
    Mix_FreeMusic(gmusic);
    Mix_FreeChunk(click);
    Mix_FreeChunk(flag);
    Mix_FreeChunk(unflag);
    Mix_FreeChunk(wrong);
    //Xoá màn hình
    SDL_RenderClear(renderer);

    return;
}


