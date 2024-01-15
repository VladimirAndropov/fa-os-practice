#include <stdio.h>

// static int  x = 10;

int incr(void){
    static int x=5;  // равносильно
    x +=1;
    return x;
}

int main(void) {
    printf("hi %d\n",incr());
    printf("hi %d\n",incr());
    return 0;
}


// gcc -Wall -Werror -m32 incr.c -o incr