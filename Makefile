CC=gcc
CFLAGS=-I. -Wall -fsanitize=address
LDFLAGS=-lncurses
DEPS = src/chip8.h src/display/display.h src/input/input.h src/memory/memory.h src/stack/stack.h src/timer/timer.h src/vm/vm.h
OBJ = src/main.o src/chip8.o src/display/display.o src/input/input.o src/memory/memory.o src/stack/stack.o src/timer/timer.o src/vm/vm.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

chip8-emulator: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

clean:
	rm -f src/*.o src/display/*.o src/input/*.o src/memory/*.o src/stack/*.o src/timer/*.o src/vm/*.o chip8-emulator
