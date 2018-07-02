#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h> // for system call interface (POSIX)

#define READ_END 0
#define WRITE_END 1
#define BUFFER_SIZE 30

int main(){

    char write_msg[BUFFER_SIZE] = "okaydone";
    char read_msg[BUFFER_SIZE];

    int fd[2]; //to create the pipe descriptor
    pid_t PID;
    int pipe_status = pipe(fd);
    
    if (pipe_status == -1) {
        fprintf(stderr, "Pipe creation failed \n");
        return 1;
    } else {
        printf("Successfuly created a pipe \n");
    }

    PID = fork();

    if (PID < 0){
        fprintf(stderr, " Fork failure \n");
        return 1;    
    } else if (PID > 0) {
        close(fd[READ_END]);
        write(fd[WRITE_END], write_msg, BUFFER_SIZE);
        close(fd[WRITE_END]);

    } else {
        close(fd[WRITE_END]);
        read(fd[READ_END], read_msg, BUFFER_SIZE);
        close(fd[READ_END]);
        printf(" I read this message: %s", read_msg);

        return 1;
    }
    return 0;
}