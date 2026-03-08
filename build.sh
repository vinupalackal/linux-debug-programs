#!/bin/bash

# Build script for Linux debugging programs

echo "Building Linux debugging programs..."
echo "===================================="

# Compile mutex_deadlock
echo "Compiling mutex_deadlock.c..."
gcc -Wall -Wextra -O2 -pthread mutex_deadlock.c -o mutex_deadlock
if [ $? -eq 0 ]; then
    echo "✓ mutex_deadlock compiled successfully"
else
    echo "✗ Failed to compile mutex_deadlock"
    exit 1
fi

# Compile memory_leak
echo "Compiling memory_leak.c..."
gcc -Wall -Wextra -O2 memory_leak.c -o memory_leak
if [ $? -eq 0 ]; then
    echo "✓ memory_leak compiled successfully"
else
    echo "✗ Failed to compile memory_leak"
    exit 1
fi

echo ""
echo "===================================="
echo "Build completed successfully!"
echo "Binaries created:"
echo "  - mutex_deadlock"
echo "  - memory_leak"
echo ""
echo "To run the programs:"
echo "  ./mutex_deadlock"
echo "  ./memory_leak"
