#include <stdio.h>
#include <string.h>

//Maximum allowed loops 
#define MAX_LOOPS 500

//Brainfuck code that would be executed
char*code = " ++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";

char*reader; // A pointer used to read values from code

int started_loops = 0; //A counter that would help us indicate the last started loop
char*loops[MAX_LOOPS]; // Array of pointers pointing to the begining of all loops 

//The main array
char array[30000] = {0}; 
char *ptr = array; //Current node in the array 

void calculation();

int main(void) {
    reader = code; //inuitialize our reader to start reading from the begining of the code 
    
    //check if we have reached the end of the brainfuck code
    while(reader - code < strlen(code)) {
        ++reader; //move readre forwards one value
        calculation(); //do the needed calculations in the current brainfuck symbol
    }
}

//Do the needed calculations with each character of the code
void calculation() {
    switch(*reader){
        case '>':
            ++ptr;
            break;
        case '<':
            --ptr;
            break;
        case '+':
            ++(*ptr);
            break;
        case '-':
            --(*ptr);
            break;
        case '.':
            printf("%c", *ptr);
            break;
        case ',':
            scanf("%c", ptr);
            break;
        case '[':
            started_loops++;
            loops[started_loops] = reader; 
            break;
        case ']':
            //if end of loop is reached go to the last begining of loop if *ptr != 0
            if(*ptr){
               reader = loops[started_loops];
            } else { // make the last loop the previous to the current
                started_loops--;
            } 
            break;
    } 
}
