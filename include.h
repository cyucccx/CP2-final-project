#pragma once

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

extern SDL_Window* window;
extern SDL_Renderer* screen;

typedef struct
{
    double x,y;
    int width,height;
    SDL_Texture *texture;
}Player;

void create_player(Player play, SDL_Renderer *render, SDL_Surface *image, SDL_Rect a);

int SDL_no_choice_one_character(char *background_image, char *character_image, char *character_message, char *character_name);

int SDL_choice_one_character(char *background_image, char *character_image,char *sellect_button_message_up,char *sellect_button_message_middle,char *sellect_button_message_down);


typedef struct scene{
    char *name;
    char *background;
    char *backpack_icon;
    int32_t character_number;
    int32_t dialogue;
    int32_t reply;
    int32_t backpack;
}sScene;

typedef struct dialogue{
    char *dialog_box;
    int32_t string_number;
    char **speaker;
    char **text;
    char *next;
}sDialogue;

typedef struct reply{
    char *option_box;
    char *object;
    char *option1;
    char *next1;
    int32_t change_favor1;
    char *option2;
    char *next2;
    int32_t change_favor2;
    char *option3;
    char *next3;
    int32_t change_favor3;
}sReply;

typedef struct final_reply{
    char *option_box;
    char *object1;
    char *option1;
    char *good_next1;
    char *bad_next1;
    int32_t change_favor1;
    int32_t favor_threshold1;
    char *object2;
    char *option2;
    char *good_next2;
    char *bad_next2;
    int32_t change_favor2;
    int32_t favor_threshold2;
    char *object3;
    char *option3;
    char *good_next3;
    char *bad_next3;
    int32_t change_favor3;
    int32_t favor_threshold3;
}sFinalReply;

typedef struct backpack{
    int32_t items_number;
    char *description_box;
    char **name;
    char **photo;
    char **description;
}sBackpack;

typedef struct character{
    char *name;
    char *photo;
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
