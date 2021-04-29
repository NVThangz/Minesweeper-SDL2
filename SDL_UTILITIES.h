#ifndef SDL_UTILITIES_H_INCLUDED
#define SDL_UTILITIES_H_INCLUDED

#include <iostream>
//#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <string>
#include <time.h>

using namespace std;

#define FPS 60

#define DEFAULT_TEXT_X 25
#define DEFAULT_TEXT_Y 25
#define LIGHTGRAY_RGB 211
#define ORANGE_R 255
#define ORANGE_G 165
#define ORANGE_B 0


//**************************************************************
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const string WINDOW_TITLE = "Minesweeper";

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal = false);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
/** \brief
 *
 * \return void
 *
 */
void waitUntilKeyPressed();
void ChooseTextClickable(int x, int y, int w, int h, bool &In, SDL_Event &e);
void RenderTextClickable(SDL_Texture* Text, SDL_Texture* TextIn, SDL_Renderer* renderer, int x, int y, int w, int h, bool In);
bool ClickText(int x, int y, int w, int h, SDL_Event &e);

//**************************************************************

// Hai hàm về texture, lấy nguyên về từtutorial tại:
// http://www.willusher.io/sdl2%20tutorials/2013/08/17/lesson-2-dont-put-everything-in-main

// Hàm nạp texture từ file ảnh, để vẽ lên renderer tương ứng
SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren);

// Hàm đưa texture ra renderer (để hiển thị ra màn hình) tại toạ độ (x,y) và giữ nguyên kích cỡ ban đầu của ảnh
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y);

// Hàm (cùng trên nhưng khác tham số với hàm ngay trên)
// đưa texture ra renderer (để hiển thị ra màn hình) tại toạ độ (x,y) và
// với kích cỡ rộng (w) và cao (h) cho trước.
// Ảnh sẽ được co dãn (phóng to thu nhỏ) cho khớp kích cỡ này.
// Đây là hàm không có trong tutorial ban đầu, được sửa từ hàm trong tutorial.
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);

SDL_Texture* loadJPGTexture(const std::string &file, SDL_Renderer *renderer);

SDL_Texture* LoadTextFont(std::string text, const std::string &font, SDL_Renderer *ren, int size, int red, int green, int blue);

SDL_Texture* LoadNumberFont(int Number, const std::string &pathfont, SDL_Renderer *ren, int size, int red, int green, int blue);

int TextWidth(string text, int size);

int delaytime(int timestart, int timeframe);


#endif // SDL_UTILITIES_H_INCLUDED

