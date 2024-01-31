# Use the latest version of Alpine Linux as the base image
FROM alpine:latest

# Update package list and install gcc, standard C library development files, and ncurses development library
RUN apk update && apk add gcc musl-dev ncurses-dev make

# Copy your project files into the container
COPY . /usr/src/chip8-emulator

# Set the working directory inside the container
WORKDIR /usr/src/chip8-emulator

# Compile your project using the Makefile
RUN make chip8-emulator && chmod +x chip8-emulator
# Define the command to run your compiled program
CMD ["./chip8-emulator"]
