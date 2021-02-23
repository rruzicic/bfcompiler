#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEM_LENGTH 3000
#define STACK_LEN 5000

// prints the first 10 values of memory strip
void print10(unsigned char memory[MEM_LENGTH]){
    for(int i = 0; i < 10; i++){
        printf("%hhu\t", memory[i]);
    }
    printf("\n");
}
// prints first 20 values of stack
void printS(unsigned stack[STACK_LEN]){
    for(int i = 0; i < 20; i++){
        printf("%u ", stack[i]);
    }
    printf("\n");
}
// initialises memory
void initMem(unsigned char memory[MEM_LENGTH]){
    for(int i = 0; i < MEM_LENGTH; i++){
        memory[i] = 0;
    }
}
// the folowing 4 functions(initStack, push, read, removeS) implement basic stack operations
// although it cant contain value 0, because 0 is used as an indicator that tells us that the cell is empty
void initStack(unsigned stack[STACK_LEN]){
    for(int i = 0; i < STACK_LEN; i++){
        stack[i] = 0;
    }
}
void push(unsigned stack[STACK_LEN], unsigned value){
    for(int i = 0; i < STACK_LEN; i++){
        if(stack[i] == 0){
            stack[i] = value;
            break;
        }
    }
}
unsigned read(unsigned stack[STACK_LEN]){
    for(int i = 0; i < STACK_LEN; i++){
        if(stack[i] == 0){
            return stack[i-1];
        }
    }
}
void removeS(unsigned stack[STACK_LEN]){
    for(int i = 0; i < STACK_LEN; i++){
        if(stack[i] == 0){
            stack[i-1] = 0;
            break;
        }
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
    //unsigned LOOP_POINTER = 0;
    //unsigned i_loop = 0;
    unsigned i_loop[STACK_LEN];
    initStack(i_loop);

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
    //printf("%s", code);

    while(code[i] != '\0'){
        //printf("%d ", i);
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
            //i_loop = i;
            push(i_loop, i+1);
            //printS(i_loop);
        }else if(code[i] == ']'){
            if(memory[POINTER] != 0){
                i = read(i_loop); // + 1
                continue;
            }else{
                removeS(i_loop);
            }
        }else if(code[i] == '.'){
            //printf("%hhu ", memory[POINTER]);
            printf("%c", memory[POINTER]);
            //print10(memory);
        }else if(code[i] == ','){
            scanf("%c", &memory[POINTER]);
        }
        //printf("%d ", i);
        i++;
        //printS(LOOP_POINTER);
    }
    print10(memory);
    }
    else{
        printf("USAGE: gcc bf.c filename.txt\n");
    }
    
    return 0;
}
