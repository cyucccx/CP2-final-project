#include "include.h"

SDL_Window* window;
SDL_Renderer* screen;

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

int SDL_no_choice_one_character(char *background_image, char *character_image, char *character_message, char *character_name)
{
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("simfang.ttf", 40);
    if(font==NULL)
    {
        printf("can not found %s\n",TTF_GetError());
        return 0;
    }
    SDL_Surface *image,*player,*talk,*button,*blank;
    SDL_Surface *message=NULL;
    SDL_Surface *name=NULL;
    
    SDL_Color textColor={ 255, 0, 0 };
    image = IMG_Load(background_image);
    player = IMG_Load(character_image);
    talk = IMG_Load("talk.png");
    button = IMG_Load("button.png");
    blank = IMG_Load("blank.png");
    
    Player play,background,talking,butt;
    SDL_Rect a,b,c,d;
    b.x = 0;
    b.y = 0;
    b.h = 600;
    b.w = 800;
    
    play.x = 0;
    play.y = 0;
    play.height = 600;
    play.width = 800;
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
    create_player(play,screen,player,b);
    create_player(talking,screen,talk,b);
    create_player(butt,screen,button,b);
    create_player(butt,screen,blank,b);
    
    message=TTF_RenderUTF8_Solid( font,character_message, textColor );
    name=TTF_RenderUTF8_Solid( font,character_name, textColor );
    
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(screen, message);
    SDL_Texture* textTexture_name = SDL_CreateTextureFromSurface(screen, name);
    SDL_Rect textRect;
    textRect.x = 63;
    textRect.y = 453;
    textRect.w = message->w/2;
    textRect.h = message->h/2;
    SDL_Rect textRect_name;
    textRect_name.x = 85;
    textRect_name.y = 416;
    textRect_name.w = message->w/2;
    textRect_name.h = message->h/2;
    
    SDL_RenderCopy(screen, textTexture, NULL, &textRect);
    SDL_RenderCopy(screen, textTexture_name, NULL, &textRect_name);
    
    
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
        
        SDL_Quit();
        TTF_Quit();
        return quit;
    }
    else if(quit == 3)
    {
        TTF_Quit();
        return quit;
    }
}

int SDL_choice_one_character(char *background_image, char *character_image,char *sellect_button_message_up,char *sellect_button_message_middle,char *sellect_button_message_down)
{
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("simfang.ttf", 50);
    if(font==NULL)
    {
        printf("can not found %s\n",TTF_GetError());
        return 0;
    }
    SDL_Surface *image,*player,*talk,*button,*blank,*sellect_button;
    SDL_Surface *message_up=NULL;
    SDL_Surface *message_middle=NULL;
    SDL_Surface *message_down=NULL;
    
    SDL_Color textColor={ 255, 0, 0 };
    image = IMG_Load(background_image);
    player = IMG_Load(character_image);
    talk = IMG_Load("talk.png");
    button = IMG_Load("button.png");
    blank = IMG_Load("blank.png");
    sellect_button = IMG_Load("select_button.png");
    
    Player play,background,talking,butt;
    SDL_Rect a,b,c,d;
    
    b.x = 0;
    b.y = 0;
    b.h = 600;
    b.w = 800;
    
    play.x = 0;
    play.y = 0;
    play.height = 600;
    play.width = 800;
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
    create_player(play,screen,player,b);
    create_player(talking,screen,talk,b);
    create_player(butt,screen,button,b);
    create_player(butt,screen,blank,b);
    create_player(butt,screen,sellect_button,b);

    message_up=TTF_RenderUTF8_Solid( font,sellect_button_message_up, textColor );
    message_middle=TTF_RenderUTF8_Solid( font,sellect_button_message_middle, textColor );
    message_down=TTF_RenderUTF8_Solid( font,sellect_button_message_down, textColor );
    
    SDL_Texture* textTexture_up = SDL_CreateTextureFromSurface(screen, message_up);
    SDL_Texture* textTexture_middle = SDL_CreateTextureFromSurface(screen, message_middle);
    SDL_Texture* textTexture_down = SDL_CreateTextureFromSurface(screen, message_down);
    SDL_Rect textRect;
    textRect.x = 155;
    textRect.y = 160;
    textRect.w = message_up->w/2;
    textRect.h = message_up->h/2;
    SDL_Rect textRect2;
    textRect2.x = 155;
    textRect2.y = 229;
    textRect2.w = message_middle->w/2;
    textRect2.h = message_middle->h/2;
    SDL_Rect textRect3;
    textRect3.x = 155;
    textRect3.y = 297;
    textRect3.w = message_down->w/2;
    textRect3.h = message_down->h/2;
    
    SDL_RenderCopy(screen, textTexture_up, NULL, &textRect);
    SDL_RenderCopy(screen, textTexture_middle, NULL, &textRect2);
    SDL_RenderCopy(screen, textTexture_down, NULL, &textRect3);
    
    
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
                        else if(x>=155&&x<=155+490&&y>=161&&y<=161+32)
                        quit = 2;
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
        TTF_Quit();
        return quit;
    }
    else if(quit==2)
    {
        TTF_Quit();
        return quit;
    }
    else if(quit == 3)
    {
        TTF_Quit();
        return quit;
    }
}

