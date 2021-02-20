#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEM_LENGTH 3000
#define NESTED_LOOPS 5000

void print10(unsigned char memory[MEM_LENGTH]){
    for(int i = 0; i < 10; i++){
        printf("%hhu\t", memory[i]);
    }
    printf("\n");
}
void initMem(unsigned char memory[MEM_LENGTH]){
    for(int i = 0; i < MEM_LENGTH; i++){
        memory[i] = 0;
    }
}
void initLoopPointers(unsigned LP[NESTED_LOOPS], unsigned iloop[NESTED_LOOPS], unsigned LE[NESTED_LOOPS]){
    for(int i = 0; i < NESTED_LOOPS; i++){
        LP[i] = 0;
        iloop[i] = 0;
        LE[i] = 0;
    }
}
int main(int argc, char *argv[]){
    // TODO:
    // 1. add support for nested loops
    // 2. read from file -- DONE
    // 3. fix decrement below 0 (0 - 1 = 255!!!) -- FIXED
    // 4. add support for dynamic memory allocation - LINKED LISTS
    // 5. 
    

    unsigned char memory[MEM_LENGTH];
    unsigned POINTER = 0;
    unsigned LOOP_POINTER = 0;
    unsigned i_loop = 0;
    char line[5000] = "";
    char code[50000] = "";
    int i = 0;

    initMem(memory);

    
    if(argc == 2){

    // read from file
    FILE *fp; 
    fp = fopen(argv[1], "rt");
    while(fgets(line, 500, fp) != NULL){
        strcat(code, line);
    }
    printf("%s", code);

    while(code[i] != '\0'){
        //printf("i = %d: %c\n", i, code[i]);
        if(code[i] == '>'){
            POINTER++;
            if(POINTER >= MEM_LENGTH || POINTER < 0){
                printf("\nCan't access memory location!\n");
                break;
            }
        }else if(code[i] == '<'){
            POINTER--;
            if(POINTER >= MEM_LENGTH || POINTER < 0){
                printf("\nCan't access memory location!\n");
                break;
            }
        }else if(code[i] == '+'){
            memory[POINTER]++;
        }else if(code[i] == '-'){
            memory[POINTER]--;
        }else if(code[i] == '['){
            LOOP_POINTER = POINTER;
            i_loop = i;
        }else if(code[i] == ']'){
            if(memory[LOOP_POINTER] != 0){
                POINTER = LOOP_POINTER;
                i = i_loop;
                continue;
            }
        }else if(code[i] == '.'){
            printf("%c", memory[POINTER]);
        }else if(code[i] == ','){
            scanf("%c", &memory[POINTER]);
        }

        i++;
    }

    //print10(memory);
    }
    else{
        printf("USAGE: gcc bf.c filename.txt\n");
    }

    return 0;
}