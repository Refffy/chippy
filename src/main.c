#include "chip8.h"

int main(void) {
	Chip8 emulator;
	initialize_chip8(&emulator);

	while (1) {
		draw_window(emulator.gfx);
	}

	dealloc_chip8(&emulator);
	return 0;
}