#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("Current process id is %ld\n", (long)getpid());
    exit(0);
}
