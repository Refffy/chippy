#include <string.h>
#include "memory.h"


void initialize_gp_registers(Registers *registers) {
    memset(registers->V, 0, sizeof(registers->V));
    registers->I = 0;
    registers->PC = 512; // 0x200
}

void initialize_memory(Memory *memory) {
    memset(memory->RAM, 0, sizeof(memory->RAM));
    initialize_gp_registers(memory->registers);
    initialize_stack(memory->stack);
} 