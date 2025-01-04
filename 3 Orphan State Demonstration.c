#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } 
    else if (pid == 0) {
        sleep(2); 
        printf("Child is now orphan, adopted by init process.\n");
    } 
    else {
        printf("Parent process exiting.\n");
        exit(0); 
    }
    return 0;
}
