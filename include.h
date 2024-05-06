#pragma once

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

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

void allocate(sScene *input){
    input->name = calloc(500, sizeof(sScene));
    input->background = calloc(500, sizeof(sScene));
    input->backpack_icon = calloc(500, sizeof(sScene));
    input->character_number = 0;
    input->dialogue = 0;
    input->reply = 0;
    input->backpack = 0;
}