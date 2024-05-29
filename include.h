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
    input->name = NULL;
    free(input->background);
    input->background = NULL;
    free(input->backpack_icon);
    input->backpack_icon = NULL;
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
    input->dialog_box = NULL;
    free(input->next);
    input->next = NULL;
    for (int32_t i = 0; i < 100; i++){
        free(input->speaker[i]);
        input->speaker[i] = NULL;
        free(input->text[i]);
        input->text[i] = NULL;
    }
    free(input->speaker);
    input->speaker = NULL;
    free(input->text);
    input->text = NULL;
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
    input->option_box = NULL;
    free(input->object);
    input->object = NULL;
    free(input->option1);
    input->option1 = NULL;
    free(input->next1);
    input->next1 = NULL;
    free(input->option2);
    input->option2 = NULL;
    free(input->next2);
    input->next2 = NULL;
    free(input->option3);
    input->option3 = NULL;
    free(input->next3);
    input->next3 = NULL;
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
    input->description_box = NULL;
    for (int32_t i = 0; i < 9; i++){
        free(input->name[i]);
        input->name[i] = NULL;
        free(input->photo[i]);
        input->photo[i] = NULL;
        free(input->description[i]);
        input->description[i] = NULL;
    }
    free(input->name);
    input->name = NULL;
    free(input->photo);
    input->photo = NULL;
    free(input->description);
    input->description = NULL;
}