#include<unistd.h>
#include "chip8.h"


int main(void) {
    Chip8 emulator;
    initialize_chip8(&emulator);
    initialize_ncurses();

    WINDOW *win = initialize_window();
    draw_window_border(win);
    while (1) {
        render_characters(win, emulator.gfx);
        int ch = getch();
        if (ch == 'q') {
            break;
        }
        usleep(100000);
    }

    destroy_window(win);
    dealloc_chip8(&emulator);
    return 0;
}