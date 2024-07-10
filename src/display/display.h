#include <stddef.h>
#include <ncurses.h>

#define HEIGHT 64
#define WIDTH 32

typedef unsigned char pixel;

typedef struct {
    pixel videomem[HEIGHT * WIDTH];
} GFX;

void initialize_display(GFX *gfx);
void initialize_ncurses(void);
void cleanup_ncurses(void);
size_t get_index(size_t x, size_t y);
void put_pixel(GFX *gfx, size_t x, size_t y, pixel pxl);
WINDOW *initialize_window(void);
void draw_window_border(WINDOW *win);
void draw_window(WINDOW *win, GFX *gfx);
void destroy_window(WINDOW *win);
void render_characters(WINDOW *win, GFX *gfx);