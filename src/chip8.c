#include "chip8.h"
#include <stdlib.h>


void initialize_chip8(Chip8 *emulator) {
    emulator->memory = calloc(1, sizeof(Memory));
    if (emulator->memory) {
        emulator->memory->registers = calloc(1, sizeof(Registers));
        emulator->memory->stack = calloc(1, sizeof(Stack));
        if (emulator->memory->stack) {
            initialize_stack(emulator->memory->stack);
        }
        if (emulator->memory->registers) {
            initialize_gp_registers(emulator->memory->registers);
        }
    }
    emulator->gfx = calloc(1, sizeof(GFX));
    if (emulator->gfx) {
        initialize_display(emulator->gfx);
    }
}

void dealloc_chip8(Chip8 *emulator) {
    if (emulator->memory) {
        free(emulator->memory->registers);
        free(emulator->memory->stack);
    }
    free(emulator->memory);
    free(emulator->gfx);
}
