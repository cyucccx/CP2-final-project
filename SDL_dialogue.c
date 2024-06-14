#include "include.h"

SDL_Window* window;
SDL_Renderer* screen;


void create_player(Player play, SDL_Renderer *render, SDL_Surface *image, SDL_Rect a)
{
    play.texture = SDL_CreateTextureFromSurface(render,image);
    if (play.texture == NULL) {
        // handle error, e.g., log the error and return
        return;
    }
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
    //SDL_DestroyTexture(play.texture);
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
    SDL_Rect background,laptopp,notee,tickett;
    background.x = 0;
    background.y = 0;
    background.h = 600;
    background.w = 800;
    laptopp.x = 135;
    laptopp.y = 160;
    laptopp.h = 65;
    laptopp.w = 65;
    notee.x = 365;
    notee.y = 160;
    notee.h = 65;
    notee.w = 65;
    tickett.x = 595;
    tickett.y = 160;
    tickett.h = 65;
    tickett.w = 65;
    SDL_Rect b,a;
    a.x = 0;
    a.y = 0;
    a.h = 65;
    a.w = 65;

    b.x = 0;
    b.y = 0;
    b.h = 600;
    b.w = 800;
    SDL_RenderClear(screen);
    SDL_Texture* laptop_texture = SDL_CreateTextureFromSurface(screen, laptop);
    SDL_FreeSurface(laptop);
    SDL_Texture* note_texture = SDL_CreateTextureFromSurface(screen, note);
    SDL_FreeSurface(note);
    SDL_Texture* ticket_texture = SDL_CreateTextureFromSurface(screen, ticket);
    SDL_FreeSurface(ticket);
    SDL_Texture* background_texture = SDL_CreateTextureFromSurface(screen, image);
    SDL_FreeSurface(image);
    SDL_RenderCopy(screen, background_texture, NULL, &background);
    SDL_RenderCopy(screen, laptop_texture, NULL, &laptopp);
    SDL_RenderCopy(screen, note_texture, NULL, &notee);
    SDL_RenderCopy(screen, ticket_texture, NULL, &tickett);
    SDL_RenderPresent(screen);

    SDL_Surface *message=NULL;
    SDL_Surface *message_2=NULL;
    SDL_Surface *message_3=NULL;
    SDL_Surface *name=NULL;
    char talking_message[3][110]={0};
    
    int cou=0,cou2=0,cou3=0;
    int len=0;
    if(laptop_message!=NULL)
    len =strlen(laptop_message);
    for(int i=0;i<len;)
    {
         if ((laptop_message[i] & 0x80) == 0) {
            talking_message[cou][cou2]=laptop_message[i];
            cou3+=2;
            cou2++;
            if(cou3>=69)
            {
                cou++;
                cou3=0;
                cou2=0;
            }
            i += 1; // ASCII字符占1字节
        } else {
            talking_message[cou][cou2]=laptop_message[i];
            talking_message[cou][cou2+1]=laptop_message[i+1];
            talking_message[cou][cou2+2]=laptop_message[i+2];
            cou2+=3;
            cou3+=3;
            if(cou3>=69)
            {
                cou++;
                cou3=0;
                cou2=0;
            } 
            i += 3; // 中文字符占3字节
        }
    }
    if(laptop_message!=NULL)
    {
        if(cou==0)
        message=TTF_RenderUTF8_Solid( font,talking_message[0], messageColor );
        else if(cou==1)
        {
            message=TTF_RenderUTF8_Solid( font,talking_message[0], messageColor );
            message_2=TTF_RenderUTF8_Solid( font,talking_message[1], messageColor );
        }
        else if(cou==2)
        {
            message=TTF_RenderUTF8_Solid( font,talking_message[0], messageColor );
            message_2=TTF_RenderUTF8_Solid( font,talking_message[1], messageColor );
            message_3=TTF_RenderUTF8_Solid( font,talking_message[2], messageColor );
        }
    }
    
    if(laptop_name!=NULL)
    name=TTF_RenderUTF8_Solid( font,laptop_name, textColor );
    SDL_Texture* textTexture;
    SDL_Texture* textTexture_2;
    SDL_Texture* textTexture_3;
    if(talking_message[0]!=NULL)
    textTexture = SDL_CreateTextureFromSurface(screen, message);
    if(talking_message[1]!=NULL)
    textTexture_2 = SDL_CreateTextureFromSurface(screen, message_2);
    if(talking_message[2]!=NULL)
    textTexture_3 = SDL_CreateTextureFromSurface(screen, message_3);
    SDL_Texture* textTexture_name;
    if(laptop_name!=NULL)
    textTexture_name = SDL_CreateTextureFromSurface(screen, name);
    SDL_Rect textRect;
    textRect.x = 105;
    textRect.y = 343;
    if(message!=NULL)
    textRect.w = message->w/2;
    if(message!=NULL)
    textRect.h = message->h/2;
    SDL_Rect textRect_2;
    textRect_2.x = 105;
    textRect_2.y = 365;
    if(message_2!=NULL)
    textRect_2.w = message_2->w/2;
    if(message_2!=NULL)
    textRect_2.h = message_2->h/2;
    SDL_Rect textRect_3;
    textRect_3.x = 105;
    textRect_3.y = 343;
    if(message_3!=NULL)
    textRect_3.w = message_3->w/2;
    if(message_3!=NULL)
    textRect_3.h = message_3->h/2;
    SDL_Rect textRect_name;
    textRect_name.x = 105;
    textRect_name.y = 286;
    if(laptop_name!=NULL)
    textRect_name.w = name->w/2;
    if(laptop_name!=NULL)
    textRect_name.h = name->h/2;

    SDL_Surface *message2=NULL;
    SDL_Surface *message2_2=NULL;
    SDL_Surface *message2_3=NULL;
    SDL_Surface *name2=NULL;
    char talking_message2[3][110]={0};
    
    int couu=0,couu2=0,couu3=0;
    int len2=0;
    if(note_message!=NULL)
    len2 =strlen(note_message);
    for(int i=0;i<len2;)
    {
         if ((note_message[i] & 0x80) == 0) {
            talking_message2[couu][couu2]=note_message[i];
            couu3+=2;
            couu2++;
            if(couu3>=69)
            {
                couu++;
                couu3=0;
                couu2=0;
            }
            i += 1; // ASCII字符占1字节
        } else {
            talking_message2[couu][couu2]=note_message[i];
            talking_message2[couu][couu2+1]=note_message[i+1];
            talking_message2[couu][couu2+2]=note_message[i+2];
            couu2+=3;
            couu3+=3;
            if(couu3>=69)
            {
                couu++;
                couu3=0;
                couu2=0;
            } 
            i += 3; // 中文字符占3字节
        }
    }
    if(note_message!=NULL)
    {
        if(couu==0)
        message2=TTF_RenderUTF8_Solid( font,talking_message2[0], messageColor );
        else if(couu==1)
        {
            message2=TTF_RenderUTF8_Solid( font,talking_message2[0], messageColor );
            message2_2=TTF_RenderUTF8_Solid( font,talking_message2[1], messageColor );
        }
        else if(couu==2)
        {
            message2=TTF_RenderUTF8_Solid( font,talking_message2[0], messageColor );
            message2_2=TTF_RenderUTF8_Solid( font,talking_message2[1], messageColor );
            message2_3=TTF_RenderUTF8_Solid( font,talking_message2[2], messageColor );
        }
    }

    if(note_name!=NULL)
    name2=TTF_RenderUTF8_Solid( font,note_name, textColor );
    SDL_Texture* textTexture2;
    SDL_Texture* textTexture2_2;
    SDL_Texture* textTexture2_3;
    if(talking_message2[0]!=NULL)
    textTexture2 = SDL_CreateTextureFromSurface(screen, message2);
    if(talking_message2[1]!=NULL)
    textTexture2_2 = SDL_CreateTextureFromSurface(screen, message2_2);
    if(talking_message2[2]!=NULL)
    textTexture2_3 = SDL_CreateTextureFromSurface(screen, message2_3);

    SDL_Texture* textTexture_name2;
    if(note_name!=NULL)
    textTexture_name2 = SDL_CreateTextureFromSurface(screen, name2);
    SDL_Rect textRect2;
    textRect2.x = 105;
    textRect2.y = 343;
    if(message2!=NULL)
    textRect2.w = message2->w/2;
    if(message2!=NULL)
    textRect2.h = message2->h/2;
    SDL_Rect textRect2_2;
    textRect2_2.x = 105;
    textRect2_2.y = 365;
    if(message2_2!=NULL)
    textRect2_2.w = message2_2->w/2;
    if(message2_2!=NULL)
    textRect2_2.h = message2_2->h/2;
    SDL_Rect textRect2_3;
    textRect2_3.x = 105;
    textRect2_3.y = 343;
    if(message2_3!=NULL)
    textRect2_3.w = message2_3->w/2;
    if(message2_3!=NULL)
    textRect2_3.h = message2_3->h/2;
    SDL_Rect textRect_name2;
    textRect_name2.x = 105;
    textRect_name2.y = 286;
    
    if(note_name!=NULL)
    textRect_name2.w = name2->w/2;
    if(note_name!=NULL)
    textRect_name2.h = name2->h/2;

    SDL_Surface *message3=NULL;
    SDL_Surface *message3_2=NULL;
    SDL_Surface *message3_3=NULL;
    SDL_Surface *name3=NULL;
    char talking_message3[3][110]={0};
    
    int couuu=0,couuu2=0,couuu3=0;
    int len3=0;
    if(ticket_message!=NULL)
    len3 =strlen(ticket_message);
    for(int i=0;i<len3;)
    {
         if ((ticket_message[i] & 0x80) == 0) {
            talking_message3[couuu][couuu2]=ticket_message[i];
            couuu3+=2;
            couuu2++;
            if(couuu3>=69)
            {
                couuu++;
                couuu3=0;
                couuu2=0;
            }
            i += 1; // ASCII字符占1字节
        } else {
            talking_message3[couuu][couuu2]=ticket_message[i];
            talking_message3[couuu][couuu2+1]=ticket_message[i+1];
            talking_message3[couuu][couuu2+2]=ticket_message[i+2];
            couuu2+=3;
            couuu3+=3;
            if(couuu3>=69)
            {
                couuu++;
                couuu3=0;
                couuu2=0;
            } 
            i += 3; // 中文字符占3字节
        }
    }
    if(ticket_message!=NULL)
    {
        if(couuu==0)
        message3=TTF_RenderUTF8_Solid( font,talking_message3[0], messageColor );
        else if(couuu==1)
        {
            message3=TTF_RenderUTF8_Solid( font,talking_message3[0], messageColor );
            message3_2=TTF_RenderUTF8_Solid( font,talking_message3[1], messageColor );
        }
        else if(couuu==2)
        {
            message3=TTF_RenderUTF8_Solid( font,talking_message3[0], messageColor );
            message3_2=TTF_RenderUTF8_Solid( font,talking_message3[1], messageColor );
            message3_3=TTF_RenderUTF8_Solid( font,talking_message3[2], messageColor );
        }
    }

    if(ticket_name!=NULL)
    name3=TTF_RenderUTF8_Solid( font,ticket_name, textColor );
    SDL_Texture* textTexture3;
    SDL_Texture* textTexture3_2;
    SDL_Texture* textTexture3_3;
    if(message3!=NULL)
    textTexture3 = SDL_CreateTextureFromSurface(screen, message3);
    if(message3_2!=NULL)
    textTexture3_2 = SDL_CreateTextureFromSurface(screen, message3_2);
    if(message3_3!=NULL)
    textTexture3_3 = SDL_CreateTextureFromSurface(screen, message3_3);

    SDL_Texture* textTexture_name3;
    if(ticket_name!=NULL)
    textTexture_name3 = SDL_CreateTextureFromSurface(screen, name3);
    SDL_Rect textRect3;
    textRect3.x = 105;
    textRect3.y = 343;
    if(message3!=NULL)
    textRect3.w = message3->w/2;
    if(message3!=NULL)
    textRect3.h = message3->h/2;
    SDL_Rect textRect3_2;
    textRect3_2.x = 105;
    textRect3_2.y = 365;
    if(message3_2!=NULL)
    textRect3_2.w = message3_2->w/2;
    if(message3_2!=NULL)
    textRect3_2.h = message3_2->h/2;
    SDL_Rect textRect3_3;
    textRect3_3.x = 105;
    textRect3_3.y = 343;
    if(message3_3!=NULL)
    textRect3_3.w = message3_3->w/2;
    if(message3_3!=NULL)
    textRect3_3.h = message3_3->h/2;

    SDL_Rect textRect_name3;
    textRect_name3.x = 105;
    textRect_name3.y = 286;
    if(ticket_name!=NULL)
    textRect_name3.w = name3->w/2;
    if(ticket_name!=NULL)
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
                            SDL_RenderCopy(screen, background_texture, NULL, &background);
                        }
                        SDL_Surface *button1;
                        button1 = IMG_Load("select1.png");
                        SDL_Texture* button_texture = SDL_CreateTextureFromSurface(screen, button1);
                        SDL_FreeSurface(button1);
                        SDL_Rect button_1;
                        button_1.x = 0;
                        button_1.y = 0;
                        button_1.h = 600;
                        button_1.w = 800;
                        SDL_RenderCopy(screen, button_texture, NULL, &button_1);
                        SDL_RenderCopy(screen, laptop_texture, NULL, &laptopp);
                        SDL_RenderCopy(screen, note_texture, NULL, &notee);
                        SDL_RenderCopy(screen, ticket_texture, NULL, &tickett);
                        SDL_RenderPresent(screen);
                    }
                    else if(x>345&&x<450&&y>145&&y<240)
                    {
                        if(press == 1 || press == 3)
                        {
                            SDL_RenderCopy(screen, background_texture, NULL, &background);
                        }
                        SDL_Surface *button1;
                        button1 = IMG_Load("select2.png");
                        SDL_Texture* button_texture = SDL_CreateTextureFromSurface(screen, button1);
                        SDL_FreeSurface(button1);
                        SDL_Rect button_1;
                        button_1.x = 0;
                        button_1.y = 0;
                        button_1.h = 600;
                        button_1.w = 800;
                        SDL_RenderCopy(screen, button_texture, NULL, &button_1);
                        SDL_RenderCopy(screen, laptop_texture, NULL, &laptopp);
                        SDL_RenderCopy(screen, note_texture, NULL, &notee);
                        SDL_RenderCopy(screen, ticket_texture, NULL, &tickett);
                        SDL_RenderPresent(screen);
                    }
                    else if(x>575&&x<680&&y>145&&y<240)
                    {
                        if(press == 1 || press == 2)
                        {
                            SDL_RenderCopy(screen, background_texture, NULL, &background);
                        }
                        SDL_Surface *button1;
                        SDL_FreeSurface(button1);
                        button1 = IMG_Load("select3.png");
                        SDL_Texture* button_texture = SDL_CreateTextureFromSurface(screen, button1);
                        SDL_Rect button_1;
                        button_1.x = 0;
                        button_1.y = 0;
                        button_1.h = 600;
                        button_1.w = 800;
                        SDL_RenderCopy(screen, button_texture, NULL, &button_1);
                        SDL_RenderCopy(screen, laptop_texture, NULL, &laptopp);
                        SDL_RenderCopy(screen, note_texture, NULL, &notee);
                        SDL_RenderCopy(screen, ticket_texture, NULL, &tickett);
                        SDL_RenderPresent(screen);
                    }
                    else
                    {
                        SDL_RenderCopy(screen, background_texture, NULL, &background);
                        SDL_RenderCopy(screen, laptop_texture, NULL, &laptopp);
                        SDL_RenderCopy(screen, note_texture, NULL, &notee);
                        SDL_RenderCopy(screen, ticket_texture, NULL, &tickett);
                        if(press == 1)
                        {
                            if(cou==0)
                            SDL_RenderCopy(screen, textTexture, NULL, &textRect);
                            else if(cou==1)
                            {
                                SDL_RenderCopy(screen, textTexture, NULL, &textRect);
                                SDL_RenderCopy(screen, textTexture_2, NULL, &textRect_2);
                            }
                            else if(cou==2)
                            {
                                SDL_RenderCopy(screen, textTexture, NULL, &textRect);
                                SDL_RenderCopy(screen, textTexture_2, NULL, &textRect_2);
                                SDL_RenderCopy(screen, textTexture_3, NULL, &textRect_3);
                            }
                            SDL_RenderCopy(screen, textTexture_name, NULL, &textRect_name);
                        }
                        else if(press == 2)
                        {
                            if(couu=0)
                            SDL_RenderCopy(screen, textTexture2, NULL, &textRect2);
                            else if(couu==1)
                            {
                                SDL_RenderCopy(screen, textTexture2, NULL, &textRect2);
                                SDL_RenderCopy(screen, textTexture2_2, NULL, &textRect2_2);
                            }
                            else if(couu==2)
                            {
                                SDL_RenderCopy(screen, textTexture2, NULL, &textRect2);
                                SDL_RenderCopy(screen, textTexture2_2, NULL, &textRect2_2);
                                SDL_RenderCopy(screen, textTexture2_3, NULL, &textRect2_3);
                            }
                            SDL_RenderCopy(screen, textTexture_name2, NULL, &textRect_name2);
                        }
                        else if(press == 3)
                        {
                            if(couuu==0)
                            SDL_RenderCopy(screen, textTexture3, NULL, &textRect3);
                            else if(couuu==1)
                            {
                                SDL_RenderCopy(screen, textTexture3, NULL, &textRect3);
                                SDL_RenderCopy(screen, textTexture3_2, NULL, &textRect3_2);
                            }
                            else if(couuu==2)
                            {
                                SDL_RenderCopy(screen, textTexture3, NULL, &textRect3);
                                SDL_RenderCopy(screen, textTexture3_2, NULL, &textRect3_2);
                                SDL_RenderCopy(screen, textTexture3_3, NULL, &textRect3_3);
                            }
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
                                if(cou==0)
                                SDL_RenderCopy(screen, textTexture, NULL, &textRect);
                                else if(cou==1)
                                {
                                    SDL_RenderCopy(screen, textTexture, NULL, &textRect);
                                    SDL_RenderCopy(screen, textTexture_2, NULL, &textRect_2);
                                }
                                else if(cou==2)
                                {
                                    SDL_RenderCopy(screen, textTexture, NULL, &textRect);
                                    SDL_RenderCopy(screen, textTexture_2, NULL, &textRect_2);
                                    SDL_RenderCopy(screen, textTexture_3, NULL, &textRect_3);
                                }
                                SDL_RenderCopy(screen, textTexture_name, NULL, &textRect_name);
                                SDL_RenderPresent(screen);
                                press=1;
                            }
                        }
                        else if(x>345&&x<450&&y>145&&y<240)
                        {
                            if(note_image!=NULL)
                            {
                                if(couu==0)
                                SDL_RenderCopy(screen, textTexture2, NULL, &textRect2);
                                else if(couu==1)
                                {
                                    SDL_RenderCopy(screen, textTexture2, NULL, &textRect2);
                                    SDL_RenderCopy(screen, textTexture2_2, NULL, &textRect2_2);
                                }
                                else if(couu==2)
                                {
                                    SDL_RenderCopy(screen, textTexture2, NULL, &textRect2);
                                    SDL_RenderCopy(screen, textTexture2_2, NULL, &textRect2_2);
                                    SDL_RenderCopy(screen, textTexture2_3, NULL, &textRect2_3);
                                }
                                SDL_RenderCopy(screen, textTexture_name2, NULL, &textRect_name2);
                                SDL_RenderPresent(screen);
                                press=2;
                            }
                        }
                        else if(x>575&&x<680&&y>145&&y<240)
                        {
                            if(ticket_image!=NULL)
                            {
                                if(couuu==0)
                                SDL_RenderCopy(screen, textTexture3, NULL, &textRect3);
                                else if(couuu==1)
                                {
                                    SDL_RenderCopy(screen, textTexture3, NULL, &textRect3);
                                    SDL_RenderCopy(screen, textTexture3_2, NULL, &textRect3_2);
                                }
                                else if(couuu==2)
                                {
                                    SDL_RenderCopy(screen, textTexture3, NULL, &textRect3);
                                    SDL_RenderCopy(screen, textTexture3_2, NULL, &textRect3_2);
                                    SDL_RenderCopy(screen, textTexture3_3, NULL, &textRect3_3);
                                }
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

int SDL_no_choice_one_character(char *background_image, char *character_image, char *character_message, char *character_name, Backpack packing, char *small_character_image)
{
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("simfang.ttf", 40);
    if(font==NULL)
    {
        printf("can not found %s\n",TTF_GetError());
        return 0;
    }
    SDL_Surface *image,*player,*talk,*button,*blank,*small_player;
    SDL_Surface *message=NULL;
    SDL_Surface *message2=NULL;
    SDL_Surface *message3=NULL;
    SDL_Surface *name=NULL;
    SDL_Surface *pack=NULL;
    
    SDL_Color textColor={ 0, 0, 0 };
    SDL_Color messageColor={ 28, 56, 121 };
    SDL_Color packColor={ 255, 255, 255 };
    image = IMG_Load(background_image);
    if(character_image!=NULL)
    player = IMG_Load(character_image);
    small_player = IMG_Load(small_character_image);
    talk = IMG_Load("talk.png");
    button = IMG_Load("button.png");
    blank = IMG_Load("blank.png");
    
    Player play,small_play,background,talking,butt;
    SDL_Rect a,b,c,d;
    b.x = 0;
    b.y = 0;
    b.h = 600;
    b.w = 800;
    a.x=65;
    a.y=440;
    a.h=115;
    a.w=98;
    c.x=28;
    c.y=375;
    c.h=200;
    c.w=743;
    d.x=646;
    d.y=393;
    d.h=41;
    d.w=91;
    
    SDL_Texture* background_texture = SDL_CreateTextureFromSurface(screen, image);
    SDL_FreeSurface(image);
    SDL_Texture* play_texture = SDL_CreateTextureFromSurface(screen, player);
    SDL_FreeSurface(player);
    SDL_Texture* talk_texture = SDL_CreateTextureFromSurface(screen, talk);
    SDL_FreeSurface(talk);
    SDL_Texture* button_texture = SDL_CreateTextureFromSurface(screen, button);
    SDL_FreeSurface(button);
    SDL_Texture* smallplayer_texture = SDL_CreateTextureFromSurface(screen, small_player);
    SDL_FreeSurface(small_player);
    SDL_RenderCopy(screen, background_texture, NULL, &b);
    SDL_RenderCopy(screen, play_texture, NULL, &b);
    SDL_RenderCopy(screen, talk_texture, NULL, &c);
    SDL_RenderCopy(screen, button_texture, NULL, &d);
    SDL_RenderCopy(screen, smallplayer_texture, NULL, &a);
    SDL_RenderPresent(screen);
    
    char talking_message[3][110]={0};
    
    int cou=0,cou2=0,cou3=0;
    int len =strlen(character_message);
    for(int i=0;i<len;)
    {
         if ((character_message[i] & 0x80) == 0) {
            talking_message[cou][cou2]=character_message[i];
            cou3+=2;
            cou2++;
            if(cou3>=87)
            {
                cou++;
                cou3=0;
                cou2=0;
            }
            i += 1; // ASCII字符占1字节
        } else {
            talking_message[cou][cou2]=character_message[i];
            talking_message[cou][cou2+1]=character_message[i+1];
            talking_message[cou][cou2+2]=character_message[i+2];
            cou2+=3;
            cou3+=3;
            if(cou3>=87)
            {
                cou++;
                cou3=0;
                cou2=0;
            } 
           
            i += 3; // 中文字符占3字节
        }
    }
    if(cou==0)
    message=TTF_RenderUTF8_Solid( font,talking_message[0], messageColor);
    else if(cou==1)
    {
        message=TTF_RenderUTF8_Solid( font,talking_message[0], messageColor);
        message2=TTF_RenderUTF8_Solid( font,talking_message[1], messageColor);
    }
    else if(cou==2)
    {
        message=TTF_RenderUTF8_Solid( font,talking_message[0], messageColor);
        message2=TTF_RenderUTF8_Solid( font,talking_message[1], messageColor);
        message3=TTF_RenderUTF8_Solid( font,talking_message[2], messageColor);
    }
    name=TTF_RenderUTF8_Solid( font,character_name, textColor );
    pack=TTF_RenderUTF8_Solid( font,"背包", packColor );
    
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(screen, message);
    SDL_Texture* textTexture2 = SDL_CreateTextureFromSurface(screen, message2);
    SDL_Texture* textTexture3 = SDL_CreateTextureFromSurface(screen, message3);
    SDL_Texture* textTexture_name = SDL_CreateTextureFromSurface(screen, name);
    SDL_Texture* textTexture_pack = SDL_CreateTextureFromSurface(screen, pack);
    SDL_Rect textRect;
    textRect.x = 182;
    textRect.y = 451;
    textRect.w = message->w/2;
    textRect.h = message->h/2;
    SDL_Rect textRect2;
    textRect2.x = 182;
    textRect2.y = 474;
    if(message2!=NULL)
    textRect2.w = message2->w/2;
    if(message2!=NULL)
    textRect2.h = message2->h/2;
    SDL_Rect textRect3;
    textRect3.x = 182;
    textRect3.y = 497;
    if(message3!=NULL)
    textRect3.w = message3->w/2;
    if(message3!=NULL)
    textRect3.h = message3->h/2;
    SDL_Rect textRect_name;
    textRect_name.x = 88;
    textRect_name.y = 400;
    textRect_name.w = name->w/2;
    textRect_name.h = name->h/2;
    SDL_Rect textRect_pack;
    textRect_pack.x = 671;
    textRect_pack.y = 397;
    textRect_pack.w = pack->w/1.85;
    textRect_pack.h = pack->h/1.85;
    if(cou==0)
    SDL_RenderCopy(screen, textTexture, NULL, &textRect);
    else if(cou==1)
    {
        SDL_RenderCopy(screen, textTexture, NULL, &textRect);
        SDL_RenderCopy(screen, textTexture2, NULL, &textRect2);
    }
    else if(cou==2)
    {
        SDL_RenderCopy(screen, textTexture, NULL, &textRect);
        SDL_RenderCopy(screen, textTexture2, NULL, &textRect2);
        SDL_RenderCopy(screen, textTexture3, NULL, &textRect3);
    }
    
    
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
                        if(x>=646&&x<=646+91&&y>=393&&y<=393+41)
                        {
                            int back = backpack(packing.background_image,packing.laptop_image,packing.note_image,packing.ticket_image,packing.laptop_message,packing.note_message,packing.ticket_message,packing.laptop_name,packing.note_name,packing.ticket_name);
                            if(back == 3)
                            {
                                SDL_RenderCopy(screen, background_texture, NULL, &b);
                                SDL_RenderCopy(screen, play_texture, NULL, &b);
                                SDL_RenderCopy(screen, talk_texture, NULL, &c);
                                SDL_RenderCopy(screen, button_texture, NULL, &d);
                                SDL_RenderCopy(screen, smallplayer_texture, NULL, &a);
    
                                if(cou==0)
                                SDL_RenderCopy(screen, textTexture, NULL, &textRect);
                                else if(cou==1)
                                {
                                    SDL_RenderCopy(screen, textTexture, NULL, &textRect);
                                    SDL_RenderCopy(screen, textTexture2, NULL, &textRect2);
                                }
                                else if(cou==2)
                                {
                                    SDL_RenderCopy(screen, textTexture, NULL, &textRect);
                                    SDL_RenderCopy(screen, textTexture2, NULL, &textRect2);
                                    SDL_RenderCopy(screen, textTexture3, NULL, &textRect3);
                                }
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
    TTF_CloseFont(font);
    TTF_Quit();
    return quit;
    
}

int SDL_no_choice_one_character_anime(char *background_image, char *character_image, char *character_message, char *character_name, Backpack packing,char *small_character_image)
{
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("simfang.ttf", 40);
    if(font==NULL)
    {
        printf("can not found %s\n",TTF_GetError());
        return 0;
    }
    SDL_Surface *image,*player,*talk,*button,*small_player;
    SDL_Surface *message=NULL;
    SDL_Surface *message2=NULL;
    SDL_Surface *message3=NULL;
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
    small_player = IMG_Load(small_character_image);
    
    Player play,background,talking,butt,small_play;
    SDL_Rect a,b,c,d;
    b.x = 0;
    b.y = 0;
    b.h = 600;
    b.w = 800;
    a.x=65;
    a.y=440;
    a.h=115;
    a.w=98;
    c.x=28;
    c.y=375;
    c.h=200;
    c.w=743;
    d.x=646;
    d.y=393;
    d.h=41;
    d.w=91;
    
    play.x = 0;
    play.y = 0;
    play.height = 600;
    play.width = 800;
    background.x = 0;
    background.y = 0;
    background.height = 600;
    background.width = 800;
    talking.x = 28;
    talking.y = 375;
    talking.height = 200;
    talking.width = 743;
    butt.x = 646;
    butt.y = 393;
    butt.height = 41;
    butt.width = 91;
    small_play.x=65;
    small_play.y=440;
    small_play.height=115;
    small_play.width=98;
    SDL_Texture* background_texture = SDL_CreateTextureFromSurface(screen, image);
    SDL_FreeSurface(image);
    SDL_Texture* play_texture = SDL_CreateTextureFromSurface(screen, player);
    SDL_FreeSurface(player);
    SDL_Texture* talk_texture = SDL_CreateTextureFromSurface(screen, talk);
    SDL_FreeSurface(talk);
    SDL_Texture* button_texture = SDL_CreateTextureFromSurface(screen, button);
    SDL_FreeSurface(button);
    SDL_Texture* smallplayer_texture = SDL_CreateTextureFromSurface(screen, small_player);
    SDL_FreeSurface(small_player);
    
    char talking_message[3][110]={0};
    
    int cou=0,cou2=0,cou3=0;
    int len =strlen(character_message);
    for(int i=0;i<len;)
    {
         if ((character_message[i] & 0x80) == 0) {
            talking_message[cou][cou2]=character_message[i];
            cou3+=2;
            cou2++;
            if(cou3>=87)
            {
                cou++;
                cou3=0;
                cou2=0;
            }
            i += 1; // ASCII字符占1字节
        } else {
            talking_message[cou][cou2]=character_message[i];
            talking_message[cou][cou2+1]=character_message[i+1];
            talking_message[cou][cou2+2]=character_message[i+2];
            cou2+=3;
            cou3+=3;
            if(cou3>=87)
            {
                cou++;
                cou3=0;
                cou2=0;
            } 
           
            i += 3; // 中文字符占3字节
        }
    }
    if(cou==0)
    message=TTF_RenderUTF8_Solid( font,talking_message[0], messageColor);
    else if(cou==1)
    {
        message=TTF_RenderUTF8_Solid( font,talking_message[0], messageColor);
        message2=TTF_RenderUTF8_Solid( font,talking_message[1], messageColor);
    }
    else if(cou==2)
    {
        message=TTF_RenderUTF8_Solid( font,talking_message[0], messageColor);
        message2=TTF_RenderUTF8_Solid( font,talking_message[1], messageColor);
        message3=TTF_RenderUTF8_Solid( font,talking_message[2], messageColor);
    }
    name=TTF_RenderUTF8_Solid( font,character_name, textColor );
    pack=TTF_RenderUTF8_Solid( font,"背包", packColor );
    
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(screen, message);
    SDL_Texture* textTexture2 = SDL_CreateTextureFromSurface(screen, message2);
    SDL_Texture* textTexture3 = SDL_CreateTextureFromSurface(screen, message3);
    SDL_Texture* textTexture_name = SDL_CreateTextureFromSurface(screen, name);
    SDL_Texture* textTexture_pack = SDL_CreateTextureFromSurface(screen, pack);
    SDL_Rect textRect;
    textRect.x = 182;
    textRect.y = 451;
    textRect.w = message->w/2;
    textRect.h = message->h/2;
    SDL_Rect textRect2;
    textRect2.x = 182;
    textRect2.y = 474;
    if(message2!=NULL)
    textRect2.w = message2->w/2;
    if(message2!=NULL)
    textRect2.h = message2->h/2;
    SDL_Rect textRect3;
    textRect3.x = 182;
    textRect3.y = 497;
    if(message3!=NULL)
    textRect3.w = message3->w/2;
    if(message3!=NULL)
    textRect3.h = message3->h/2;
    SDL_Rect textRect_name;
    textRect_name.x = 88;
    textRect_name.y = 400;
    textRect_name.w = name->w/2;
    textRect_name.h = name->h/2;
    SDL_Rect textRect_pack;
    textRect_pack.x = 671;
    textRect_pack.y = 397;
    textRect_pack.w = pack->w/1.85;
    textRect_pack.h = pack->h/1.85;
    
    SDL_FlushEvents(SDL_FIRSTEVENT,SDL_LASTEVENT);
    Uint8 alpha = 0;
    int go=0;
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
                        if(x>=646&&x<=646+91&&y>=393&&y<=393+41)
                        {
                            int back = backpack(packing.background_image,packing.laptop_image,packing.note_image,packing.ticket_image,packing.laptop_message,packing.note_message,packing.ticket_message,packing.laptop_name,packing.note_name,packing.ticket_name);
                            if(back == 3)
                            {
                                SDL_RenderCopy(screen, background_texture, NULL, &b);
                                SDL_RenderCopy(screen, play_texture, NULL, &b);
                                SDL_RenderCopy(screen, talk_texture, NULL, &c);
                                SDL_RenderCopy(screen, button_texture, NULL, &d);
                                SDL_RenderCopy(screen, smallplayer_texture, NULL, &a);
    
                                if(cou==0)
                                SDL_RenderCopy(screen, textTexture, NULL, &textRect);
                                else if(cou==1)
                                {
                                    SDL_RenderCopy(screen, textTexture, NULL, &textRect);
                                    SDL_RenderCopy(screen, textTexture2, NULL, &textRect2);
                                }
                                else if(cou==2)
                                {
                                    SDL_RenderCopy(screen, textTexture, NULL, &textRect);
                                    SDL_RenderCopy(screen, textTexture2, NULL, &textRect2);
                                    SDL_RenderCopy(screen, textTexture3, NULL, &textRect3);
                                }
                                
                                
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
        if (alpha < 255) {
            SDL_RenderClear(screen);
            SDL_SetTextureAlphaMod(background_texture, alpha);
            SDL_SetTextureAlphaMod(play_texture, alpha);
            SDL_SetTextureAlphaMod(talk_texture, alpha);
            SDL_SetTextureAlphaMod(button_texture, alpha);
            SDL_SetTextureAlphaMod(smallplayer_texture, alpha);
            SDL_RenderCopy(screen, background_texture, NULL, &b);
            SDL_RenderCopy(screen, play_texture, NULL, &b);
            SDL_RenderCopy(screen, talk_texture, NULL, &c);
            SDL_RenderCopy(screen, button_texture, NULL, &d);
            SDL_RenderCopy(screen, smallplayer_texture, NULL, &a);
            SDL_RenderPresent(screen);
            alpha++;
        }
        else
        {
            if(go==0)
            {
                if(cou==0)
                SDL_RenderCopy(screen, textTexture, NULL, &textRect);
                else if(cou==1)
                {
                    SDL_RenderCopy(screen, textTexture, NULL, &textRect);
                    SDL_RenderCopy(screen, textTexture2, NULL, &textRect2);
                }
                else if(cou==2)
                {
                    SDL_RenderCopy(screen, textTexture, NULL, &textRect);
                    SDL_RenderCopy(screen, textTexture2, NULL, &textRect2);
                    SDL_RenderCopy(screen, textTexture3, NULL, &textRect3);
                }
                
                SDL_RenderCopy(screen, textTexture_name, NULL, &textRect_name);
                SDL_RenderCopy(screen, textTexture_pack, NULL, &textRect_pack);
                
                
                SDL_RenderPresent(screen);
                go=1;
            }
        }
        // 延遲一小段時間
        SDL_Delay(10);
    }
    
    SDL_DestroyTexture(textTexture);
    SDL_DestroyTexture(textTexture_name);
    SDL_FreeSurface(message);
    SDL_FreeSurface(name);
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
    a.x=65;
    a.y=440;
    a.h=115;
    a.w=98;
    c.x=28;
    c.y=375;
    c.h=200;
    c.w=743;
    d.x=646;
    d.y=393;
    d.h=41;
    d.w=91;
    
    SDL_Texture* background_texture = SDL_CreateTextureFromSurface(screen, image);
    SDL_FreeSurface(image);
    SDL_Texture* play_texture = SDL_CreateTextureFromSurface(screen, player);
    SDL_FreeSurface(player);
    SDL_Texture* talk_texture = SDL_CreateTextureFromSurface(screen, talk);
    SDL_FreeSurface(talk);
    SDL_Texture* button_texture = SDL_CreateTextureFromSurface(screen, button);
    SDL_FreeSurface(button);
    SDL_Texture* sellectbutton_texture = SDL_CreateTextureFromSurface(screen, sellect_button);
    SDL_FreeSurface(sellect_button);
    SDL_RenderCopy(screen, background_texture, NULL, &b);
    SDL_RenderCopy(screen, play_texture, NULL, &b);
    SDL_RenderCopy(screen, talk_texture, NULL, &c);
    SDL_RenderCopy(screen, button_texture, NULL, &d);
    SDL_RenderCopy(screen, sellectbutton_texture, NULL, &b);

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
    textRect.y = 155;
    textRect.w = message_up->w/2;
    textRect.h = message_up->h/2;
    SDL_Rect textRect2;
    textRect2.x = 155;
    textRect2.y = 224;
    textRect2.w = message_middle->w/2;
    textRect2.h = message_middle->h/2;
    SDL_Rect textRect3;
    textRect3.x = 155;
    textRect3.y = 294;
    textRect3.w = message_down->w/2;
    textRect3.h = message_down->h/2;
    SDL_Rect textRect_name;
    textRect_name.x = 88;
    textRect_name.y = 400;
    textRect_name.w = name->w/2;
    textRect_name.h = name->h/2;
    SDL_Rect textRect_pack;
    textRect_pack.x = 671;
    textRect_pack.y = 397;
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
                        if(x>=646&&x<=646+91&&y>=393&&y<=393+41)
                        {
                            int back = backpack(packing.background_image,packing.laptop_image,packing.note_image,packing.ticket_image,packing.laptop_message,packing.note_message,packing.ticket_message,packing.laptop_name,packing.note_name,packing.ticket_name);
                            if(back == 3)
                            {
                                SDL_RenderCopy(screen, background_texture, NULL, &b);
                                SDL_RenderCopy(screen, play_texture, NULL, &b);
                                SDL_RenderCopy(screen, talk_texture, NULL, &c);
                                SDL_RenderCopy(screen, button_texture, NULL, &d);
                                SDL_RenderCopy(screen, sellectbutton_texture, NULL, &b);
    
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
                        else if(x>=138&&x<=660&&y>=285&&y<=322)
                        quit = 3;
                        else if(x>=138&&x<=660&&y>=218&&y<=254)
                        quit = 2;
                        else if(x>=138&&x<=660&&y>=149&&y<=189)
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
    TTF_CloseFont(font);
    TTF_Quit();
    return quit;
}

int SDL_main_screen(char *background_image,int x_position,int y_position,int width,int height)
{
    SDL_Surface *image;
    image = IMG_Load(background_image);
    SDL_Texture* background_texture = SDL_CreateTextureFromSurface(screen, image);
    SDL_FreeSurface(image);
    Player play;
    SDL_Rect b;
    b.x = 0;
    b.y = 0;
    b.h = 600;
    b.w = 800;
    
    play.x = 0;
    play.y = 0;
    play.height = 600;
    play.width = 800;

    //create_player(play,screen,image,b);

    SDL_FlushEvents(SDL_FIRSTEVENT,SDL_LASTEVENT);
    Uint8 alpha = 0;
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
                        
                        if(x>=x_position&&x<=x_position+width&&y>=y_position&&y<=y_position+height)
                        {
                            alpha = 255;
                            while (alpha > 0) {
                                SDL_RenderClear(screen);
                                SDL_SetTextureAlphaMod(background_texture, alpha);
                                SDL_RenderCopy(screen, background_texture, NULL, NULL);
                                SDL_RenderPresent(screen);
                                alpha--;
                            }
                            quit = 1;
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        if (alpha < 255) {
            SDL_RenderClear(screen);
            SDL_SetTextureAlphaMod(background_texture, alpha);
            SDL_RenderCopy(screen, background_texture, NULL, NULL);
            SDL_RenderPresent(screen);
            alpha++;
        }
        SDL_Delay(5);
    }
    
    
    
    return quit;
}


// int main(int argc, char* args[]) 
// {
//     char *in="classroom.png";
//     char *in2="chi.png";
//     char *in3="憨憨憨憨!憨憨憨憨!憨憨憨憨!憨憨憨憨!憨憨憨憨!憨憨憨憨!憨憨憨憨!憨憨憨憨!";
//     char *in4="嗨!!我是LU";
//     char *in5="嗨!!我是SDMH";
//     char *in6="大仙chang";
//     Backpack back;
//     char *in7="backpack.png";
//     char *in8=NULL;
//     char *in9="note.png";
//     char *in10="ticket.png";
//     back.background_image = "backpack.png";
//     back.laptop_image = NULL;
//     back.note_image = "note.png";
//     back.ticket_image = "ticket.png";
//     back.laptop_message = NULL;
//     back.note_message = NULL;
//     back.ticket_message= NULL;
//     back.laptop_name = NULL;
//     back.note_name = NULL;
//     back.ticket_name= NULL;

//     int i;
//     window = SDL_CreateWindow( "fin_project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN );
//     screen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
//     i=SDL_main_screen("menu.png",120,460,220,90);
//     if(i==4)
//     {
//         SDL_DestroyRenderer(screen);
//         SDL_DestroyWindow(window);
//         SDL_Quit();
//         return 0;
//     }
//     i = SDL_no_choice_one_character(in,in2,in3,in6,back,"head_chi.png");
//     if(i==4)
//     {
//         SDL_DestroyRenderer(screen);
//         SDL_DestroyWindow(window);
//         SDL_Quit();
//         return 0;
//     }
//     else
//     {
//         i = SDL_choice_one_character(in,in2,in3,in4,in5,in6,back);
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
