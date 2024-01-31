#include <stdint.h>

#define STACK_SIZE 16


typedef struct {
    unsigned short arr[STACK_SIZE];
    uint16_t stack_ptr;
} Stack;

void initialize_stack(Stack *stack);

void push(Stack *stack, unsigned short item);

unsigned short pop(Stack *stack);
