#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Window* window=NULL;
SDL_Renderer* screen=NULL;
typedef struct
{
    double x,y;
    int width,height;
    SDL_Texture *texture;
}Player;

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
    SDL_DestroyTexture(play.texture);
}

int SDL_no_choice_one_character(char *background_image,char *character_image)
{
    

    SDL_Surface *image,*player,*talk,*button,*blank;
    image = IMG_Load(background_image);
    player = IMG_Load(character_image);
    talk = IMG_Load("talk.png");
    button = IMG_Load("button.png");
    blank = IMG_Load("blank.png");

    Player play,background,talking,butt;
    SDL_Rect a,b,c,d;
    a.x = 0;
    a.y = 0;
    a.h = 1300;
    a.w = 570;
    b.x = 0;
    b.y = 0;
    b.h = 600;
    b.w = 800;
    c.x = 0;
    c.y = 0;
    c.h = 139;
    c.w = 749;
    d.x = 0;
    d.y = 0;
    d.h = 41;
    d.w = 91;
    
    play.x = 150;
    play.y = 200;
    play.height = 800;
    play.width = 500;
    background.x = 0;
    background.y = 0;
    background.height = 600;
    background.width = 800;
    talking.x = 0;
    talking.y = 0;
    talking.height = 600;
    talking.width = 800;
    butt.x = 0;
    butt.y = 0;
    butt.height = 600;
    butt.width = 800;
    create_player(background,screen,image,b);
    create_player(play,screen,player,a);
    create_player(talking,screen,talk,b);
    create_player(butt,screen,button,b);
    create_player(butt,screen,blank,b);
    
    
    
    SDL_RenderPresent(screen);
    SDL_FlushEvents(SDL_FIRSTEVENT,SDL_LASTEVENT);
    int quit = 0;
    while (!quit)
    {
        SDL_Event event;
        int x,y;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    quit = 1;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if(event.button.button == SDL_BUTTON_LEFT)
                    {
                        x=event.button.x;
                        y=event.button.y;
                        if(x>=444&&x<=444+64&&y>=415&&y<=444+32)
                        quit = 3;
                    }
                    break;
                default:
                    break;
            }
        }
    }
    if(quit == 1)
    {
        SDL_DestroyRenderer(screen);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    else if(quit == 3)
    {
        return quit;
    }

    
}

int main(int argc, char* args[]) 
{
    char *in="test.png";
    char *in2="girl_one.png";
    int i;
    window = SDL_CreateWindow( "fin_project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN );
    screen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    printf("%d ",i);
    i = SDL_no_choice_one_character(in,in2);
    if(i==1)
    {
        SDL_DestroyRenderer(screen);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    printf("%d ",i);
    i=SDL_no_choice_one_character(in,in2);
    printf("%d ",i);
    i=SDL_no_choice_one_character(in,in2);
    printf("%d ",i);
    i=SDL_no_choice_one_character(in,in2);
    printf("%d ",i);
    i=SDL_no_choice_one_character(in,in2);
    printf("%d ",i);
    i=SDL_no_choice_one_character(in,in2);
    printf("%d ",i);
    i=SDL_no_choice_one_character(in,in2);
    printf("%d ",i);
}
