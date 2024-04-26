#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct
{
    double x,y;
    int width,height;
    SDL_Texture *texture;
}Player;//角色

void create_player(Player play, SDL_Renderer *render, SDL_Surface *image, SDL_Rect a)
{
    play.texture = SDL_CreateTextureFromSurface(render,image);
    SDL_Rect s,d;
    s.x = 0;
    s.y = 0;
    s.h = a.h;
    s.y = a.y;

    d.x = play.x;
    d.y = play.y;
    d.w = play.width;
    d.h = play.height;
    SDL_RenderCopyEx(render,play.texture,&s,&d,0,0,SDL_FLIP_NONE);
}//圖片呈現


int main(int argc, char* args[]) 
{
    SDL_Window* window=NULL;
    SDL_Renderer* screen=NULL;
    window = SDL_CreateWindow( "fin_project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN );//初始化
    screen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);//初始化

    
    SDL_SetRenderDrawColor(screen,0,255,0,255);
    SDL_RenderClear(screen);
    SDL_RenderPresent(screen);

    SDL_Surface *image,*player,*talk;//各種圖片
    image = IMG_Load("test.png");
    player = IMG_Load("girl_one.png");
    talk = IMG_Load("talk.png");

    Player play,background,talking;
    SDL_Rect a,b,c;
    a.x = 0;
    a.y = 0;
    a.h = 1300;
    a.w = 570;
    b.x = 0;
    b.y = 0;
    b.h = 600;
    b.w = 800;
    
    play.x = 150;
    play.y = 200;
    play.height = 800;
    play.width = 500;
    background.x = 0;
    background.y = 0;
    background.height = 600;
    background.width = 800;
    talking.x = 0;
    talking.y = 400;
    talking.height = 200;
    talking.width = 800;
    create_player(background,screen,image,b);
    create_player(play,screen,player,a);
    create_player(talking,screen,talk,b);
    
    
    
    SDL_RenderPresent(screen);

    int quit = 0;
    while (!quit)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    quit = 1;
                    break;
                default:
                    break;
            }
        }
        
    }
    SDL_DestroyRenderer(screen);
    SDL_DestroyWindow(window);
    SDL_Quit();
 
    return 0;
}
