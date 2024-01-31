#include "display/display.h"
#include "memory/memory.h"


typedef struct {
    Memory *memory;
    GFX *gfx;
} Chip8;

void initialize_chip8(Chip8 *emulator);
void dealloc_chip8(Chip8 *emulator);