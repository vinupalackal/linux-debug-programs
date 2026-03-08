#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* thread_function(void* arg) {
    int thread_id = *(int*)arg;
    printf("Thread %d: Attempting to acquire mutex...\n", thread_id);
    
    // This will hang because the mutex is already locked by main thread
    pthread_mutex_lock(&mutex);
    
    // This code will never execute
    printf("Thread %d: Mutex acquired (this should never print)\n", thread_id);
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

int main() {
    pthread_t thread;
    int thread_id = 1;
    
    printf("Main: Locking mutex...\n");
    pthread_mutex_lock(&mutex);
    printf("Main: Mutex locked\n");
    
    // Create a thread that will try to acquire the same mutex
    printf("Main: Creating thread...\n");
    if (pthread_create(&thread, NULL, thread_function, &thread_id) != 0) {
        perror("Failed to create thread");
        return 1;
    }
    
    printf("Main: Thread created. Now sleeping to keep mutex locked...\n");
    printf("Main: Thread %d is now hanging, waiting for the mutex\n", thread_id);
    printf("Main: Press Ctrl+C to exit\n");
    
    // Keep the main thread alive with the mutex locked
    // The spawned thread will hang indefinitely waiting for the mutex
    while (1) {
        sleep(5);
        printf("Main: Still holding the mutex. Thread is still waiting...\n");
    }
    
    // Cleanup (unreachable in this example)
    pthread_mutex_unlock(&mutex);
    pthread_join(thread, NULL);
    pthread_mutex_destroy(&mutex);
    
    return 0;
}
