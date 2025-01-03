#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void sortArray(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
 }

int main() {
    int arr[] = {34, 7, 23, 32, 5, 62};
    int n = sizeof(arr)/sizeof(arr[0]);
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } 
    else if (pid == 0) {
        printf("Child Process sorting array...\n");
        sortArray(arr, n);
        printf("Child sorted array: ");
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    } else {
        sleep(2); 
        wait(NULL); 
        printf("Parent waited for child. Zombie state demonstrated.\n");
    }
    return 0;
}