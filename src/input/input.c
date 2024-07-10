#include "input.h"

// trash code, isn't it? But it looks pretty funny, so I wrote it and just let it be here...
unsigned char get_chip8_keycode(char keycode) {
    // char keycode = wgetch();
    switch (keycode) {
        keycodes_mapping(keycode)
        default: return 0xFF;   
    }
}
