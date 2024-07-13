#include <string.h>
#include <ncurses.h>
#include "display.h"


size_t get_index(size_t x, size_t y) {
    return y * WIDTH + x;
}

void initialize_display(GFX *gfx) {
    memset(gfx->videomem, 0, sizeof(gfx->videomem));
}

void initialize_ncurses(void) {
    initscr();
    refresh();
    cbreak();
    noecho();
    curs_set(FALSE);
    timeout(0);
}

void put_pixel(GFX *gfx, size_t x, size_t y, pixel pxl) {
    size_t index = get_index(x, y);
    gfx->videomem[index] = pxl;
}

void draw_window_border(WINDOW *win) {
    werase(win);
    box(win, 0, 0);
    wrefresh(win);
}

WINDOW *initialize_window(void) {
    int start_x = 10; // TODO: add some calculation logic based on the terminal size
    int start_y = 10;

    WINDOW *win = newwin(WIDTH + 2, HEIGHT + 2, start_y, start_x);

    return win;
}

void destroy_window(WINDOW *win) {
    delwin(win);
    endwin();
}

void render_characters(WINDOW *win, GFX *gfx) {
    for (size_t y = 0; y < HEIGHT; ++y) {
        for (size_t x = 0; x < WIDTH; ++x) {
            size_t curr_index = get_index(x, y);
            mvwaddch(win, x + 1, y + 1, gfx->videomem[curr_index] ? '#' : ' ');
        }
    }
    wrefresh(win);
}