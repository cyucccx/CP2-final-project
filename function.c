#include "include.h"

void free_select(sSelect *input){
    free(input->background);
    input->background = NULL;
    free(input->name1);
    input->name1 = NULL;
    free(input->name2);
    input->name2 = NULL;
    free(input->name3);
    input->name3 = NULL;
    free(input->name4);
    input->name4 = NULL;
    free(input->name5);
    input->name5 = NULL;
    free(input->avatar1);
    input->avatar1 = NULL;
    free(input->avatar2);
    input->avatar2 = NULL;
    free(input->avatar3);
    input->avatar3 = NULL;
    free(input->avatar4);
    input->avatar4 = NULL;
    free(input->avatar5);
    input->avatar5 = NULL;
}

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

void allocate_FinalReply(sFinalReply *input){
    input->option_box = calloc(100, sizeof(char));
    input->object1 = calloc(100, sizeof(char));
    input->option1 = calloc(100, sizeof(char));
    input->good_next1 = calloc(100, sizeof(char));
    input->bad_next1 = calloc(100, sizeof(char));
    input->change_favor1 = 0;
    input->favor_threshold1 = 0;
    input->object2 = calloc(100, sizeof(char));
    input->option2 = calloc(100, sizeof(char));
    input->good_next2 = calloc(100, sizeof(char));
    input->bad_next2 = calloc(100, sizeof(char));
    input->change_favor2 = 0;
    input->favor_threshold2 = 0;
    input->object3 = calloc(100, sizeof(char));
    input->option3 = calloc(100, sizeof(char));
    input->good_next3 = calloc(100, sizeof(char));
    input->bad_next3 = calloc(100, sizeof(char));
    input->change_favor3 = 0;
    input->favor_threshold3 = 0;
}

void free_FinalReply(sFinalReply *input){
    free(input->option_box);
    input->option_box = NULL;
    free(input->object1);
    input->object1 = NULL;
    free(input->option1);
    input->option1 = NULL;
    free(input->good_next1);
    input->good_next1 = NULL;
    free(input->bad_next1);
    input->bad_next1 = NULL;
    free(input->object2);
    input->object2 = NULL;
    free(input->option2);
    input->option2 = NULL;
    free(input->good_next2);
    input->good_next2 = NULL;
    free(input->bad_next2);
    input->bad_next2 = NULL;
    free(input->object1);
    input->object3 = NULL;
    free(input->option3);
    input->option3 = NULL;
    free(input->good_next3);
    input->good_next3 = NULL;
    free(input->bad_next3);
    input->bad_next3 = NULL;
}
