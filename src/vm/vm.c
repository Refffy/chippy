#include "vm.h"

// https://tobiasvl.github.io/blog/write-a-chip-8-emulator/#decode
#define signature(opcode) ((opcode & 0xF000) >> 12) // the first nibble
#define X(opcode) ((opcode & 0x0F00) >> 8)
#define Y(opcode) ((opcode & 0x00F0) >> 4)
#define N(opcode) (opcode & 0x000F)
#define NN(opcode) (opcode & 0xFF)
#define NNN(opcode) (opcode & 0xFFF)

uint16_t fetch_opcode(Chip8 *emulator) {
    /*
        since the instuction is 2 bytes wide and stored in MSB order,
        to get the highest byte part, we need to shift the opcode by 8 (1 byte == 8 bits usually)
        and do OR with the lowest byte part.
    */
    uint16_t pc = emulator->memory->registers->PC;
    uint16_t opcode = emulator->memory->RAM[pc] >> 8 | emulator->memory->RAM[pc+1];
    emulator->memory->registers->PC += 2;   
    return opcode;
}

void evaluate_instruction(Chip8 *emulator) {
    uint16_t opcode = fetch_opcode(emulator);

    switch (signature(opcode)) {
        case 0x0:
            if (N(opcode) == 0x0) {
                initialize_display(emulator->gfx); // clear the display
                break;
            } else if (N(opcode) == 0xE) {
                emulator->memory->registers->PC = emulator->memory->stack->arr[emulator->memory->stack->stack_ptr--];
                break;
            } else {
                // 0nnn - SYS addr instruction is deprecated, ignore it
                break;
            }
        case 0x1:
            emulator->memory->registers->PC = NNN(opcode);
            break;
        case 0x6:
            emulator->memory->registers->V[X(opcode)] = NN(opcode);
            break;
        case 0x7:
            emulator->memory->registers->V[X(opcode)] = X(opcode) + NN(opcode);
        case 0xA:
            emulator->memory->registers->I = NNN(opcode);
            // emulator->memory->registers.I = get_index_register_lst(emulator->memory->registers.I);
            break;
        case 0xD:
            break;
            // todo
    }
}