void allocate(sScene *input){
    input->name = calloc(500, sizeof(sScene));
    input->background = calloc(500, sizeof(sScene));
    input->backpack_icon = calloc(500, sizeof(sScene));
    input->character_number = 0;
    input->dialogue = 0;
    input->reply = 0;
    input->backpack = 0;
}
// int main(int argc, char* args[]) 
// {
//     char *in="test.png";
//     char *in2="chi.png";
//     char *in3="嗨!!我是CHI";
//     char *in4="嗨!!我是LU";
//     char *in5="嗨!!我是SDMH";
//     char *in6="大仙chang";
//     int i;
//     window = SDL_CreateWindow( "fin_project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN );
//     screen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
//     i = SDL_no_choice_one_character(in,in2,in3,in6);
//     if(i==1)
//     {
//         SDL_DestroyRenderer(screen);
//         SDL_DestroyWindow(window);
//         SDL_Quit();
//         return 0;
//     }
//     else
//     {
//         i = SDL_choice_one_character(in,in2,in3,in4,in5);
//     }
//     // i=SDL_no_choice_one_character(in,in2);
//     // if(i==1)
//     // {
//     //     SDL_DestroyRenderer(screen);
//     //     SDL_DestroyWindow(window);
//     //     SDL_Quit();
//     //     return 0;
//     // }
//     // i=SDL_no_choice_one_character(in,in2);
//     // if(i==1)
//     // {
//     //     SDL_DestroyRenderer(screen);
//     //     SDL_DestroyWindow(window);
//     //     SDL_Quit();
//     //     return 0;
//     // }
//     // i=SDL_no_choice_one_character(in,in2);
//     // if(i==1)
//     // {
//     //     SDL_DestroyRenderer(screen);
//     //     SDL_DestroyWindow(window);
//     //     SDL_Quit();
//     //     return 0;
//     // }
//     // i=SDL_no_choice_one_character(in,in2);
//     // if(i==1)
//     // {
//     //     SDL_DestroyRenderer(screen);
//     //     SDL_DestroyWindow(window);
//     //     SDL_Quit();
//     //     return 0;
//     // }
//     // i=SDL_no_choice_one_character(in,in2);
//     // if(i==1)
//     // {
//     //     SDL_DestroyRenderer(screen);
//     //     SDL_DestroyWindow(window);
//     //     SDL_Quit();
//     //     return 0;
//     // }
//     // i=SDL_no_choice_one_character(in,in2);
//     // if(i==1)
//     // {
//     //     SDL_DestroyRenderer(screen);
//     //     SDL_DestroyWindow(window);
//     //     SDL_Quit();
//     //     return 0;
//     // }
// }
