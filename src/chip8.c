#include "chip8.h"
#include <stdlib.h>

void initialize_chip8(Chip8 *emulator) {
    emulator->memory = calloc(1, sizeof(Memory));

    if (!emulator->memory) {
        puts("An allocation error occured!");
        return;
    } else {
        puts("Emulator's memory has been allocated");
    }

    emulator->memory->registers = calloc(1, sizeof(Registers));
    emulator->memory->stack = calloc(1, sizeof(Stack));

    if (!emulator->memory->registers || !emulator->memory->stack) {
        puts("An allocation error occured!");
        free(emulator->memory->registers);
        free(emulator->memory->stack);
        free(emulator->memory);
        emulator->memory = NULL;
        return;
    } else {
        puts("Memory registers and stack have been allocated");
    }
    
    initialize_stack(emulator->memory->stack);
    initialize_gp_registers(emulator->memory->registers);

    emulator->gfx = calloc(1, sizeof(GFX));
    if (!emulator->gfx) {
        puts("An allocation error occured!");
        free(emulator->memory->registers);
        free(emulator->memory->stack);
        free(emulator->memory);
        emulator->memory = NULL;
        return;
    } else {
        puts("Graphics memory has been allocated");
    }

    initialize_display(emulator->gfx);
}

void dealloc_chip8(Chip8 *emulator) {
    if (emulator->memory) {
        free(emulator->memory->registers);
        free(emulator->memory->stack);
        free(emulator->memory);
    }
    free(emulator->gfx);
    puts("Emulator's resources have been deallocated");
}
