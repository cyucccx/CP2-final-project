#include "include.h"

SDL_Window* window;
SDL_Renderer* screen;
// char *in7="backpack.png";
// char *in8="laptop.png";
// char *in9="note.png";
// char *in10="ticket.png";

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

int backpack(char *background_image, char *laptop_image,char *note_image, char *ticket_image,char *laptop_message,char *note_message,char *ticket_message,char *laptop_name,char *note_name,char *ticket_name)
{
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("simfang.ttf", 50);
    if(font==NULL)
    {
        printf("can not found %s\n",TTF_GetError());
        return 0;
    }
    SDL_Surface *image,*laptop,*note,*ticket;
    SDL_Color textColor={ 0, 0, 0 };
    SDL_Color messageColor={ 28, 56, 121 };
    image = IMG_Load(background_image);
    if(laptop_image!=NULL)
    laptop = IMG_Load(laptop_image);
    if(note_image!=NULL)
    note = IMG_Load(note_image);
    if(ticket_image!=NULL)
    ticket = IMG_Load(ticket_image);
    Player background,laptopp,notee,tickett;
    background.x = 0;
    background.y = 0;
    background.height = 600;
    background.width = 800;
    laptopp.x = 0;
    laptopp.y = 0;
    laptopp.height = 600;
    laptopp.width = 800;
    notee.x = 0;
    notee.y = 0;
    notee.height = 600;
    notee.width = 800;
    tickett.x = 0;
    tickett.y = 0;
    tickett.height = 600;
    tickett.width = 800;
    SDL_Rect b;
    b.x = 0;
    b.y = 0;
    b.h = 600;
    b.w = 800;
    SDL_RenderClear(screen);
    create_player(background,screen,image,b);
    create_player(laptopp,screen,laptop,b);
    create_player(notee,screen,note,b);
    create_player(tickett,screen,ticket,b);

    SDL_Surface *message=NULL;
    SDL_Surface *name=NULL;
    message=TTF_RenderUTF8_Solid( font,laptop_message, messageColor );
    name=TTF_RenderUTF8_Solid( font,laptop_name, textColor );
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(screen, message);
    SDL_Texture* textTexture_name = SDL_CreateTextureFromSurface(screen, name);
    SDL_Rect textRect;
    textRect.x = 105;
    textRect.y = 343;
    textRect.w = message->w/2;
    textRect.h = message->h/2;
    SDL_Rect textRect_name;
    textRect_name.x = 105;
    textRect_name.y = 286;
    textRect_name.w = name->w/2;
    textRect_name.h = name->h/2;

    SDL_Surface *message2=NULL;
    SDL_Surface *name2=NULL;
    message2=TTF_RenderUTF8_Solid( font,note_message, messageColor );
    name2=TTF_RenderUTF8_Solid( font,note_name, textColor );
    SDL_Texture* textTexture2 = SDL_CreateTextureFromSurface(screen, message2);
    SDL_Texture* textTexture_name2 = SDL_CreateTextureFromSurface(screen, name2);
    SDL_Rect textRect2;
    textRect2.x = 105;
    textRect2.y = 343;
    textRect2.w = message2->w/2;
    textRect2.h = message2->h/2;
    SDL_Rect textRect_name2;
    textRect_name2.x = 105;
    textRect_name2.y = 286;
    textRect_name2.w = name2->w/2;
    textRect_name2.h = name2->h/2;

    SDL_Surface *message3=NULL;
    SDL_Surface *name3=NULL;
    message3=TTF_RenderUTF8_Solid( font,ticket_message, messageColor );
    name3=TTF_RenderUTF8_Solid( font,ticket_name, textColor );
    SDL_Texture* textTexture3 = SDL_CreateTextureFromSurface(screen, message3);
    SDL_Texture* textTexture_name3 = SDL_CreateTextureFromSurface(screen, name3);
    SDL_Rect textRect3;
    textRect3.x = 105;
    textRect3.y = 343;
    textRect3.w = message3->w/2;
    textRect3.h = message3->h/2;
    SDL_Rect textRect_name3;
    textRect_name3.x = 105;
    textRect_name3.y = 286;
    textRect_name3.w = name3->w/2;
    textRect_name3.h = name3->h/2;
    SDL_RenderPresent(screen);
    SDL_FlushEvents(SDL_FIRSTEVENT,SDL_LASTEVENT);
    int quit = 0;
    int press = 0;
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
                case SDL_MOUSEMOTION:
                    x=event.motion.x;
                    y=event.motion.y;
                    if(x>115&&x<225&&y>145&&y<240)
                    {
                        if(press == 2 || press == 3)
                        {
                            create_player(background,screen,image,b);
                        }
                        SDL_Surface *button1;
                        button1 = IMG_Load("select1.png");
                        Player button_1;
                        button_1.x = 0;
                        button_1.y = 0;
                        button_1.height = 600;
                        button_1.width = 800;
                        create_player(button_1,screen,button1,b);
                        create_player(laptopp,screen,laptop,b);
                        create_player(notee,screen,note,b);
                        create_player(tickett,screen,ticket,b);
                        SDL_RenderPresent(screen);
                    }
                    else if(x>345&&x<450&&y>145&&y<240)
                    {
                        if(press == 1 || press == 3)
                        {
                            create_player(background,screen,image,b);
                        }
                        SDL_Surface *button1;
                        button1 = IMG_Load("select2.png");
                        Player button_1;
                        button_1.x = 0;
                        button_1.y = 0;
                        button_1.height = 600;
                        button_1.width = 800;
                        create_player(button_1,screen,button1,b);
                        create_player(laptopp,screen,laptop,b);
                        create_player(notee,screen,note,b);
                        create_player(tickett,screen,ticket,b);
                        SDL_RenderPresent(screen);
                    }
                    else if(x>575&&x<680&&y>145&&y<240)
                    {
                        if(press == 1 || press == 2)
                        {
                            create_player(background,screen,image,b);
                        }
                        SDL_Surface *button1;
                        button1 = IMG_Load("select3.png");
                        Player button_1;
                        button_1.x = 0;
                        button_1.y = 0;
                        button_1.height = 600;
                        button_1.width = 800;
                        create_player(button_1,screen,button1,b);
                        create_player(laptopp,screen,laptop,b);
                        create_player(notee,screen,note,b);
                        create_player(tickett,screen,ticket,b);
                        SDL_RenderPresent(screen);
                    }
                    else
                    {
                        create_player(background,screen,image,b);
                        create_player(laptopp,screen,laptop,b);
                        create_player(notee,screen,note,b);
                        create_player(tickett,screen,ticket,b);
                        if(press == 1)
                        {
                            SDL_RenderCopy(screen, textTexture, NULL, &textRect);
                            SDL_RenderCopy(screen, textTexture_name, NULL, &textRect_name);
                        }
                        else if(press == 2)
                        {
                            SDL_RenderCopy(screen, textTexture2, NULL, &textRect2);
                            SDL_RenderCopy(screen, textTexture_name2, NULL, &textRect_name2);
                        }
                        else if(press == 3)
                        {
                            SDL_RenderCopy(screen, textTexture3, NULL, &textRect3);
                            SDL_RenderCopy(screen, textTexture_name3, NULL, &textRect_name3);
                        }
                        SDL_RenderPresent(screen);
                    }
                case SDL_MOUSEBUTTONDOWN:
                    if(event.button.button == SDL_BUTTON_LEFT)
                    {
                        x=event.button.x;
                        y=event.button.y;
                        if(x>115&&x<225&&y>145&&y<240)
                        {
                            if(laptop_image!=NULL)
                            {
                                SDL_RenderCopy(screen, textTexture, NULL, &textRect);
                                SDL_RenderCopy(screen, textTexture_name, NULL, &textRect_name);
                                SDL_RenderPresent(screen);
                                press=1;
                            }
                        }
                        else if(x>345&&x<450&&y>145&&y<240)
                        {
                            if(note_image!=NULL)
                            {
                                SDL_RenderCopy(screen, textTexture2, NULL, &textRect2);
                                SDL_RenderCopy(screen, textTexture_name2, NULL, &textRect_name2);
                                SDL_RenderPresent(screen);
                                press=2;
                            }
                        }
                        else if(x>575&&x<680&&y>145&&y<240)
                        {
                            if(ticket_image!=NULL)
                            {
                                SDL_RenderCopy(screen, textTexture3, NULL, &textRect3);
                                SDL_RenderCopy(screen, textTexture_name3, NULL, &textRect_name3);
                                SDL_RenderPresent(screen);
                                press=3;
                            }
                        }
                        else if(x>335&&x<465&&y>500&&y<550)
                        {
                            quit = 3;
                            return quit;
                        }
                    }
                    break;
                default:
                    break;
            }
        }
    }
    return quit;
}

