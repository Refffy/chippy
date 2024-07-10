#include<unistd.h>
#include "chip8.h"


int main(void) {
    Chip8 emulator;
    initialize_chip8(&emulator);
    initialize_ncurses();
    WINDOW *win = initialize_window();

    // while (1) {
    //     draw_window_border(win);
    //     draw_window(win, emulator.gfx);
    //     napms(500);
    // }

    destroy_window(win);
    dealloc_chip8(&emulator);
    return 0;
}