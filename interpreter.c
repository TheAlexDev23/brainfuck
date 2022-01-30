#include <stdio.h>
#include <string.h>

#define MAX_LOOPS 500

char*code = " ++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";
char*reader;
int started_loops = 0;
char*loops[MAX_LOOPS];

char array[30000] = {0}; 
char *ptr = array;

void calculation();

int main(void) {
    reader = code; 
    while(reader - code < strlen(code)) {
        ++reader;
        calculation();
    }
}

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
            if(*ptr){
               reader = loops[started_loops];
            } else {
                started_loops--;
            } 
            break;
    } 
}
