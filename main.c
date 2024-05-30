#include "include.h"

// main and home is set the biggest problem is scene part...
// remember to free the memory!!!!!
// don't read the sentence which is commented
// if max_character < real number -> segmentation fault, plz resolve ;;


int32_t getstring(char *string, char **var_name){
    char *start = strstr(string, "\"")+1;
    if (start == NULL){
        return -1;
    }
    char *end = strstr(start+1, "\"");
    if (end == NULL){
        return -1;
    }
    *end = '\0';
    *var_name = calloc(end-start, sizeof(char));
    strcpy(*var_name, start);
    return 0;
}

int main(){
    FILE *script = fopen("script.toml", "r");
    char buffer[500] = {0};
    char *project_name;
    char *author;
    int32_t home = 0;
    char *home_background = 0;
    char *home_button = 0;
    char *backpack_background = 0;
    int32_t max_character = 0; // create an array to store the favor of every character
    sScene scene;
    allocate_scene(&scene);
    sCharacter *character;
    int32_t count_character = 0;
    int32_t index = 0;
    sDialogue dialogue;
    allocate_dialogue(&dialogue);
    sReply reply;
    allocate_reply(&reply);
    sBackpack backpack;
    allocate_backpack(&backpack);
    int32_t string_index = 0;
    int32_t backpack_index = 0;
    char *search_event = NULL;
    window = SDL_CreateWindow( "fin_project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN );
    screen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    while(fgets(buffer, 500, script) != 0){
        if (strcmp(buffer, "\n") == 0 && home == 1){
            home = 0;
            continue;
        }
        // printf("%s", buffer);
        if (strstr(buffer, "project_name") != 0){
            if (getstring(buffer, &project_name) == -1){
                // wrong
            }
            printf("%s\n", project_name);
        }
        else if (strstr(buffer, "author") != 0){
            if (getstring(buffer, &author) == -1){
                // wrong
            }
            printf("%s\n", author);
        }
        // read home
        if (strstr(buffer, "[home]") != 0){
            home = 1;
            continue;
        }
        if (home == 1){
            // printf("%s", buffer);
            if (home_background == 0){
                if (getstring(buffer, &home_background) == -1){
                    // wrong
                }
                printf("%s\n", home_background);
            }
            else if (home_button == 0){
                if (getstring(buffer, &home_button) == -1){
                    // wrong
                }
                printf("%s\n", home_button);
            }
            else if (backpack_background == 0){
                if (getstring(buffer, &backpack_background) == -1){
                    // wrong
                }
                printf("%s\n", backpack_background);
            }
            else if (max_character == 0){
                if (strstr(buffer, "max_character") != 0){
                    char *start = strstr(buffer, "=");
                    int32_t START = start-buffer;
                    for (int32_t i = START; buffer[i] != '\n'; i++){
                        if (buffer[i] >= 48 && buffer[i] < 57){
                            if (buffer[i+1] >= 48 && buffer[i+1] < 57){
                                max_character = (buffer[i]-48)*10 + buffer[i+1]-48;
                                break;
                            }
                            else{
                                max_character = buffer[i]-48;
                                break;
                            }
                        }
                    }
                    character = calloc(max_character, sizeof(sCharacter));
                    for (int32_t i = 0; i < max_character; i++){
                        character[i].name = calloc(100, sizeof(char));
                        character[i].photo = calloc(100, sizeof(char));
                        character[i].favor = 0;
                    }
                }
                printf("%d\n", max_character);
            }
        }
        // read event
        // search event code
        if (search_event != NULL){
            if (strstr(buffer, search_event) != 0 && buffer[0] == '['){
                if (scene.name != NULL){
                    free_scene(&scene);
                }
                allocate_scene(&scene);
                strcpy(scene.name, search_event);
                search_event = NULL;
            }
            else{
                continue;
            }
        }
        else if (buffer[0] == '[' && home == 0 && buffer[1] != '['){
            if (scene.name != NULL){
                printf("%s\n", scene.name);
                printf("137\n");
                free_scene(&scene);
            }
            allocate_scene(&scene);
            char *end = strstr(buffer, "]");
            *end = '\0';
            strcpy(scene.name, buffer+1);
            printf("%s\n", scene.name);
        }
        // printf("%d:%d %d %d\n", scene_number, scene[scene_number].dialogue, scene[scene_number].reply, scene[scene_number].backpack);
        if (scene.dialogue == 0 && scene.reply == 0 && scene.backpack == 0){
            // printf("%s\n", scene[scene_number].background);
            if (scene.background != 0){
                if (strstr(buffer, "background") != 0){
                    getstring(buffer, &scene.background);
                    printf("%s\n", scene.background);
                }
            }
            if (scene.backpack_icon != 0){
                if (strstr(buffer, "backpack_icon") != 0){
                    getstring(buffer, &scene.backpack_icon);
                    printf("%s\n", scene.backpack_icon);
                }
            }
            if (scene.character_number == 0){
                if (strstr(buffer, "character_number") != 0){
                    char *start = strstr(buffer, "=");
                    int32_t START = start-buffer;
                    for (int32_t i = START; buffer[i] != '\n'; i++){
                        if (buffer[i] >= 48 && buffer[i] < 57){
                            scene.character_number = buffer[i]-48;
                            break;
                        }
                    }
                    index = scene.character_number;
                    printf("character_number = %d\n", scene.character_number);
                }
            }
            if (index > 0){
                int32_t character_index = 0;
                int32_t check = 0;
                if (strstr(buffer, "name") != 0){
                    char *temp = 0;
                    getstring(buffer, &temp);
                    for (int32_t i = 0; i < count_character; i++){
                        if (strcmp(character[i].name, temp) == 0){
                            check = 1;
                            character_index = i;
                            break;
                        }
                    }
                    if (check == 0){
                        if (count_character == max_character){
                            // wrong
                        }
                        character_index = count_character;
                        strncpy(character[count_character].name, temp, 100);
                    }
                    printf("%s\n", character[character_index].name);
                }
                else if (strstr(buffer, "photo") != 0){
                    if (check == 0){
                        character_index = count_character;
                        getstring(buffer, &character[character_index].photo);
                        printf("%s\n", character[character_index].photo);
                        if (strcmp(character[character_index].photo, "null") == 0){
                            // switch to no photo function
                        }
                        count_character++;
                    }
                    index--;
                }
                
            }
        }
        if (buffer[0] == '[' && buffer[1] == '[' && home == 0){
            if (strstr(buffer, scene.name) != 0){
                if (strstr(buffer, "backpack") != 0){
                    backpack_index = 0;
                    scene.backpack = 1;
                    if (backpack.description_box != NULL){
                        free_backpack(&backpack);
                    }
                    allocate_backpack(&backpack);
                }
                else if (strstr(buffer, "dialogue") != 0){
                    string_index = 0;
                    scene.dialogue = 1;
                    if (dialogue.dialog_box != NULL){
                        free_dialogue(&dialogue);
                    }
                    allocate_dialogue(&dialogue);
                }
                else if (strstr(buffer, "reply") != 0){
                    scene.reply = 1;
                    if (reply.option_box != NULL){
                        free_reply(&reply);
                    }
                    allocate_reply(&reply);
                }
            }
            if (scene.reply > 0 && scene.dialogue == 0){
                printf("wrong\n");
                return 0;
                // wrong
            }
            // printf("%d %d %d\n", scene[scene_number].dialogue, scene[scene_number].reply, scene[scene_number].backpack);
        }

        // read backpack
        if (scene.backpack == 1){
            if (strstr(buffer, "items_number") != 0){
                char *start = strstr(buffer, "=");
                int32_t START = start-buffer;
                for (int32_t i = START; buffer[i] != '\n'; i++){
                    if (buffer[i] >= 48 && buffer[i] < 57){
                        backpack.items_number = buffer[i]-48;
                        break;
                    }
                }
                printf("%d\n", backpack.items_number);
            }
            if (strstr(buffer, "description_box") != 0){
                getstring(buffer, &backpack.description_box);
                printf("%s\n", backpack.description_box);
            }
            if (backpack_index < backpack.items_number){
                if (strstr(buffer, "name") != 0){
                    getstring(buffer, &backpack.name[backpack_index]);
                    printf("%s\n", backpack.name[backpack_index]);
                }
                else if(strstr(buffer, "photo") != 0){
                    getstring(buffer, &backpack.photo[backpack_index]);
                    printf("%s\n", backpack.photo[backpack_index]);
                }
                else if(strstr(buffer, "description") != 0 && strstr(buffer, "description_box") == 0){
                    getstring(buffer, &backpack.description[backpack_index]);
                    printf("%s\n", backpack.description[backpack_index]);
                    backpack_index++;
                }
            }
            // if (backpack.description_box != NULL && backpack_index == backpack.items_number && backpack_index != 0){
            //     free_backpack(&backpack);
            //     free_scene(&scene);
            // }
        }
        
        // read dialogue
        if (scene.dialogue == 1){
            if (strstr(buffer, "dialog_box") != 0){
                getstring(buffer, &dialogue.dialog_box);
                printf("%s\n", dialogue.dialog_box);
            }
            if (strstr(buffer, "string_number") != 0){
                char *start = strstr(buffer, "=");
                int32_t START = start-buffer;
                for (int32_t i = START; buffer[i] != '\n'; i++){
                    if (buffer[i] >= 48 && buffer[i] < 57){
                        if (buffer[i+2] >= 48 && buffer[i+2] < 57){
                            dialogue.string_number = (buffer[i]-48)*100 + (buffer[i+1]-48)*10 + buffer[i+2]-48;
                            break;
                        }
                        else if (buffer[i+1] >= 48 && buffer[i+1] < 57){
                            dialogue.string_number = (buffer[i]-48)*10 + buffer[i+1]-48;
                            break;
                        }
                        else{
                            dialogue.string_number = buffer[i]-48;
                            break;
                        }
                    }
                }
                printf("%d\n", dialogue.string_number);
            }
            if (string_index < dialogue.string_number){
                if (strstr(buffer, "speaker") != 0){
                    getstring(buffer, &dialogue.speaker[string_index]);
                    printf("%s\n", dialogue.speaker[string_index]);
                }
                else if (strstr(buffer, "text") != 0){
                    getstring(buffer, &dialogue.text[string_index]);
                    printf("%s\n", dialogue.text[string_index]);
                    string_index++;
                }
            }
            if (strstr(buffer, "next") != 0 && scene.reply == 0){
                getstring(buffer, &dialogue.next);
                if (strstr(dialogue.next, "null") == 0){
                    search_event = calloc(100, sizeof(char));
                    strcpy(search_event, dialogue.next);
                }
                /*
                for(int i=0;i<dialogue.string_number;i++)
                {
                    for(int j=0;j<scene.character_number;j++)
                    {
                        if(strcmp(dialogue.speaker[i],character[j].name)==0 )
                        {
                            int end = SDL_no_choice_one_character(scene.background,character[j].photo,dialogue.text[i],character[j].name);
                            if(end==1)
                            {
                                SDL_DestroyRenderer(screen);
                                SDL_DestroyWindow(window);
                                SDL_Quit();
                                for (int32_t i = 0; i < 1001; i++) {
                                    free_scene(&scene);
                                }
                                return 0;
                            }
                        }
                    }
                }
                */
                if (dialogue.dialog_box != NULL){
                    free_dialogue(&dialogue);
                }
            }
        }

        // read reply
        if (scene.reply == 1){
            int32_t object_number = -1;
            if (strstr(buffer, "option_box") != 0){
                getstring(buffer, &reply.option_box);
                printf("%s\n", reply.option_box);
            }
            else if (strstr(buffer, "object") != 0){
                getstring(buffer, &reply.object);
                for (int32_t i = 0; i < count_character; i++){
                    if (strcmp(reply.object, character[i].name) == 0){
                        object_number = i;
                        break;
                    }
                }
                if (object_number == -1){
                    // wrong
                }
                printf("%s\n", reply.object);
            }
            else if (strstr(buffer, "option1") != 0){
                getstring(buffer, &reply.option1);
                printf("%s\n", reply.option1);
            }
            else if (strstr(buffer, "change_favor1") != 0){
                char *start = strstr(buffer, "=");
                int32_t START = start-buffer;
                for (int32_t i = START; buffer[i] != '\n'; i++){
                    if (buffer[i] == 43){
                        reply.change_favor1 = buffer[i+1]-48;
                        break;
                    }
                    else if (buffer[i] == 45){
                        reply.change_favor1 = -(buffer[i+1]-48);
                        break;
                    }
                    else if (buffer[i] >= 48 && buffer[i] < 57){
                        reply.change_favor1 = buffer[i]-48;
                        break;
                    }
                }
                printf("%d\n", reply.change_favor1);
                // if player choose option 1
                // character[object_number].favor += reply.change_favor1;
                // if (character[object_number].favor > 100){
                //     character[object_number].favor = 100;
                // }
                // else if (character[object_number].favor < 0){
                //     character[object_number].favor = 0;
                // }
            }
            else if (strstr(buffer, "next1") != 0){
                getstring(buffer, &reply.next1);
                printf("%s\n", reply.next1);
                // switch to next1 event
                // if player choose option1
                search_event = calloc(100, sizeof(char));
                strcpy(search_event, reply.next1);
            }
            else if (strstr(buffer, "option2") != 0){
                getstring(buffer, &reply.option2);
                printf("%s\n", reply.option2);
            }
            else if (strstr(buffer, "change_favor2") != 0){
                char *start = strstr(buffer, "=");
                int32_t START = start-buffer;
                for (int32_t i = START; buffer[i] != '\n'; i++){
                    if (buffer[i] == 43){
                        reply.change_favor2 = buffer[i+1]-48;
                        break;
                    }
                    else if (buffer[i] == 45){
                        reply.change_favor2 = -(buffer[i+1]-48);
                        break;
                    }
                    else if (buffer[i] >= 48 && buffer[i] < 57){
                        reply.change_favor2 = buffer[i]-48;
                        break;
                    }
                }
                printf("%d\n", reply.change_favor2);
                // if player choose option 2
                // character[object_number].favor += reply.change_favor2;
                // if (character[object_number].favor > 100){
                //     character[object_number].favor = 100;
                // }
                // else if (character[object_number].favor < 0){
                //     character[object_number].favor = 0;
                // }
            }
            else if (strstr(buffer, "next2") != 0){
                getstring(buffer, &reply.next2);
                printf("%s\n", reply.next2);
                // switch to next2 event
                // if player choose option2
                // search_event = calloc(100, sizeof(char));
                // strcpy(search_event, reply.next2);
            }
            else if (strstr(buffer, "option3") != 0){
                getstring(buffer, &reply.option3);
                printf("%s\n", reply.option3);
            }
            else if (strstr(buffer, "change_favor3") != 0){
                char *start = strstr(buffer, "=");
                int32_t START = start-buffer;
                for (int32_t i = START; buffer[i] != '\n'; i++){
                    if (buffer[i] == 43){
                        reply.change_favor3 = buffer[i+1]-48;
                        break;
                    }
                    else if (buffer[i] == 45){
                        reply.change_favor3 = -(buffer[i+1]-48);
                        break;
                    }
                    else if (buffer[i] >= 48 && buffer[i] < 57){
                        reply.change_favor3 = buffer[i]-48;
                        break;
                    }
                }
                printf("%d\n", reply.change_favor3);
                // if player choose option 3
                // character[object_number].favor += reply.change_favor3;
                // if (character[object_number].favor > 100){
                //     character[object_number].favor = 100;
                // }
                // else if (character[object_number].favor < 0){
                //     character[object_number].favor = 0;
                // }
            }
            else if (strstr(buffer, "next3") != 0){
                getstring(buffer, &reply.next3);
                printf("%s\n", reply.next3);
                // switch to next3 event
                // if player choose option3
                // search_event = calloc(100, sizeof(char));
                // strcpy(search_event, reply.next3);
                if (reply.option_box != NULL){
                    free_reply(&reply);
                }
            }
        }
    }
    fclose(script);
}