int SDL_no_choice_one_character(char *background_image, char *character_image, char *character_message, char *character_name, Backpack packing)
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
    SDL_Surface *pack=NULL;
    
    SDL_Color textColor={ 0, 0, 0 };
    SDL_Color messageColor={ 28, 56, 121 };
    SDL_Color packColor={ 255, 255, 255 };
    image = IMG_Load(background_image);
    if(character_image!=NULL)
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
    SDL_RenderClear(screen);
    create_player(background,screen,image,b);
    create_player(play,screen,player,b);
    create_player(talking,screen,talk,b);
    create_player(butt,screen,button,b);
    
    message=TTF_RenderUTF8_Solid( font,character_message, messageColor );
    name=TTF_RenderUTF8_Solid( font,character_name, textColor );
    pack=TTF_RenderUTF8_Solid( font,"背包", packColor );
    
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(screen, message);
    SDL_Texture* textTexture_name = SDL_CreateTextureFromSurface(screen, name);
    SDL_Texture* textTexture_pack = SDL_CreateTextureFromSurface(screen, pack);
    SDL_Rect textRect;
    textRect.x = 63;
    textRect.y = 451;
    textRect.w = message->w/2;
    textRect.h = message->h/2;
    SDL_Rect textRect_name;
    textRect_name.x = 85;
    textRect_name.y = 412;
    textRect_name.w = name->w/2;
    textRect_name.h = name->h/2;
    SDL_Rect textRect_pack;
    textRect_pack.x = 453;
    textRect_pack.y = 409;
    textRect_pack.w = pack->w/1.85;
    textRect_pack.h = pack->h/1.85;
    
    SDL_RenderCopy(screen, textTexture, NULL, &textRect);
    SDL_RenderCopy(screen, textTexture_name, NULL, &textRect_name);
    SDL_RenderCopy(screen, textTexture_pack, NULL, &textRect_pack);
    
    
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
                    quit = 4;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if(event.button.button == SDL_BUTTON_LEFT)
                    {
                        x=event.button.x;
                        y=event.button.y;
                        if(x>=444&&x<=444+64&&y>=415&&y<=444+32)
                        {
                            int back = backpack(packing.background_image,packing.laptop_image,packing.note_image,packing.ticket_image,packing.laptop_message,packing.note_message,packing.ticket_message,packing.laptop_name,packing.note_name,packing.ticket_name);
                            if(back == 3)
                            {
                                image = IMG_Load(background_image);
                                player = IMG_Load(character_image);
                                talk = IMG_Load("talk.png");
                                button = IMG_Load("button.png");
                                blank = IMG_Load("blank.png");
                                create_player(background,screen,image,b);
                                create_player(play,screen,player,b);
                                create_player(talking,screen,talk,b);
                                create_player(butt,screen,button,b);
    
                                SDL_RenderCopy(screen, textTexture, NULL, &textRect);
                                SDL_RenderCopy(screen, textTexture_name, NULL, &textRect_name);
                                SDL_RenderCopy(screen, textTexture_pack, NULL, &textRect_pack);
                                SDL_RenderPresent(screen);  
                            }
                            else if(back==1)
                            {
                                quit = 4;
                                break;
                            }
                        }
                        else
                        {
                            quit = 1;
                        }
                    }
                    break;
                default:
                    break;
            }
        }
    }
    SDL_DestroyTexture(textTexture);
    SDL_DestroyTexture(textTexture_name);
    SDL_FreeSurface(message);
    SDL_FreeSurface(name);
    SDL_FreeSurface(image);
    SDL_FreeSurface(player);
    SDL_FreeSurface(talk);
    SDL_FreeSurface(button);
    SDL_FreeSurface(blank);
    TTF_CloseFont(font);
    TTF_Quit();
    return quit;
    
}

