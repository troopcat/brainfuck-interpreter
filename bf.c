#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int tape[30000] = {0};
static int tape_index = 0;
static size_t loop;
static size_t i;

int main(int argc, char **argv){

    FILE *fp = fopen(argv[1], "r");

    if(fp == NULL){
        puts("Cannot load the given file");
        return 1;
    }

    fseek(fp, 0L, SEEK_END);
    long int size = ftell(fp);
    rewind(fp);

    char content[size];

    char c;
    for(int i = 0; i < size; i++){
        c = fgetc(fp);
        if(c == EOF){
            break;
        }
        content[i] = c;
    }



    for(int i = 0;i < size; i++){
        char c = content[i];

        if(c == *(">")){tape_index++;}

        else if(c == *("<")){tape_index--;}

        else if(c == *("+")){tape[tape_index]++;}

        else if(c == *("-")){tape[tape_index]--;}

        else if(c == *(".")){printf("%c", tape[tape_index]);}

        else if(c == *(",")){tape[tape_index] = getc(stdin);}

        else if (c == *("[")){

        }

        else if (c == *("]") && tape[tape_index] > 0){
            loop = 1;
            while(loop > 0){
                c = content[--i];
                if(c == *("[")){
                    loop--;
                } else if(c == *("]")){
                    loop++;
                }
            }
        }
    }
    return 0;
}
