#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "stack.h"


void initialize_stack(Stack *stack) {
    memset(stack->arr, 0, sizeof(stack->arr));
    stack->stack_ptr = 0;
}

void push(Stack *stack, unsigned short item) {
    assert(stack->stack_ptr < STACK_SIZE);
    stack->arr[stack->stack_ptr] = item;
    ++stack->stack_ptr;
}

unsigned short pop(Stack *stack) {
    assert(stack->stack_ptr > 0);
    --stack->stack_ptr;
    return stack->arr[stack->stack_ptr];
}
