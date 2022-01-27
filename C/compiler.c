#include <stdio.h>
#include <string.h>

//variables

char*code = "1. +++++ +++++             initialize counter (cell #0) to 10 \
             2. [                       use loop to set the next four cells to 70/100/30/10\
             3.    > +++++ ++              add  7 to cell #1\
             4.    > +++++ +++++           add 10 to cell #2 \
             5.    > +++                   add  3 to cell #3\
            6.    > +                     add  1 to cell #4\
            7.    <<<< -                  decrement counter (cell #0)\
            8. ]";
char*start;
char*reader;

char array[30000];
char*ptr=array;

//function prototypes
void calculate(char*pointer);

int main(void) {
    start = reader = code;

    calculate(ptr);
    printf("Programm has ended\nCode used: %s\n", code);
}

void calculate(char*pointer) {
    switch(*reader) {
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
            printf("%c %i\n",*ptr, *ptr);
            break;
        case ',':
            scanf("%c", ptr);
            break;
        case '[':
            char*tmp = reader;
            while(*ptr) {
                calculate(tmp);
                ++reader;
            }
            break;
        case ']':
            reader = pointer;
            return;
        default:
            break;
	}
   
    if(reader - start < strlen(code) - 1) {
        ++reader;
        calculate(ptr);
    }
}
