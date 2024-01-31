#include <stdio.h>
#include "chip8.h"
// #include "stack/stack.h"

int main(void) {
	Chip8 emulator;
	initialize_chip8(&emulator);

	draw_window();

	dealloc_chip8(&emulator);
	return 0;
}