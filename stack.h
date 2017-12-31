#include <stdbool.h>

/*
    first-in, last out (stack) impl, using void ptrs
*/
#ifndef STACK_H
#define STACK_H

typedef struct stack_element stack_element;
struct stack_element {
    void* ptr;
    stack_element* u; // under
};

typedef struct stack stack;
struct stack {
    stack_element* t; // top
    /*
        size is number of elements on stack
        < CL size for mutex later
    */
    unsigned int s;
};

// create a new stack
stack* stack_new();

// put an element on the stack
bool s_push(stack* stack, void* ptr);

// pop an element off the stack
void* s_pop(stack* stack);

// return size
unsigned int s_size(stack* stack);

#endif //STACK_H
