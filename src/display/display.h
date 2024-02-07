#include <stddef.h>
#include <ncurses.h>

#define HEIGHT 64
#define WIDTH 32

typedef unsigned char pixel;

typedef struct {
    pixel videomem[HEIGHT * WIDTH];
} GFX;

void initialize_display(GFX *gfx);
void render_characters(WINDOW *win, GFX *gfx);
void draw_window(GFX *gfx);

void initialize_ncurses(void);

pixel get_pixel(GFX *gfx, size_t x, size_t y);
void put_pixel(GFX *gfx, size_t x, size_t y, pixel pxl);

size_t get_index(size_t x, size_t y);