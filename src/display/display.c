#include <string.h>
#include <ncurses.h>
#include "display.h"


size_t get_index(size_t x, size_t y) {
    return y * WIDTH + x;
}

void initialize_display(GFX *gfx) {
    memset(gfx->videomem, 0, sizeof(gfx->videomem));

    // for the debug purpose
    printf("Size of gfx.videomem: %zu\n", sizeof(gfx->videomem));
    for (size_t y = 0; y < HEIGHT; y++) {
        for (size_t x = 0; x < WIDTH; x++) {
            size_t curr_index = get_index(x, y);
                printf("%i", gfx->videomem[curr_index]);
        }
        puts("\n");
    }
    for (int i = 0; i < 10; i++) {
        printf("videomem[%d] = %d\n", i, gfx->videomem[i]);
    }
    for (int i = (WIDTH * HEIGHT) - 10; i < (WIDTH * HEIGHT); i++) {
        printf("videomem[%d] = %d\n", i, gfx->videomem[i]);
    }
}

void initialize_ncurses(void) {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
}

void put_pixel(GFX *gfx, size_t x, size_t y, pixel pxl) {
    size_t index = get_index(x, y);
    gfx->videomem[index] = pxl;
}

void draw_window_border(WINDOW *win) {
    box(win, 0, 0);
    wrefresh(win);
}

WINDOW *initialize_window(void) {
    int start_x = 10; // TODO: add some calculation logic based on the terminal size
    int start_y = 10;

    WINDOW *win = newwin(WIDTH, HEIGHT, start_y, start_x);

    // draw_window_border(win);

    return win;
}

void draw_window(WINDOW *win, GFX *gfx) {
    render_characters(win, gfx);
}

void destroy_window(WINDOW *win) {
    delwin(win);
    endwin();
}

void render_characters(WINDOW *win, GFX *gfx) {
    for (size_t y = 0; y < HEIGHT; y++) {
        for (size_t x = 0; x < WIDTH; x++) {
            size_t curr_index = get_index(x, y);
            mvwaddch(win, x, y, gfx->videomem[curr_index] ? '#' : 'l');
        }
    }
    wrefresh(win);
}