# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS = -pthread

# Target binaries
TARGETS = mutex_deadlock memory_leak

# Default target: build all programs
all: $(TARGETS)

# Build mutex_deadlock
mutex_deadlock: mutex_deadlock.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

# Build memory_leak
memory_leak: memory_leak.c
	$(CC) $(CFLAGS) -o $@ $<

# Clean up binaries
clean:
	rm -f $(TARGETS)

# Phony targets
.PHONY: all clean
