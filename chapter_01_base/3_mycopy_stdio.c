#include<stdio.h>
#include<stdlib.h>

int main()
{
    int c;
    while ((c = getc(stdin)) != EOF)
    {
        if (putc(c, stdout) == EOF) {
            printf("write failed\n");
            exit(-1);
        }
    }

    if (ferror(stdin)) {
        printf("read error\n");
        exit(-1);
    }
    exit(0);
}
