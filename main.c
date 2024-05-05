#include "include.h"

// main and home is set the biggest problem is scene part...

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
    while(fgets(buffer, 500, script) != 0){
        if (strcmp(buffer, "\n") == 0){
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
            }
            // printf("%s\n", home_background);
            // printf("%s\n", home_button);
            // printf("%s\n", backpack_background);
        }
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
                        if (buffer[i] >= 30 && buffer[i] < 40){
                            scene[scene_number].character_number = buffer[i]-30;
                            break;
                        }
                    }
                    printf("character_number = %d\n", scene[scene_number].character_number);
                }
            }
        }
        // if (buffer[0] == '[' && buffer[1] == '[' && home == 0){
        //     if (strstr(buffer, scene[scene_number].name) != 0){
        //         if (strstr(buffer, "dialogue") != 0){

        //         }
        //     }
        // }
    }
}