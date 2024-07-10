FROM debian:latest

RUN apt-get update && apt-get install -y \
    gcc \
    make \
    libncurses-dev \
    g++ \
    gdb \
    libasan6 \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

COPY . /usr/src/chip8-emulator

WORKDIR /usr/src/chip8-emulator

RUN make chip8-emulator && chmod +x chip8-emulator

CMD ["./chip8-emulator"]
