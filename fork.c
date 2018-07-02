#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main() {

    pid_t PID;
    int child_status;

    PID = fork();
    
    if (PID < 0){

        printf("%s", "Fork Failure \n");
        return 1;

    } else if (PID == 0) {
        printf("%s"," This is the child process \n" );
    
    } else {
        wait(&child_status);
        printf("The child process exited with code \n Code: %d", child_status);
        
    }
    return 0;
}