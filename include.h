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
    int32_t number;
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
    char *option1;
    char *next1;
    char *option2;
    char *next2;
    char *option3;
    char *next3;
}sReply;

typedef struct backpack{
    int32_t items_number;
    char **name;
    char **photo;
    char **description;
}sBackpack;

typedef struct character{
    char *name;
    char *photo;
    int32_t favor;
}sCharacter;

void allocate_scene(sScene *input){
    input->name = calloc(100, sizeof(sScene));
    input->background = calloc(100, sizeof(sScene));
    input->backpack_icon = calloc(100, sizeof(sScene));
    input->character_number = 0;
    input->dialogue = 0;
    input->reply = 0;
    input->backpack = 0;
}

void free_scene(sScene *input){
    free(input->name);
    free(input->background);
    free(input->backpack_icon);
}

void allocate_dialogue(sDialogue *input){
    input->dialog_box = calloc(100, sizeof(char));
    input->string_number = 0;
    input->speaker = calloc(100, sizeof(char *));
    input->text = calloc(100, sizeof(char *));
    input->next = calloc(100, sizeof(char *));
    for (int32_t i = 0; i < 100; i++){
        input->speaker[i] = calloc(100, sizeof(char));
        input->text[i] = calloc(100, sizeof(char));
    }
}

void free_dialogue(sDialogue *input){
    free(input->dialog_box);
    free(input->next);
    for (int32_t i = 0; i < 100; i++){
        free(input->speaker[i]);
        free(input->text[i]);
    }
    free(input->speaker);
    free(input->text);
}

void allocate_reply(sReply *input){
    input->option_box = calloc(100, sizeof(char));
    input->object = calloc(100, sizeof(char));
    input->option1 = calloc(100, sizeof(char));
    input->next1 = calloc(100, sizeof(char));
    input->change_favor1 = 0;
    input->option2 = calloc(100, sizeof(char));
    input->next2 = calloc(100, sizeof(char));
    input->change_favor2 = 0;
    input->option3 = calloc(100, sizeof(char));
    input->next3 = calloc(100, sizeof(char));
    input->change_favor3 = 0;
}

void free_reply(sReply *input){
    free(input->option_box);
    free(input->object);
    free(input->option1);
    free(input->next1);
    free(input->option2);
    free(input->next2);
    free(input->option3);
    free(input->next3);
}

void allocate_backpack(sBackpack *input){
    input->items_number = 0;
    input->description_box = calloc(100, sizeof(char));
    input->name = calloc(9, sizeof(char *));
    input->photo = calloc(9, sizeof(char *));
    input->description = calloc(9, sizeof(char *));
    for (int32_t i = 0; i < 9; i++){
        input->name[i] = calloc(100, sizeof(char));
        input->photo[i] = calloc(100, sizeof(char));
        input->description = calloc(100, sizeof(char));
    }
}

void free_backpack(sBackpack *input){
    free(input->description_box);
    for (int32_t i = 0; i < 9; i++){
        free(input->name[i]);
        free(input->photo[i]);
        free(input->description[i]);
    }
    free(input->name);
    free(input->photo);
    free(input->description);
}
