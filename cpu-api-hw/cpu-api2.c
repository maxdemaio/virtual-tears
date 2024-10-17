#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Open a file before the fork
    int fd = open("test.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    if (fd < 0) {
        printf("Error opening file\n");
        exit(1);
    }

    printf("hello world (pid:%d)\n", (int) getpid());
    //fflush(stdout);  // Flush to ensure output is not buffered

    int rc = fork();
    
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // Child process
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        char *child_msg = "This is the child writing\n";
        write(fd, child_msg, strlen(child_msg));
        fsync(fd);  // Ensure data is written to disk
    } else {
        // Parent process
        int wc = wait(NULL);
        printf("hello, I am parent of %d (wc:%d) (pid:%d)\n", rc, wc, (int) getpid());
        char *parent_msg = "This is the parent writing\n";
        write(fd, parent_msg, strlen(parent_msg));
        fsync(fd);  // Ensure data is written to disk
    }

    close(fd);
    return 0;
}
