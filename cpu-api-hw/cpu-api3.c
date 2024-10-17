#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sigchld_handler(int signum) {
    // Handler for SIGCHLD - this will be triggered when the child terminates
    printf("Child process finished (received SIGCHLD)\n");
}

int main(int argc, char *argv[]) {
    printf("hello world (pid:%d)\n", (int)getpid());
    
    // Set up the signal handler for SIGCHLD
    signal(SIGCHLD, sigchld_handler);

    int rc = fork();
    
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello, I am child (pid:%d)\n", (int)getpid());
        sleep(1);
        exit(0);
    } else {
        // parent process
        // pause the parent, waiting for a signal (SIGCHLD from child)
        pause();
        printf("goodbye, I am parent of %d (pid:%d)\n", rc, (int)getpid());
    }

    return 0;
}
