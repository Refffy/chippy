#include <string.h>
#include <ncurses.h>
#include "display.h"


void initialize_display(GFX *gfx) {
    memset(gfx->videomem, 0, WIDTH * HEIGHT * sizeof(pixel));
}

void initialize_ncurses(void) {
    initscr();
    cbreak();
    noecho();
}

size_t get_index(size_t x, size_t y) {
    return x * WIDTH + y;
}

void put_pixel(GFX *gfx, size_t x, size_t y, pixel pxl) {
    size_t index = get_index(x, y);
    gfx->videomem[index] = pxl;
}

void draw_window(GFX *gfx) {
    initialize_ncurses();
    int start_x = 10; // TODO: add some calculation logic based on the terminal size
    int start_y = 10;
    WINDOW *win = newwin(WIDTH, HEIGHT, start_y, start_x);
    refresh();
    box(win, 0, 0);
    wrefresh(win);
    draw_display(win, gfx);
    wgetch(win);
    endwin();
}

void render_characters(WINDOW *win, GFX *gfx) {
    for (size_t x = 0; x < WIDTH; ++x) {
        for (size_t y = 0; y < HEIGHT; ++y) {
            size_t curr_index = get_index(x, y);
            mvwaddch(win, x, y, gfx->videomem[curr_index] ? '#' : ' ');
        }
    }
}
