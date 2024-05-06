#include "include.h"

// main and home is set the biggest problem is scene part...
// remember to free the memory

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
    // 不可以隨便在pointer + 數值 如果讀到空行再加會爆掉 segmentation fault
    char buffer[500] = {0};
    char *project_name;
    char *author;
    int32_t home = 0;
    char *home_background = 0;
    char *home_button = 0;
    char *backpack_background = 0;
    int32_t scene_number = -1; // 0-1000
    sScene scene[1001];
    for (int32_t i = 0; i < 1001; i++){
        allocate(&scene[i]);
    }
    sCharacter character[3];
    int32_t index = 0;
    sDialogue dialogue;
    sReply reply;
    sBackpack backpack;
    backpack.items_number = 0;
    int32_t string_index = 0;
    int32_t backpack_index = 0;

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
            // printf("%s\n", project_name);
        }
        else if (strstr(buffer, "author") != 0){
            if (getstring(buffer, &author) == -1){
                // wrong
            }
            // printf("%s\n", author);
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
                // printf("%s\n", home_background);
            }
            else if (home_button == 0){
                if (getstring(buffer, &home_button) == -1){
                    // wrong
                }
                // printf("%s\n", home_button);
            }
            else if (backpack_background == 0){
                if (getstring(buffer, &backpack_background) == -1){
                    // wrong
                }
            }
            // printf("%s\n", home_background);
            // printf("%s\n", home_button);
            // printf("%s\n", backpack_background);
        }
        // read event
        if (buffer[0] == '[' && home == 0 && buffer[1] != '['){
            scene_number++;
            char *end = strstr(buffer, "]");
            *end = '\0';
            strcpy(scene[scene_number].name, buffer+1);
            // printf("%s\n", scene[scene_number].name);
        }
        // printf("%d:%d %d %d\n", scene_number, scene[scene_number].dialogue, scene[scene_number].reply, scene[scene_number].backpack);
        if (scene[scene_number].dialogue == 0 && scene[scene_number].reply == 0 && scene[scene_number].backpack == 0){
            // printf("%s\n", scene[scene_number].background);
            if (scene[scene_number].background != 0){
                if (strstr(buffer, "background") != 0){
                    getstring(buffer, &scene[scene_number].background);
                    printf("%s\n", scene[scene_number].background);
                }
            }
            if (scene[scene_number].backpack_icon != 0){
                if (strstr(buffer, "backpack_icon") != 0){
                    getstring(buffer, &scene[scene_number].backpack_icon);
                    printf("%s\n", scene[scene_number].backpack_icon);
                }
            }
            if (scene[scene_number].character_number == 0){
                if (strstr(buffer, "character_number") != 0){
                    char *start = strstr(buffer, "=");
                    int32_t START = start-buffer;
                    for (int32_t i = START; buffer[i] != '\n'; i++){
                        if (buffer[i] >= 48 && buffer[i] < 57){
                            scene[scene_number].character_number = buffer[i]-48;
                            break;
                        }
                    }
                    for (int32_t i = 0; i < 3; i++){
                        character[i].name = calloc(50, sizeof(char));
                        character[i].photo = calloc(50, sizeof(char));
                    }
                    index = scene[scene_number].character_number;
                    printf("character_number = %d\n", scene[scene_number].character_number);
                }
            }
            if (index > 0){
                if (strstr(buffer, "name") != 0){
                    getstring(buffer, &character[3-index].name);
                    printf("%s\n", character[3-index].name);
                }
                else if (strstr(buffer, "photo") != 0){
                    getstring(buffer, &character[3-index].photo);
                    printf("%s\n", character[3-index].photo);
                }
                else if (strstr(buffer, "favor") != 0){
                    char *start = strstr(buffer, "=");
                    int32_t START = start-buffer;
                    for (int32_t i = START; buffer[i] != '\n'; i++){
                        if (buffer[i] == 43 || buffer[i] == 45){
                            if (buffer[i+2] >= 48 && buffer[i+2] < 57){
                                printf("%d", buffer[i+2]);
                                character[3-index].favor = (buffer[i+1]-48)*10 + buffer[i+2]-48;
                            }
                            else{
                                character[3-index].favor = buffer[i+1]-48;
                            }
                            if (buffer[i] == 45){
                                character[3-index].favor = -character[3-index].favor;
                            }
                            break;
                        }
                    }
                    printf("favor = %d\n", character[3-index].favor);
                    index--;
                }
            }
        }
        if (buffer[0] == '[' && buffer[1] == '[' && home == 0){
            if (strstr(buffer, scene[scene_number].name) != 0){
                if (strstr(buffer, "dialogue") != 0){
                    string_index = 0;
                    scene[scene_number].dialogue = 1;
                    dialogue.dialog_box = calloc(500, sizeof(char));
                    dialogue.string_number = 0;
                    dialogue.speaker = calloc(100, sizeof(char));
                    dialogue.text = calloc(100, sizeof(char));
                    for (int32_t i = 0; i < 100; i++){
                        dialogue.speaker[i] = calloc(500, sizeof(char *));
                        dialogue.text[i] = calloc(500, sizeof(char *));
                    }
                }
                else if (strstr(buffer, "reply") != 0){
                    scene[scene_number].reply = 1;
                    reply.option1 = calloc(500, sizeof(char));
                    reply.next1 = calloc(500, sizeof(char));
                    reply.option2 = calloc(500, sizeof(char));
                    reply.next2 = calloc(500, sizeof(char));
                    reply.option3 = calloc(500, sizeof(char));
                    reply.next3 = calloc(500, sizeof(char));
                }
                else if (strstr(buffer, "backpack") != 0){
                    backpack_index = 0;
                    scene[scene_number].backpack = 1;
                    backpack.items_number = 0;
                    backpack.name = calloc(9, sizeof(char));
                    backpack.photo = calloc(9, sizeof(char));
                    backpack.description = calloc(9, sizeof(char));
                    for (int32_t i = 0; i < 9; i++){
                        backpack.name[i] = calloc(500, sizeof(char *));
                        backpack.photo[i] = calloc(500, sizeof(char *));
                        backpack.description = calloc(500, sizeof(char *));
                    }
                }
            }
            if (scene[scene_number].reply > 0 && scene[scene_number].dialogue == 0){
                printf("wrong\n");
                return 0;
                // wrong
            }
            // printf("%d %d %d\n", scene[scene_number].dialogue, scene[scene_number].reply, scene[scene_number].backpack);
        }
        // read dialogue
        if (scene[scene_number].dialogue == 1){
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
        }

        // read reply
        if (scene[scene_number].reply == 1){
            if (strstr(buffer, "option1") != 0){
                getstring(buffer, &reply.option1);
                printf("%s\n", reply.option1);
            }
            else if (strstr(buffer, "next1") != 0){
                getstring(buffer, &reply.next1);
                printf("%s\n", reply.next1);
                // switch to next1 event
            }
            else if (strstr(buffer, "option2") != 0){
                getstring(buffer, &reply.option2);
                printf("%s\n", reply.option2);
            }
            else if (strstr(buffer, "next2") != 0){
                getstring(buffer, &reply.next2);
                printf("%s\n", reply.next2);
                // switch to next2 event
            }
            else if (strstr(buffer, "option3") != 0){
                getstring(buffer, &reply.option3);
                printf("%s\n", reply.option3);
            }
            else if (strstr(buffer, "next3") != 0){
                getstring(buffer, &reply.next3);
                printf("%s\n", reply.next3);
                // switch to next3 event
            }
        }

        // read backpack
        if (scene[scene_number].backpack == 1){
            if (strstr(buffer, "items_number") != 0){
                char *start = strstr(buffer, "=");
                int32_t START = start-buffer;
                for (int32_t i = START; buffer[i] != '\n'; i++){
                    if (buffer[i] >= 48 && buffer[i] < 57){
                        backpack.items_number = buffer[i]-48;
                        break;
                    }
                }
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
                else if(strstr(buffer, "description") != 0){
                    getstring(buffer, &backpack.description[backpack_index]);
                    printf("%s\n", backpack.description[backpack_index]);
                    backpack_index++;
                }
            }
        }
    }
}