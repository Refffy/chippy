#include <stdint.h>


typedef struct {
    uint8_t DT; // delay timer
    uint8_t ST; // sound timer
} Timers;


void timer_lifecycle(Timers *timer);
