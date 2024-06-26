#pragma once

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

extern SDL_Window* window;
extern SDL_Renderer* screen;

typedef struct
{
    double x,y;
    int width,height;
    SDL_Texture *texture;
}Player;

typedef struct Backpack{
    char background_image[100];
    char laptop_image[100];
    char note_image[100];
    char ticket_image[100];
    char laptop_message[1000];
    char note_message[1000];
    char ticket_message[1000];
    char laptop_name[100];
    char note_name[100];
    char ticket_name[100];
}Backpack;

void create_player(Player play, SDL_Renderer *render, SDL_Surface *image, SDL_Rect a);

int backpack(char *background_image, char laptop_image[100],char note_image[100], char ticket_image[100],char *laptop_message,char *note_message,char *ticket_message,char laptop_name[100],char note_name[100],char ticket_name[100]);

int SDL_no_choice_one_character(char *background_image, char *character_image, char *character_message, char *character_name, Backpack packing, char *small_character_image);

int SDL_no_choice_one_character_anime(char *background_image, char *character_image, char *character_message, char *character_name, Backpack packing,char *small_character_image);

int SDL_choice_one_character(char *background_image, char *character_image,char *sellect_button_message_up,char *sellect_button_message_middle,char *sellect_button_message_down, char *character_name, Backpack packing);

int SDL_main_screen(char *background_image,char *start_image,char *load_image,int x_position,int y_position,int width,int height);

int SDL_sellcet_screen(char *character_image1,char *character_image2,char *character_image3,char *character_image4,char *character_image5,char *character_name1,char *character_name2,char *character_name3,char *character_name4,char *character_name5);



typedef struct select{
    char *name1;
    char *name2;
    char *name3;
    char *name4;
    char *name5;
    char *avatar1;
    char *avatar2;
    char *avatar3;
    char *avatar4;
    char *avatar5;
}sSelect;
void free_select(sSelect *input);
typedef struct scene{
    char name[100];
    char background[100];
    int32_t character_number;
    int32_t dialogue;
    int32_t reply;
    int32_t backpack;
}sScene;

typedef struct dialogue{
    int32_t string_number;
    char speaker[250][10000];
    char text[250][10000];
    char next[1000];
}sDialogue;

typedef struct reply{
    char object[100];
    char option1[100];
    char next1[100];
    int32_t change_favor1;
    char option2[100];
    char next2[100];
    int32_t change_favor2;
    char option3[100];
    char next3[100];
    int32_t change_favor3;
}sReply;

typedef struct final_reply{
    char object1[100];
    char option1[100];
    char good_next1[100];
    char bad_next1[100];
    int32_t change_favor1;
    int32_t favor_threshold1;
    char object2[100];
    char option2[100];
    char good_next2[100];
    char bad_next2[100];
    int32_t change_favor2;
    int32_t favor_threshold2;
    char object3[100];
    char option3[100];
    char good_next3[100];
    char bad_next3[100];
    int32_t change_favor3;
    int32_t favor_threshold3;
}sFinalReply;

typedef struct backpack{
    int32_t items_number;
    char name[25][100];
    char photo[25][100];
    char description[25][1000];
}sBackpack;

typedef struct character{
    char name[100];
    char photo[100];
    char avatar[100];
    int32_t favor;
}sCharacter;

void allocate_scene(sScene *input);

void free_scene(sScene *input);

void allocate_dialogue(sDialogue *input);

void free_dialogue(sDialogue *input);

void allocate_reply(sReply *input);

void free_reply(sReply *input);

void allocate_backpack(sBackpack *input);

void free_backpack(sBackpack *input);

void allocate_FinalReply(sFinalReply *input);

void free_FinalReply(sFinalReply *input);
