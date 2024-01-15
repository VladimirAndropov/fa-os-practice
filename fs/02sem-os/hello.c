
#include <stdio.h>

// #define GREETING "Hello, world\n"
// extern int  GREETING ;  // hi 1   bss
// int GREETING = 2;          // hi 1 data
static int  GREETING=2;   // hi o
// макрос будет раскрыт в ходе препроцессирования

int main(void) {
    printf("hi %d\n",GREETING);
    // printf(GREETING);
    return 0;
}


// gcc -Wall -Werror -m32 hello.c hello2.c -o hello