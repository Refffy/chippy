#include <stdint.h>
#include <src/chip8.h>


typedef struct {
    uint16_t opcode;
} VM;

void evaluate_opcode(Chip8 *emulator);
uint16_t fetch_opcode(Chip8 *emulator);