int SDL_choice_one_character(char *background_image, char *character_image,char *sellect_button_message_up,char *sellect_button_message_middle,char *sellect_button_message_down, char *character_name, Backpack packing)
{
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("simfang.ttf", 40);
    if(font==NULL)
    {
        printf("can not found %s\n",TTF_GetError());
        return 0;
    }
    SDL_Surface *image,*player,*talk,*button,*blank,*sellect_button;
    SDL_Surface *name=NULL;
    SDL_Surface *message_up=NULL;
    SDL_Surface *message_middle=NULL;
    SDL_Surface *message_down=NULL;
    SDL_Surface *pack=NULL;
    SDL_Color textColor={ 0, 0, 0 };
    SDL_Color messageColor={ 28, 56, 121 };
    SDL_Color packColor={ 255, 255, 255 };
    image = IMG_Load(background_image);
    if(character_image != NULL)
    player = IMG_Load(character_image);
    talk = IMG_Load("talk.png");
    button = IMG_Load("button.png");
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
    SDL_RenderClear(screen);
    create_player(background,screen,image,b);
    if(character_image != NULL)
    create_player(play,screen,player,b);
    create_player(talking,screen,talk,b);
    create_player(butt,screen,button,b);
    create_player(butt,screen,sellect_button,b);

    message_up=TTF_RenderUTF8_Solid( font,sellect_button_message_up, messageColor );
    message_middle=TTF_RenderUTF8_Solid( font,sellect_button_message_middle, messageColor );
    message_down=TTF_RenderUTF8_Solid( font,sellect_button_message_down, messageColor );
    name=TTF_RenderUTF8_Solid( font,character_name, textColor );
    pack=TTF_RenderUTF8_Solid( font,"背包", packColor );

    SDL_Texture* textTexture_up = SDL_CreateTextureFromSurface(screen, message_up);
    SDL_Texture* textTexture_middle = SDL_CreateTextureFromSurface(screen, message_middle);
    SDL_Texture* textTexture_down = SDL_CreateTextureFromSurface(screen, message_down);
    SDL_Texture* textTexture_name = SDL_CreateTextureFromSurface(screen, name);
    SDL_Texture* textTexture_pack = SDL_CreateTextureFromSurface(screen, pack);
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
    SDL_Rect textRect_name;
    textRect_name.x = 85;
    textRect_name.y = 416;
    textRect_name.w = name->w/2;
    textRect_name.h = name->h/2;
    SDL_Rect textRect_pack;
    textRect_pack.x = 453;
    textRect_pack.y = 409;
    textRect_pack.w = pack->w/1.85;
    textRect_pack.h = pack->h/1.85;
    
    SDL_RenderCopy(screen, textTexture_up, NULL, &textRect);
    SDL_RenderCopy(screen, textTexture_middle, NULL, &textRect2);
    SDL_RenderCopy(screen, textTexture_down, NULL, &textRect3);
    SDL_RenderCopy(screen, textTexture_name, NULL, &textRect_name);
    SDL_RenderCopy(screen, textTexture_pack, NULL, &textRect_pack);

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
                        {
                            int back = backpack(packing.background_image,packing.laptop_image,packing.note_image,packing.ticket_image,packing.laptop_message,packing.note_message,packing.ticket_message,packing.laptop_name,packing.note_name,packing.ticket_name);
                            if(back == 3)
                            {
                                image = IMG_Load(background_image);
                                if(character_image != NULL)
                                player = IMG_Load(character_image);
                                talk = IMG_Load("talk.png");
                                button = IMG_Load("button.png");
                                sellect_button = IMG_Load("select_button.png");
                                create_player(background,screen,image,b);
                                create_player(play,screen,player,b);
                                create_player(talking,screen,talk,b);
                                create_player(butt,screen,button,b);
                                create_player(butt,screen,sellect_button,b);
    
                                SDL_RenderCopy(screen, textTexture_up, NULL, &textRect);
                                SDL_RenderCopy(screen, textTexture_middle, NULL, &textRect2);
                                SDL_RenderCopy(screen, textTexture_down, NULL, &textRect3);
                                SDL_RenderCopy(screen, textTexture_name, NULL, &textRect_name);
                                SDL_RenderCopy(screen, textTexture_pack, NULL, &textRect_pack);
                                SDL_RenderPresent(screen);  
                            }
                            else if(back==1)
                            {
                                quit = 4;
                                break;
                            }
                        }
                        else if(x>=155&&x<=155+64&&y>=297&&y<=297+32)
                        quit = 3;
                        else if(x>=155&&x<=155+64&&y>=229&&y<=229+32)
                        quit = 2;
                        else if(x>=155&&x<=155+490&&y>=161&&y<=161+32)
                        quit = 1;
                    }
                    break;
                default:
                    break;
            }
        }
    }
    SDL_DestroyTexture(textTexture_down);
    SDL_DestroyTexture(textTexture_middle);
    SDL_DestroyTexture(textTexture_up);
    SDL_DestroyTexture(textTexture_name);
    SDL_FreeSurface(name);
    SDL_FreeSurface(image);
    SDL_FreeSurface(player);
    SDL_FreeSurface(talk);
    SDL_FreeSurface(button);
    SDL_FreeSurface(blank);
    TTF_CloseFont(font);
    TTF_Quit();
    return quit;
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
//     if(i==4)
//     {
//         SDL_DestroyRenderer(screen);
//         SDL_DestroyWindow(window);
//         SDL_Quit();
//         return 0;
//     }
//     else
//     {
//         i = SDL_choice_one_character(in,in2,in3,in4,in5,in6);
//         SDL_DestroyRenderer(screen);
//         SDL_DestroyWindow(window);
//         SDL_Quit();
//         return 0;
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
