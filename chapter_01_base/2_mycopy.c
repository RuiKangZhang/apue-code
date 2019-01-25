#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define BUFFSIZE 4096

int main()
{
    int n;
    char buf[BUFFSIZE];
    char exit_symbol = '.';  //循环退出标识

    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
    {
        if (write(STDOUT_FILENO, buf, n) != n)
        {
            perror("Error: write to stdout failed!");
            exit(1);
        }

        //根据输入的最后一个字符判断是否需要退出循环
        if (buf[n-sizeof("\n")] == exit_symbol)
        {
            printf("Exit program....\n");
            break;
        }
    }

    if (n < 0)
    {
        perror("Error: read from stdin failed!");
        exit(1);
    }

    return 0;
}
