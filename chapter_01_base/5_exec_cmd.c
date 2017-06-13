#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

#define MAXLINE 4096

int main()
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf("%% ");

    //read cmd from std input
    while (fgets(buf, MAXLINE, stdin) != NULL) {

        //execlp() requires null for the end of param
        if (buf[strlen(buf) - 1] == '\n') {
            buf[strlen(buf) - 1] = 0;
        }

        if ((pid = fork()) < 0) {
            perror("fork error\n");
        } else if (pid == 0) {
            execlp(buf, buf, (char *)0);
        }

        if ((pid = waitpid(pid, &status, 0)) < 0) {
            perror("waitpid error\n");
        }
        printf("%% ");
    }

    exit(0);
}
