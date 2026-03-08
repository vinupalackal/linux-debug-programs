#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function that leaks a small amount of memory
void leak_small_memory() {
    // Allocate 1 KB of memory and never free it
    char *leaked_ptr = (char *)malloc(1024);
    if (leaked_ptr != NULL) {
        // Use the memory to avoid compiler optimizations
        memset(leaked_ptr, 0xAB, 1024);
        strcpy(leaked_ptr, "This memory will never be freed");
    }
    // Intentionally not freeing the memory - this is the leak
}

int main() {
    int iteration = 0;
    
    printf("Starting memory leak program...\n");
    printf("This program will leak 1 KB of memory every 2 seconds\n");
    printf("Use tools like 'valgrind' or 'ps' to monitor memory growth\n");
    printf("Press Ctrl+C to exit\n\n");
    
    while (1) {
        leak_small_memory();
        iteration++;
        
        printf("Iteration %d: Leaked 1 KB (Total leaked: %d KB)\n", 
               iteration, iteration);
        
        // Sleep for 2 seconds between leaks
        sleep(2);
    }
    
    return 0;
}
