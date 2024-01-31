#include <string.h>
#include <ncurses.h>
#include "display.h"


void initialize_display(GFX *gfx) {
    memset(gfx, 0, WIDTH * HEIGHT * sizeof(pixel));
    initialize_ncurses();

    int start_x = 0;
    int start_y = 0;
    WINDOW *win = newwin(HEIGHT, WIDTH, start_y, start_x);
    refresh();
    box(win, 0, 0);
    wrefresh(win);
    getch();
    endwin();
}

void initialize_ncurses(void) {
    initscr();
    cbreak();
    noecho();
}

size_t get_index(size_t x, size_t y) {
    return y * HEIGHT + x;
}

void put_pixel(GFX *gfx, size_t x, size_t y, pixel pxl) {
    size_t index = get_index(x, y);
    gfx->videomem[index] = pxl;
}

// this function will be basically used in the emulator lifecycle to update the pixels
void draw_display(GFX *gfx) {
    for (size_t y = 0; y < HEIGHT; ++y) {
        for (size_t x = 0; x < WIDTH; ++x) {
            size_t curr_index = get_index(x, y);
            mvaddch(x, y, gfx->videomem[curr_index] ? '#' : ' ');
        }
    }
}
