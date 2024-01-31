#include <stdint.h>
#include "src/stack/stack.h"

#define REGISTERS_SIZE 16
#define RAM_SIZE 4096


typedef uint16_t address;
typedef uint8_t constant;
typedef struct {
    unsigned int X: 4;
    unsigned int Y: 4; 
} RegisterID; //RegisterID.X; RegisterID.Y -- are 4-bit registers identifiers

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
