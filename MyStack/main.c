#include <stdio.h>
#include "stack.h"  // Include the stack header file




int main() {
    Stack s;


    ST_init(&s);
    ST_push(&s,6);
    ST_push(&s,5);
    ST_print(s);
    ST_pop(&s);
    ST_print(s);





    return 0;
}