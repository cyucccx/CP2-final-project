#include "include.h"

// main and home is set the biggest problem is scene part...
// remember to free the memory!!!!!
// don't read the sentence which is commented
// if max_character < real number -> segmentation fault, plz resolve ;;

int32_t getstring(char *string, char **var_name) {
    char *start = strstr(string, "\"");
    if (start == NULL) {
        return -1;
    }
    start++;
    char *end = strstr(start, "\"");
    if (end == NULL) {
        return -1;
    }
    *end = '\0';

    size_t len = end - start + 1; // +1 for the null terminator
    *var_name = calloc(len, sizeof(char));
    if (*var_name == NULL) {
        return -1;
    }
    strcpy(*var_name, start);
    return 0;
}

int main(){
    FILE *script = fopen("script.toml", "r");
    char buffer[500] = {0};
    char *project_name;
    char *author;
    int32_t home = 0;
    int32_t select_character = 0;
    sSelect select;
    char myname[100] = {0};
    char myavatar[100] = {0};
    char *home_background = 0;
    char *home_button = 0;
    int32_t max_character = 0; // create an array to store the favor of every character
    sScene scene;
    scene.name;
    scene.background;
    scene.backpack_icon;
    scene.reply = 0;
    // allocate_scene(&scene);
    sCharacter character[16];
    int32_t count_character = 0;
    int32_t index = 0;
    sDialogue dialogue;
    //allocate_dialogue(&dialogue);
    sReply reply;
    //allocate_reply(&reply);
    sFinalReply final_reply;
    final_reply.option_box;
    sBackpack backpack;
    //allocate_backpack(&backpack);
    int32_t string_index = 0;
    int32_t backpack_index = 0;
    char search_event[100]={0};
    
    int32_t check = 0;
    int32_t character_index = 0;
    int32_t need_anime = 1;
    char compare[100]={0};
    int32_t last_scene = 0;
    char avatar_choose1[100]={0};
    char avatar_choose2[100]={0};
    char avatar_choose3[100]={0};
    char avatar_choose4[100]={0};
    char avatar_choose5[100]={0};
    //compare = calloc(100, sizeof(char));
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
            printf("project name = %s\n", project_name);
        }
        else if (strstr(buffer, "author") != 0){
            if (getstring(buffer, &author) == -1){
                // wrong
            }
            printf("author = %s\n", author);
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
                printf("home_background = %s\n", home_background);
            }
            else if (home_button == 0){
                if (getstring(buffer, &home_button) == -1){
                    // wrong
                }
                printf("home_button = %s\n", home_button);
            }
            else if (max_character == 0){
                if (strstr(buffer, "max_character") != 0){
                    sscanf(buffer,"max_character = %d",&max_character);
                    // char *start = strstr(buffer, "=");
                    // int32_t START = start-buffer;
                    // for (int32_t i = START; buffer[i] != '\n'; i++){
                    //     if (buffer[i] >= 48 && buffer[i] <= 57){
                    //         if (buffer[i+1] >= 48 && buffer[i+1] <= 57){
                    //             max_character = (buffer[i]-48)*10 + buffer[i+1]-48;
                    //             break;
                    //         }
                    //         else{
                    //             max_character = buffer[i]-48;
                    //             break;
                    //         }
                    //     }
                    // }
                    // character = calloc(max_character, sizeof(sCharacter));
                    // for (int32_t i = 0; i < max_character; i++){
                    //     character[i].name = calloc(100, sizeof(char));
                    //     character[i].photo = calloc(100, sizeof(char));
                    //     character[i].avatar = calloc(100, sizeof(char));
                    //     character[i].favor = 0;
                    // }
                }
                printf("max_character = %d\n", max_character);
                int end =SDL_main_screen(home_background,home_button,home_button,120,460,220,90);
                if(end==4 || end == 6)
                {
                    SDL_DestroyRenderer(screen);
                    SDL_DestroyWindow(window);
                    SDL_Quit();
                    return 0;
                }
                if (end == 5 || end == 6){
                    FILE *save = fopen("save.txt", "wb");
                    printf("%s\n", buffer);
                }
            }
        }
        
        // read select character
        if (strstr(buffer, "[select_character]") != 0 && home == 0){
            select_character = 1;
            select.background = NULL;
            select.name1 = NULL;
            select.name2 = NULL;
            select.name3 = NULL;
            select.name4 = NULL;
            select.name5 = NULL;
            select.avatar1 = NULL;
            select.avatar2 = NULL;
            select.avatar3 = NULL;
            select.avatar4 = NULL;
            select.avatar5 = NULL;
            continue;
        }
        if (select_character == 1){
            if (select.background == NULL && strstr(buffer, "background") != 0){
                select.background = calloc(100, sizeof(char));
                sscanf(buffer, "background = \"%[^\"]\"", select.background);
                printf("%s\n", select.background);
            }
            else if (avatar_choose1[0] == 0 && strstr(buffer, "avatar_choose1") != 0){
                sscanf(buffer, "avatar_choose1 = \"%[^\"]\"", avatar_choose1);
                printf("%s\n", avatar_choose1);
            }
            else if (avatar_choose2[0] == 0 && strstr(buffer, "avatar_choose2") != 0){
                sscanf(buffer, "avatar_choose2 = \"%[^\"]\"", avatar_choose2);
                printf("%s\n", avatar_choose2);
            }
            else if (avatar_choose3[0] == 0 && strstr(buffer, "avatar_choose3") != 0){
                sscanf(buffer, "avatar_choose3 = \"%[^\"]\"", avatar_choose3);
                printf("%s\n", avatar_choose3);
            }
            else if (avatar_choose4[0] == 0 && strstr(buffer, "avatar_choose4") != 0){
                sscanf(buffer, "avatar_choose4 = \"%[^\"]\"", avatar_choose4);
                printf("%s\n", avatar_choose4);
            }
            else if (avatar_choose5[0] == 0 && strstr(buffer, "avatar_choose5") != 0){
                sscanf(buffer, "avatar_choose5 = \"%[^\"]\"", avatar_choose5);
                printf("%s\n", avatar_choose5);
            }
            else if (select.name1 == NULL && strstr(buffer, "name1") != 0){
                select.name1 = calloc(100, sizeof(char));
                sscanf(buffer, "name1 = \"%[^\"]\"", select.name1);
                printf("%s\n", select.name1);
            }
            else if (select.name2 == NULL && strstr(buffer, "name2") != 0){
                select.name2 = calloc(100, sizeof(char));
                sscanf(buffer, "name2 = \"%[^\"]\"", select.name2);
                printf("%s\n", select.name2);
            }
            else if (select.name3 == NULL && strstr(buffer, "name3") != 0){
                select.name3 = calloc(100, sizeof(char));
                sscanf(buffer, "name3 = \"%[^\"]\"", select.name3);
                printf("%s\n", select.name3);
            }
            else if (select.name4 == NULL && strstr(buffer, "name4") != 0){
                select.name4 = calloc(100, sizeof(char));
                sscanf(buffer, "name4 = \"%[^\"]\"", select.name4);
                printf("%s\n", select.name4);
            }
            else if (select.name5 == NULL && strstr(buffer, "name5") != 0){
                select.name5 = calloc(100, sizeof(char));
                sscanf(buffer, "name5 = \"%[^\"]\"", select.name5);
                printf("%s\n", select.name5);
            }
            else if (select.avatar1 == NULL && strstr(buffer, "avatar1") != 0){
                select.avatar1 = calloc(100, sizeof(char));
                sscanf(buffer, "avatar1 = \"%[^\"]\"", select.avatar1);
                printf("%s\n", select.avatar1);
            }
            else if (select.avatar2 == NULL && strstr(buffer, "avatar2") != 0){
                select.avatar2 = calloc(100, sizeof(char));
                sscanf(buffer, "avatar2 = \"%[^\"]\"", select.avatar2);
                printf("%s\n", select.avatar2);
            }
            else if (select.avatar3 == NULL && strstr(buffer, "avatar3") != 0){
                select.avatar3 = calloc(100, sizeof(char));
                sscanf(buffer, "avatar3 = \"%[^\"]\"", select.avatar3);
                printf("%s\n", select.avatar3);
            }
            else if (select.avatar4 == NULL && strstr(buffer, "avatar4") != 0){
                select.avatar4 = calloc(100, sizeof(char));
                sscanf(buffer, "avatar4 = \"%[^\"]\"", select.avatar4);
                printf("%s\n", select.avatar4);
            }
            else if (select.avatar5 == NULL && strstr(buffer, "avatar5") != 0){
                select.avatar5 = calloc(100, sizeof(char));
                sscanf(buffer, "avatar5 = \"%[^\"]\"", select.avatar5);
                printf("%s\n", select.avatar5);
                int end = SDL_sellcet_screen(avatar_choose1,avatar_choose2,avatar_choose3,avatar_choose4,avatar_choose5,select.name1,select.name2,select.name3,select.name4,select.name5); // SDL
                if(end==4)
                {
                    SDL_DestroyRenderer(screen);
                    SDL_DestroyWindow(window);
                    SDL_Quit();
                    return 0;
                }
                if (end == 11){
                    strcpy(myname, select.name1);
                    strcpy(myavatar, select.avatar1);
                    // free select
                }
                else if (end == 12){
                    strcpy(myname, select.name2);
                    strcpy(myavatar, select.avatar2);
                    // free select
                }
                else if (end == 13){
                    strcpy(myname, select.name3);
                    strcpy(myavatar, select.avatar3);
                    // free select
                }
                else if (end == 14){
                    strcpy(myname, select.name4);
                    strcpy(myavatar, select.avatar4);
                    // free select
                }
                else if (end == 15){
                    strcpy(myname, select.name5);
                    strcpy(myavatar, select.avatar5);
                    // free select
                }
            }
        }

        // read event
        // search event code
        if (search_event[0] != 0){
            if (strstr(buffer, search_event) != 0 && buffer[0] == '['){
                if (scene.name != NULL){
                    for(int i=0;i<100;i++)
                    {
                        compare[i]=0;
                    }
                    //compare = calloc(100, sizeof(char));
                    
                    if(scene.background[0]!=0)
                    strcpy(compare, scene.background);
                    //free_scene(&scene);
                }
                //allocate_scene(&scene);
                for(int i=0;i<100;i++)
                {
                    scene.background[i]=0;
                    scene.name[i]=0;
                    scene.backpack_icon[i]=0;
                }
                scene.dialogue=0;scene.character_number=0;scene.reply=0;scene.backpack=0;
                char *end = strstr(buffer, "]");
                *end = '\0';
                strcpy(scene.name, buffer+1);
                printf("scene.name = %s\n", scene.name);
                for(int i=0;i<100;i++)
                search_event[i]=0;
                if (last_scene == 1){
                    last_scene++;
                }
            }
            else{
                continue;
            }
        }
        else if (buffer[0] == '[' && home == 0 && buffer[1] != '['){
            if (last_scene > 1){
                break;
            }
            if (scene.name != NULL){
                for(int i=0;i<100;i++)
                {
                    compare[i]=0;
                }
                //compare = calloc(100, sizeof(char));
                if(scene.background!=NULL)
                strcpy(compare, scene.background);
                //free_scene(&scene);
            }
            //allocate_scene(&scene);
            for(int i=0;i<100;i++)
            {
                scene.background[i]=0;
                scene.name[i]=0;
                scene.backpack_icon[i]=0;
            }
            scene.dialogue=0;scene.character_number=0;scene.reply=0;scene.backpack=0;
            char *end = strstr(buffer, "]");
            *end = '\0';
            strcpy(scene.name, buffer+1);
            printf("scene.name = %s\n", scene.name);
        }
        // printf("%s:%d %d %d\n", scene.name, scene.backpack, scene.dialogue, scene.reply);
        if (scene.dialogue == 0 && scene.reply == 0 && scene.backpack == 0){
            if (scene.background[0] == 0){
                printf("%s88\n",buffer);
                
                if (strstr(buffer, "background") != 0){
                    need_anime = 1;printf("%s55\n",compare);
                    sscanf(buffer,"background = \"%[^\"]\"",scene.background);
                    // getstring(buffer, &scene.background);
                    printf("compare = %s\nbackground = %s\n", compare, scene.background);
                    if (compare == NULL){
                        continue;
                    }
                    else if (strcmp(compare, scene.background) == 0){
                        need_anime = 0;
                    }
                    
                    printf("scene.background = %s\n", scene.background);
                }
            }
            if (scene.backpack_icon != 0){
                if (strstr(buffer, "backpack_icon") != 0){
                    sscanf(buffer,"backpack_icon = \"%[^\"]\"",scene.backpack_icon);
                    //getstring(buffer, &scene.backpack_icon);
                    printf("scene.backpack_icon = %s\n", scene.backpack_icon);
                }
            }
            if (scene.character_number == 0){
                if (strstr(buffer, "character_number") != 0){
                    sscanf(buffer,"character_number = %d",&scene.character_number);
                    // char *start = strstr(buffer, "=");
                    // int32_t START = start-buffer;
                    // for (int32_t i = START; buffer[i] != '\n'; i++){
                    //     if (buffer[i] >= 48 && buffer[i] <= 57){
                    //         scene.character_number = buffer[i]-48;
                    //         break;
                    //     }
                    // }
                    index = scene.character_number;
                    printf("character_number = %d\n", scene.character_number);
                }
            }
            if (index > 0){
                if (strstr(buffer, "name") != 0){
                    check = 0;
                    character_index = 0;
                    char temp[100]={0};
                    sscanf(buffer,"name = \"%[^\"]\"",temp);
                    // getstring(buffer, &temp);
                    if (strcmp(temp, "me") == 0){
                        strncpy(temp, myname, strlen(myname));
                    }
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
                        strcpy(character[count_character].name, temp);
                        
                    }
                    printf("character_name = %s\n", character[character_index].name);
                }
                else if (strstr(buffer, "photo") != 0){
                    sscanf(buffer,"photo = \"%[^\"]\"",character[character_index].photo);
                    //getstring(buffer, &character[character_index].photo);
                    if (check == 0){
                        if (strcmp(character[character_index].photo, "null") == 0){
                            // switch to no photo function
                        }
                    }
                    printf("character_photo = %s\n", character[character_index].photo);
                }
                else if (strstr(buffer, "avatar") != 0){
                    sscanf(buffer,"avatar = \"%[^\"]\"",character[character_index].avatar);
                    //getstring(buffer, &character[character_index].avatar);
                    if (strcmp(character[character_index].avatar, "me_avatar") == 0){
                        strncpy(character[character_index].avatar, myavatar, strlen(myavatar));
                    }
                    if (check == 0){
                        if (strcmp(character[character_index].avatar, "null") == 0){
                            // switch to no photo function
                        }
                        count_character++;
                    }
                    printf("avatar = %s\n", character[character_index].avatar);
                    index--;
                }
            }
        }
        if (buffer[0] == '[' && buffer[1] == '[' && home == 0){
            if (strstr(buffer, scene.name) != 0){
                if (strstr(buffer, "dialogue") != 0){
                    string_index = 0;
                    scene.dialogue = 1;
                    // if (dialogue.dialog_box != NULL){
                    //     //free_dialogue(&dialogue);
                    // }
                    for(int i=0;i<100;i++)
                    {
                        dialogue.dialog_box[i]=0;
                        dialogue.next[i]=0;
                    }
                    dialogue.string_number=0;
                    for(int i=0;i<25;i++)
                    {
                        for(int j=0;j<1000;j++)
                        {
                            dialogue.speaker[i][j]=0;
                            dialogue.text[i][j]=0;
                        }
                    }
                }
                else if (strstr(buffer, "reply") != 0){
                    scene.reply = 1;
                    // if (reply.option_box != NULL){
                    //     //free_reply(&reply);
                    // }
                    for(int i=0;i<100;i++)
                    {
                        reply.option_box[i]=0;
                        reply.object[i]=0;
                        reply.option1[i]=0;
                        reply.next1[i]=0;
                        reply.option2[i]=0;
                        reply.next2[i]=0;
                        reply.option3[i]=0;
                        reply.next3[i]=0;
                    }
                    reply.change_favor1=0;reply.change_favor2=0;reply.change_favor3=0;
                    //allocate_reply(&reply);
                }
                else if (strstr(buffer, "backpack") != 0){
                    backpack_index = 0;
                    scene.backpack = 1;
                    // if (backpack.items_number == 0){
                    //     //free_backpack(&backpack);
                    // }
                    for(int i=0;i<25;i++)
                    {
                        for(int j=0;j<100;j++)
                        {
                            backpack.name[i][j]=0;
                            backpack.photo[i][j]=0;
                        }
                    }
                    for(int i=0;i<25;i++)
                    {
                        for(int j=0;j<1000;j++)
                        {
                            backpack.description[i][j]=0;
                        }
                    }
                    backpack.items_number=0;
                    //allocate_backpack(&backpack);
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
                sscanf(buffer,"items_number = %d",&backpack.items_number);
                // char *start = strstr(buffer, "=");
                // int32_t START = start-buffer;
                // for (int32_t i = START; buffer[i] != '\n'; i++){
                //     if (buffer[i] >= 48 && buffer[i] <= 57){
                //         backpack.items_number = buffer[i]-48;
                //         break;
                //     }
                // }
                printf("items_number = %d\n", backpack.items_number);
            }
            if (backpack_index < backpack.items_number){
                if (strstr(buffer, "name") != 0){
                    sscanf(buffer,"name = \"%[^\"]\"",backpack.name[backpack_index]);
                    //getstring(buffer, &backpack.name[backpack_index]);
                    printf("backpackname = %s\n", backpack.name[backpack_index]);
                }
                else if(strstr(buffer, "photo") != 0){
                    sscanf(buffer,"photo = \"%[^\"]\"",backpack.photo[backpack_index]);
                    //getstring(buffer, &backpack.photo[backpack_index]);
                    printf("backpackphoto = %s\n", backpack.photo[backpack_index]);
                }
                else if(strstr(buffer, "description") != 0 && strstr(buffer, "description_box") == 0){
                    sscanf(buffer,"description = \"%[^\"]\"",backpack.description[backpack_index]);
                    //getstring(buffer, &backpack.description[backpack_index]);
                    printf("backpackdescription = %s\n", backpack.description[backpack_index]);
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
                sscanf(buffer,"dialog_box = \"%[^\"]\"",dialogue.dialog_box);
                //getstring(buffer, &dialogue.dialog_box);
                printf("%s\n", dialogue.dialog_box);
            }
            if (strstr(buffer, "string_number") != 0){
                sscanf(buffer,"string_number = %d",&dialogue.string_number);
                // char *start = strstr(buffer, "=");
                // int32_t START = start-buffer;
                // for (int32_t i = START; buffer[i] != '\n'; i++){
                //     if (buffer[i] >= 48 && buffer[i] <= 57){
                //         if (buffer[i+2] >= 48 && buffer[i+2] <= 57){
                //             dialogue.string_number = (buffer[i]-48)*100 + (buffer[i+1]-48)*10 + buffer[i+2]-48;
                //             break;
                //         }
                //         else if (buffer[i+1] >= 48 && buffer[i+1] <= 57){
                //             dialogue.string_number = (buffer[i]-48)*10 + buffer[i+1]-48;
                //             break;
                //         }
                //         else{
                //             dialogue.string_number = buffer[i]-48;
                //             break;
                //         }
                //     }
                // }
                printf("%d\n", dialogue.string_number);
            }
            if (string_index < dialogue.string_number){
                if (strstr(buffer, "speaker") != 0){
                    sscanf(buffer,"speaker = \"%[^\"]\"",dialogue.speaker[string_index]);
                    //getstring(buffer, &dialogue.speaker[string_index]);
                    if (strcmp(dialogue.speaker[string_index], "me") == 0){
                        strncpy(dialogue.speaker[string_index], myname, strlen(myname));
                    }
                    printf("%s\n", dialogue.speaker[string_index]);
                }
                else if (strstr(buffer, "text") != 0){
                    sscanf(buffer,"text = \"%[^\"]\"",dialogue.text[string_index]);
                    //getstring(buffer, &dialogue.text[string_index]);
                    printf("%s\n", dialogue.text[string_index]);
                    string_index++;
                }
            }
            if (strstr(buffer, "next") != 0 && scene.reply == 0){
                sscanf(buffer,"next = \"%[^\"]\"",dialogue.next);
                //getstring(buffer, &dialogue.next);
                Backpack back;
                back.background_image = malloc(256);
                back.background_image="../assets/scene/backpack.png";
                if(backpack.items_number==0)
                {
                    back.laptop_image=NULL;
                    back.laptop_image=NULL;
                    back.laptop_message=NULL;
                    back.laptop_name=NULL;
                    back.note_image=NULL;
                    back.note_message=NULL;
                    back.note_name=NULL;
                    back.ticket_image=NULL;
                    back.ticket_message=NULL;
                    back.ticket_name=NULL;
                }
                else if(backpack.items_number==1)
                {
                    back.laptop_image = malloc(256);
                    strcpy(back.laptop_image,backpack.photo[0]);
                    back.note_image=NULL;//strcpy(back.note_image,backpack.photo[1]);
                    back.ticket_image=NULL;//strcpy(back.ticket_image,backpack.photo[2]);
                    back.laptop_name = malloc(256);
                    strcpy(back.laptop_name,backpack.name[0]);
                    back.note_name=NULL;//strcpy(back.note_name,backpack.name[1]);
                    back.ticket_name=NULL;//strcpy(back.ticket_name,backpack.name[2]);
                    back.laptop_message = malloc(256);
                    strcpy(back.laptop_message,backpack.description[0]);
                    back.note_message=NULL;//strcpy(back.note_message,backpack.description[1]);
                    back.ticket_image=NULL;//strcpy(back.ticket_message,backpack.description[2]);
                }
                else if(backpack.items_number==2)
                {
                    back.laptop_image = malloc(256);
                    back.note_image = malloc(256);
                    strcpy(back.laptop_image,backpack.photo[0]);
                    strcpy(back.note_image,backpack.photo[1]);
                    back.ticket_image=NULL;//strcpy(back.ticket_image,backpack.photo[2]);
                    back.laptop_name = malloc(256);
                    back.note_name = malloc(256);
                    strcpy(back.laptop_name,backpack.name[0]);
                    strcpy(back.note_name,backpack.name[1]);
                    back.ticket_name=NULL;//strcpy(back.ticket_name,backpack.name[2]);
                    back.laptop_message=malloc(256);
                    back.note_message=malloc(256);
                    strcpy(back.laptop_message,backpack.description[0]);
                    strcpy(back.note_message,backpack.description[1]);
                    back.ticket_message=NULL;//strcpy(back.ticket_message,backpack.description[2]);
                }
                else if(backpack.items_number==3)
                {
                    back.laptop_image = malloc(256);
                    back.note_image = malloc(256);
                    back.ticket_image = malloc(256);
                    strcpy(back.laptop_image,backpack.photo[0]);
                    strcpy(back.note_image,backpack.photo[1]);
                    strcpy(back.ticket_image,backpack.photo[2]);
                    back.laptop_name = malloc(256);
                    back.note_name = malloc(256);
                    back.ticket_name = malloc(256);
                    strcpy(back.laptop_name,backpack.name[0]);
                    strcpy(back.note_name,backpack.name[1]);
                    strcpy(back.ticket_name,backpack.name[2]);
                    back.laptop_message=malloc(256);
                    back.note_message=malloc(256);
                    back.ticket_message=malloc(256);
                    strcpy(back.laptop_message,backpack.description[0]);
                    strcpy(back.note_message,backpack.description[1]);
                    strcpy(back.ticket_message,backpack.description[2]);
                }
                for(int i=0;i<dialogue.string_number;i++)
                {
                    for(int j=0;j<count_character;j++)
                    {
                        if(strcmp(dialogue.speaker[i],character[j].name)==0 )
                        {
                            if(need_anime==1)
                            {
                                int end = SDL_no_choice_one_character_anime(scene.background,character[j].photo,dialogue.text[i],character[j].name,back,character[j].avatar);
                                need_anime=0;
                                if(end==4 || end == 6)
                                {
                                    SDL_DestroyRenderer(screen);
                                    SDL_DestroyWindow(window);
                                    SDL_Quit();
                                    return 0;
                                }
                            }
                            else
                            {
                                int end = SDL_no_choice_one_character(scene.background,character[j].photo,dialogue.text[i],character[j].name,back,character[j].avatar);
                                if(end==4 || end == 6)
                                {
                                    SDL_DestroyRenderer(screen);
                                    SDL_DestroyWindow(window);
                                    SDL_Quit();
                                    return 0;
                                }
                                if (end == 5 || end == 6){
                                    FILE *save = fopen("save.txt", "wb");
                                    printf("%s\n\n", buffer);
                                }
                            }
                        }
                    }
                }
                
                if (strstr(dialogue.next, "null") == 0){
                    for(int i=0;i<100;i++)
                    {
                        search_event[i]=0;
                    }
                    strcpy(search_event, dialogue.next);
                }
                if (dialogue.dialog_box != NULL){
                    //free_dialogue(&dialogue);
                }
            }
        }

        // read reply
        int32_t object_number = -1;
        if (scene.name == NULL){
            continue;
        }
        if (strcmp(scene.name, "final_event") == 0 && scene.reply == 1){
            if (final_reply.option_box == NULL){
                //allocate_FinalReply(&final_reply);
            }
            if (strstr(buffer, "option_box") != 0){
                sscanf(buffer,"option_box = \"%[^\"]\"",final_reply.option_box);
                //getstring(buffer, &final_reply.option_box);
                printf("special = %s\n", final_reply.option_box);
            }
            else if (strstr(buffer, "object1") != 0){
                sscanf(buffer,"object1 = \"%[^\"]\"",final_reply.object1);
                //getstring(buffer, &final_reply.object1);
                printf("%s\n", final_reply.object1);
            }
            else if (strstr(buffer, "option1") != 0){
                sscanf(buffer,"option1 = \"%[^\"]\"",final_reply.option1);
                //getstring(buffer, &final_reply.option1);
                printf("option 1 = %s\n", final_reply.option1);
            }
            else if (strstr(buffer, "change_favor1") != 0){
                sscanf(buffer,"change_favor1 = %d",&final_reply.change_favor1);
                // char *start = strstr(buffer, "=");
                // int32_t START = start-buffer;
                // for (int32_t i = START; buffer[i] != '\n'; i++){
                //     if (buffer[i] == 43){
                //         final_reply.change_favor1 = buffer[i+1]-48;
                //         break;
                //     }
                //     else if (buffer[i] == 45){
                //         final_reply.change_favor1 = -(buffer[i+1]-48);
                //         break;
                //     }
                //     else if (buffer[i] >= 48 && buffer[i] <= 57){
                //         final_reply.change_favor1 = buffer[i]-48;
                //         break;
                //     }
                // }
                printf("%d\n", final_reply.change_favor1);
            }
            else if (strstr(buffer, "favor_threshold1") != 0){
                sscanf(buffer,"favor_threshold1 = %d",&final_reply.favor_threshold1);
                // char *start = strstr(buffer, "=");
                // int32_t START = start-buffer;
                // for (int32_t i = START; buffer[i] != '\n'; i++){
                //     if (buffer[i] >= 48 && buffer[i] <= 57){
                //         if (buffer[i+1] >= 48 && buffer[i+1] <= 57){
                //             final_reply.favor_threshold1 = (buffer[i]-48)*10 + buffer[i+1]-48;
                //             break;
                //         }
                //         else{
                //             final_reply.favor_threshold1 = buffer[i]-48;
                //             break;
                //         }
                //     }
                // }
                printf("%d\n", final_reply.favor_threshold1);
            }
            else if (strstr(buffer, "good_next1") != 0){
                sscanf(buffer,"good_next1 = \"%[^\"]\"",final_reply.good_next1);
                //getstring(buffer, &final_reply.good_next1);
                printf("%s\n", final_reply.good_next1);
            }
            else if (strstr(buffer, "bad_next1") != 0){
                sscanf(buffer,"bad_next1 = \"%[^\"]\"",final_reply.bad_next1);
                //getstring(buffer, &final_reply.bad_next1);
                printf("%s\n", final_reply.bad_next1);
            }
            else if (strstr(buffer, "object2") != 0){
                sscanf(buffer,"object2 = \"%[^\"]\"",final_reply.object2);
                //getstring(buffer, &final_reply.object2);
                printf("%s\n", final_reply.object2);
            }
            else if (strstr(buffer, "option2") != 0){
                sscanf(buffer,"option2 = \"%[^\"]\"",final_reply.option2);
                //getstring(buffer, &final_reply.option2);
                printf("option2 = %s\n", final_reply.option2);
            }
            else if (strstr(buffer, "change_favor2") != 0){
                sscanf(buffer,"change_favor2 = %d",&final_reply.change_favor2);
                // char *start = strstr(buffer, "=");
                // int32_t START = start-buffer;
                // for (int32_t i = START; buffer[i] != '\n'; i++){
                //     if (buffer[i] == 43){
                //         final_reply.change_favor2 = buffer[i+1]-48;
                //         break;
                //     }
                //     else if (buffer[i] == 45){
                //         final_reply.change_favor2 = -(buffer[i+1]-48);
                //         break;
                //     }
                //     else if (buffer[i] >= 48 && buffer[i] <= 57){
                //         final_reply.change_favor2 = buffer[i]-48;
                //         break;
                //     }
                // }
                printf("%d\n", final_reply.change_favor2);
            }
            else if (strstr(buffer, "favor_threshold2") != 0){
                sscanf(buffer,"favor_threshold2 = %d",&final_reply.favor_threshold2);
                // char *start = strstr(buffer, "=");
                // int32_t START = start-buffer;
                // for (int32_t i = START; buffer[i] != '\n'; i++){
                //     if (buffer[i] >= 48 && buffer[i] <= 57){
                //         if (buffer[i+1] >= 48 && buffer[i+1] <= 57){
                //             final_reply.favor_threshold2 = (buffer[i]-48)*10 + buffer[i+1]-48;
                //             break;
                //         }
                //         else{
                //             final_reply.favor_threshold2 = buffer[i]-48;
                //             break;
                //         }
                //     }
                // }
                printf("%d\n", final_reply.favor_threshold2);
            }
            else if (strstr(buffer, "good_next2") != 0){
                sscanf(buffer,"good_next2 = \"%[^\"]\"",final_reply.good_next2);
                //getstring(buffer, &final_reply.good_next2);
                printf("%s\n", final_reply.good_next2);
            }
            else if (strstr(buffer, "bad_next2") != 0){
                sscanf(buffer,"bad_next2 = \"%[^\"]\"",final_reply.bad_next2);
                //getstring(buffer, &final_reply.bad_next2);
                printf("%s\n", final_reply.bad_next2);
            }
            else if (strstr(buffer, "object3") != 0){
                sscanf(buffer,"object3 = \"%[^\"]\"",final_reply.object3);
                //getstring(buffer, &final_reply.object3);
                printf("%s\n", final_reply.object3);
            }
            else if (strstr(buffer, "option3") != 0){
                sscanf(buffer,"option3 = \"%[^\"]\"",final_reply.option3);
                //getstring(buffer, &final_reply.option3);
                printf("option3 = %s\n", final_reply.option3);
            }
            else if (strstr(buffer, "change_favor3") != 0){
                sscanf(buffer,"change_favor3 = %d",&final_reply.change_favor3);
                // char *start = strstr(buffer, "=");
                // int32_t START = start-buffer;
                // for (int32_t i = START; buffer[i] != '\n'; i++){
                //     if (buffer[i] == 43){
                //         final_reply.change_favor3 = buffer[i+1]-48;
                //         break;
                //     }
                //     else if (buffer[i] == 45){
                //         final_reply.change_favor3 = -(buffer[i+1]-48);
                //         break;
                //     }
                //     else if (buffer[i] >= 48 && buffer[i] <= 57){
                //         final_reply.change_favor3 = buffer[i]-48;
                //         break;
                //     }
                // }
                printf("%d\n", final_reply.change_favor3);
            }
            else if (strstr(buffer, "favor_threshold3") != 0){
                sscanf(buffer,"change_favor3 = %d",&final_reply.favor_threshold3);
                // char *start = strstr(buffer, "=");
                // int32_t START = start-buffer;
                // for (int32_t i = START; buffer[i] != '\n'; i++){
                //     if (buffer[i] >= 48 && buffer[i] <= 57){
                //         if (buffer[i+1] >= 48 && buffer[i+1] <= 57){
                //             final_reply.favor_threshold3 = (buffer[i]-48)*10 + buffer[i+1]-48;
                //             break;
                //         }
                //         else{
                //             final_reply.favor_threshold3 = buffer[i]-48;
                //             break;
                //         }
                //     }
                // }
                printf("%d\n", final_reply.favor_threshold3);
            }
            else if (strstr(buffer, "good_next3") != 0){
                sscanf(buffer,"good_next3 = \"%[^\"]\"",final_reply.good_next3);
                //getstring(buffer, &final_reply.good_next3);
                printf("%s\n", final_reply.good_next3);
            }
            else if (strstr(buffer, "bad_next3") != 0){
                sscanf(buffer,"bad_next3 = \"%[^\"]\"",final_reply.bad_next3);
                //getstring(buffer, &final_reply.bad_next3);
                printf("%s\n", final_reply.bad_next3);
                Backpack back;
                back.background_image = malloc(256);
                back.background_image="../assets/scene/backpack.png";
                if(backpack.items_number==0)
                {
                    back.laptop_image=NULL;
                    back.laptop_image=NULL;
                    back.laptop_message=NULL;
                    back.laptop_name=NULL;
                    back.note_image=NULL;
                    back.note_message=NULL;
                    back.note_name=NULL;
                    back.ticket_image=NULL;
                    back.ticket_message=NULL;
                    back.ticket_name=NULL;
                }
                else if(backpack.items_number==1)
                {
                    back.laptop_image = malloc(256);
                    strcpy(back.laptop_image,backpack.photo[0]);
                    back.note_image=NULL;//strcpy(back.note_image,backpack.photo[1]);
                    back.ticket_image=NULL;//strcpy(back.ticket_image,backpack.photo[2]);
                    back.laptop_name = malloc(256);
                    strcpy(back.laptop_name,backpack.name[0]);
                    back.note_name=NULL;//strcpy(back.note_name,backpack.name[1]);
                    back.ticket_name=NULL;//strcpy(back.ticket_name,backpack.name[2]);
                    back.laptop_message = malloc(256);
                    strcpy(back.laptop_message,backpack.description[0]);
                    back.note_message=NULL;//strcpy(back.note_message,backpack.description[1]);
                    back.ticket_image=NULL;//strcpy(back.ticket_message,backpack.description[2]);
                }
                else if(backpack.items_number==2)
                {
                    back.laptop_image = malloc(256);
                    back.note_image = malloc(256);
                    strcpy(back.laptop_image,backpack.photo[0]);
                    strcpy(back.note_image,backpack.photo[1]);
                    back.ticket_image=NULL;//strcpy(back.ticket_image,backpack.photo[2]);
                    back.laptop_name = malloc(256);
                    back.note_name = malloc(256);
                    strcpy(back.laptop_name,backpack.name[0]);
                    strcpy(back.note_name,backpack.name[1]);
                    back.ticket_name=NULL;//strcpy(back.ticket_name,backpack.name[2]);
                    back.laptop_message=malloc(256);
                    back.note_message=malloc(256);
                    strcpy(back.laptop_message,backpack.description[0]);
                    strcpy(back.note_message,backpack.description[1]);
                    back.ticket_message=NULL;//strcpy(back.ticket_message,backpack.description[2]);
                }
                else if(backpack.items_number==3)
                {
                    back.laptop_image = malloc(256);
                    back.note_image = malloc(256);
                    back.ticket_image = malloc(256);
                    strcpy(back.laptop_image,backpack.photo[0]);
                    strcpy(back.note_image,backpack.photo[1]);
                    strcpy(back.ticket_image,backpack.photo[2]);
                    back.laptop_name = malloc(256);
                    back.note_name = malloc(256);
                    back.ticket_name = malloc(256);
                    strcpy(back.laptop_name,backpack.name[0]);
                    strcpy(back.note_name,backpack.name[1]);
                    strcpy(back.ticket_name,backpack.name[2]);
                    back.laptop_message=malloc(256);
                    back.note_message=malloc(256);
                    back.ticket_message=malloc(256);
                    strcpy(back.laptop_message,backpack.description[0]);
                    strcpy(back.note_message,backpack.description[1]);
                    strcpy(back.ticket_message,backpack.description[2]);
                }
                int end = SDL_choice_one_character(scene.background,"NULL",final_reply.option1,final_reply.option2,final_reply.option3," ",back);
                if(end==4 || end == 6)
                {
                    SDL_DestroyRenderer(screen);
                    SDL_DestroyWindow(window);
                    SDL_Quit();
                    return 0;
                }
                else if (end == 1){
                    object_number = -1;
                    for (int32_t i = 0; i < count_character; i++){
                        if (strcmp(final_reply.object1, character[i].name) == 0){
                            object_number = i;
                            break;
                        }
                        else if (object_number == -1){
                            // wrong
                        }
                    }
                    character[object_number].favor += final_reply.change_favor1;
                    if (character[object_number].favor > 100){
                        character[object_number].favor = 100;
                    }
                    else if (character[object_number].favor < 0){
                        character[object_number].favor = 0;
                    }
                    if (character[object_number].favor >= final_reply.favor_threshold1){
                        for(int i=0;i<100;i++)
                        {
                            search_event[i]=0;
                        }
                        strcpy(search_event, final_reply.good_next1);
                    }
                    else{
                        for(int i=0;i<100;i++)
                        {
                            search_event[i]=0;
                        }
                        strcpy(search_event, final_reply.bad_next1);
                    }
                }
                else if (end == 2){
                    object_number = -1;
                    for (int32_t i = 0; i < count_character; i++){
                        if (strcmp(final_reply.object2, character[i].name) == 0){
                            object_number = i;
                            break;
                        }
                        else if (object_number == -1){
                            // wrong
                        }
                    }
                    character[object_number].favor += final_reply.change_favor2;
                    if (character[object_number].favor > 100){
                        character[object_number].favor = 100;
                    }
                    else if (character[object_number].favor < 0){
                        character[object_number].favor = 0;
                    }
                    if (character[object_number].favor >= final_reply.favor_threshold2){
                        for(int i=0;i<100;i++)
                        {
                            search_event[i]=0;
                        }
                        strcpy(search_event, final_reply.good_next2);
                    }
                    else{
                        for(int i=0;i<100;i++)
                        {
                            search_event[i]=0;
                        }
                        strcpy(search_event, final_reply.bad_next2);
                    }
                }
                else if (end == 3){
                    object_number = -1;
                    for (int32_t i = 0; i < count_character; i++){
                        if (strcmp(final_reply.object3, character[i].name) == 0){
                            object_number = i;
                            break;
                        }
                        else if (object_number == -1){
                            // wrong
                        }
                    }
                    character[object_number].favor += final_reply.change_favor3;
                    if (character[object_number].favor > 100){
                        character[object_number].favor = 100;
                    }
                    else if (character[object_number].favor < 0){
                        character[object_number].favor = 0;
                    }
                    if (character[object_number].favor >= final_reply.favor_threshold3){
                        for(int i=0;i<100;i++)
                        {
                            search_event[i]=0;
                        }
                        strcpy(search_event, final_reply.good_next3);
                    }
                    else{
                        for(int i=0;i<100;i++)
                        {
                            search_event[i]=0;
                        }
                        strcpy(search_event, final_reply.bad_next3);
                    }
                }
                last_scene = 1;
                // SDL_choice_one_character(接return value)
                // object_number = -1;
                // for (int32_t i = 0; i < count_character; i++){
                //     if (strcmp(final_reply.object1, character[i].name) == 0){
                //         object_number = i;
                //         break;
                //     }
                // }
                // if (object_number == -1){
                //     // wrong
                // }
                
                if (final_reply.option_box != NULL){
                    //free_FinalReply(&final_reply);
                }
            }
        }

        if (scene.reply == 1 && strcmp(scene.name, "final_event") != 0){
            object_number = -1;
            if (strstr(buffer, "option_box") != 0){
                sscanf(buffer,"option_box = \"%[^\"]\"",reply.option_box);
                //getstring(buffer, &reply.option_box);
                printf("%s\n", reply.option_box);
            }
            else if (strstr(buffer, "object") != 0){
                sscanf(buffer,"object = \"%[^\"]\"",reply.object);
                //getstring(buffer, &reply.object);
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
                sscanf(buffer,"option1 = \"%[^\"]\"",reply.option1);
                //getstring(buffer, &reply.option1);
                printf("%s\n", reply.option1);
            }
            else if (strstr(buffer, "change_favor1") != 0){
                sscanf(buffer,"change_favor1 = %d",&reply.change_favor1);
                // char *start = strstr(buffer, "=");
                // int32_t START = start-buffer;
                // for (int32_t i = START; buffer[i] != '\n'; i++){
                //     if (buffer[i] == 43){
                //         reply.change_favor1 = buffer[i+1]-48;
                //         break;
                //     }
                //     else if (buffer[i] == 45){
                //         reply.change_favor1 = -(buffer[i+1]-48);
                //         break;
                //     }
                //     else if (buffer[i] >= 48 && buffer[i] <= 57){
                //         reply.change_favor1 = buffer[i]-48;
                //         break;
                //     }
                // }
                printf("%d\n", reply.change_favor1);
            }
            else if (strstr(buffer, "next1") != 0){
                sscanf(buffer,"next1 = \"%[^\"]\"",reply.next1);
                //getstring(buffer, &reply.next1);
                printf("%s\n", reply.next1);
            }
            else if (strstr(buffer, "option2") != 0){
                sscanf(buffer,"option2 = \"%[^\"]\"",reply.option2);
                //getstring(buffer, &reply.option2);
                printf("%s\n", reply.option2);
            }
            else if (strstr(buffer, "change_favor2") != 0){
                sscanf(buffer,"change_favor2 = %d",&reply.change_favor2);
                // char *start = strstr(buffer, "=");
                // int32_t START = start-buffer;
                // for (int32_t i = START; buffer[i] != '\n'; i++){
                //     if (buffer[i] == 43){
                //         reply.change_favor2 = buffer[i+1]-48;
                //         break;
                //     }
                //     else if (buffer[i] == 45){
                //         reply.change_favor2 = -(buffer[i+1]-48);
                //         break;
                //     }
                //     else if (buffer[i] >= 48 && buffer[i] <= 57){
                //         reply.change_favor2 = buffer[i]-48;
                //         break;
                //     }
                // }
                printf("%d\n", reply.change_favor2);
            }
            else if (strstr(buffer, "next2") != 0){
                sscanf(buffer,"next2 = \"%[^\"]\"",reply.next2);
                //getstring(buffer, &reply.next2);
                printf("%s\n", reply.next2);
            }
            else if (strstr(buffer, "option3") != 0){
                sscanf(buffer,"option3 = \"%[^\"]\"",reply.option3);
                //getstring(buffer, &reply.option3);
                printf("%s\n", reply.option3);
            }
            else if (strstr(buffer, "change_favor3") != 0){
                sscanf(buffer,"change_favor3 = %d",&reply.change_favor3);
                // char *start = strstr(buffer, "=");
                // int32_t START = start-buffer;
                // for (int32_t i = START; buffer[i] != '\n'; i++){
                //     if (buffer[i] == 43){
                //         reply.change_favor3 = buffer[i+1]-48;
                //         break;
                //     }
                //     else if (buffer[i] == 45){
                //         reply.change_favor3 = -(buffer[i+1]-48);
                //         break;
                //     }
                //     else if (buffer[i] >= 48 && buffer[i] <= 57){
                //         reply.change_favor3 = buffer[i]-48;
                //         break;
                //     }
                // }
                printf("%d\n", reply.change_favor3);
            }
            else if (strstr(buffer, "next3") != 0){
                sscanf(buffer,"next3 = \"%[^\"]\"",reply.next3);
                //getstring(buffer, &reply.next3);
                printf("%s\n", reply.next3);
                Backpack back;
                back.background_image = malloc(256);
                back.background_image="../assets/scene/backpack.png";
                if(backpack.items_number==0)
                {
                    back.laptop_image=NULL;
                    back.laptop_image=NULL;
                    back.laptop_message=NULL;
                    back.laptop_name=NULL;
                    back.note_image=NULL;
                    back.note_message=NULL;
                    back.note_name=NULL;
                    back.ticket_image=NULL;
                    back.ticket_message=NULL;
                    back.ticket_name=NULL;
                }
                else if(backpack.items_number==1)
                {
                    back.laptop_image = malloc(256);
                    strcpy(back.laptop_image,backpack.photo[0]);
                    back.note_image=NULL;//strcpy(back.note_image,backpack.photo[1]);
                    back.ticket_image=NULL;//strcpy(back.ticket_image,backpack.photo[2]);
                    back.laptop_name = malloc(256);
                    strcpy(back.laptop_name,backpack.name[0]);
                    back.note_name=NULL;//strcpy(back.note_name,backpack.name[1]);
                    back.ticket_name=NULL;//strcpy(back.ticket_name,backpack.name[2]);
                    back.laptop_message = malloc(256);
                    strcpy(back.laptop_message,backpack.description[0]);
                    back.note_message=NULL;//strcpy(back.note_message,backpack.description[1]);
                    back.ticket_image=NULL;//strcpy(back.ticket_message,backpack.description[2]);
                }
                else if(backpack.items_number==2)
                {
                    back.laptop_image = malloc(256);
                    back.note_image = malloc(256);
                    strcpy(back.laptop_image,backpack.photo[0]);
                    strcpy(back.note_image,backpack.photo[1]);
                    back.ticket_image=NULL;//strcpy(back.ticket_image,backpack.photo[2]);
                    back.laptop_name = malloc(256);
                    back.note_name = malloc(256);
                    strcpy(back.laptop_name,backpack.name[0]);
                    strcpy(back.note_name,backpack.name[1]);
                    back.ticket_name=NULL;//strcpy(back.ticket_name,backpack.name[2]);
                    back.laptop_message=malloc(256);
                    back.note_message=malloc(256);
                    strcpy(back.laptop_message,backpack.description[0]);
                    strcpy(back.note_message,backpack.description[1]);
                    back.ticket_message=NULL;//strcpy(back.ticket_message,backpack.description[2]);
                }
                else if(backpack.items_number==3)
                {
                    back.laptop_image = malloc(256);
                    back.note_image = malloc(256);
                    back.ticket_image = malloc(256);
                    strcpy(back.laptop_image,backpack.photo[0]);
                    strcpy(back.note_image,backpack.photo[1]);
                    strcpy(back.ticket_image,backpack.photo[2]);
                    back.laptop_name = malloc(256);
                    back.note_name = malloc(256);
                    back.ticket_name = malloc(256);
                    strcpy(back.laptop_name,backpack.name[0]);
                    strcpy(back.note_name,backpack.name[1]);
                    strcpy(back.ticket_name,backpack.name[2]);
                    back.laptop_message=malloc(256);
                    back.note_message=malloc(256);
                    back.ticket_message=malloc(256);
                    strcpy(back.laptop_message,backpack.description[0]);
                    strcpy(back.note_message,backpack.description[1]);
                    strcpy(back.ticket_message,backpack.description[2]);
                }
                
                for(int i=0;i<1;i++)
                {
                    for(int j=0;j<count_character;j++)
                    {
                        if(strcmp(reply.object,character[j].name)==0 )
                        {
                            int end = SDL_choice_one_character(scene.background,character[j].photo,reply.option1,reply.option2,reply.option3,character[j].name,back);
                            if(end==4 || end == 6)
                            {
                                SDL_DestroyRenderer(screen);
                                SDL_DestroyWindow(window);
                                SDL_Quit();
                                return 0;
                            }
                            else if (end == 1){
                                character[object_number].favor += reply.change_favor1;
                                if (character[object_number].favor > 100){
                                    character[object_number].favor = 100;
                                }
                                else if (character[object_number].favor < 0){
                                    character[object_number].favor = 0;
                                }
                                for(int i=0;i<100;i++)
                                {
                                    search_event[i]=0;
                                }
                                strcpy(search_event, reply.next1);
                            }
                            else if (end == 2){
                                character[object_number].favor += reply.change_favor2;
                                if (character[object_number].favor > 100){
                                    character[object_number].favor = 100;
                                }
                                else if (character[object_number].favor < 0){
                                    character[object_number].favor = 0;
                                }
                                for(int i=0;i<100;i++)
                                {
                                    search_event[i]=0;
                                }
                                strcpy(search_event, reply.next2);
                            }
                            else if (end == 3){
                                character[object_number].favor += reply.change_favor3;
                                if (character[object_number].favor > 100){
                                    character[object_number].favor = 100;
                                }
                                else if (character[object_number].favor < 0){
                                    character[object_number].favor = 0;
                                }
                                for(int i=0;i<100;i++)
                                {
                                    search_event[i]=0;
                                }
                                strcpy(search_event, reply.next3);
                                
                            }
                        }
                    }
                }
                // SDL_choice_one_character(接return value)
                
                if (reply.option_box != NULL){
                    //free_reply(&reply);
                }
            }
        }
    }
    fclose(script);
}
