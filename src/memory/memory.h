#include <stdint.h>
#include "src/stack/stack.h"

#define REGISTERS_SIZE 16
#define RAM_SIZE 4096

// only the lowest (rightmost) 12 bits are usually used: http://devernay.free.fr/hacks/chip8/C8TECH10.HTM#2.2
#define get_index_register_lsb(I) I >> 12


typedef uint16_t address;
typedef uint8_t constant;

typedef struct {
    uint8_t V[REGISTERS_SIZE];
    uint16_t I;
    uint16_t PC;
} Registers;

typedef struct {
    uint8_t RAM[RAM_SIZE]; 
    Registers *registers;
    Stack *stack;
} Memory;

// initialization of general purpose registers
void initialize_gp_registers(Registers *registers);

void initialize_memory(Memory *memory);
