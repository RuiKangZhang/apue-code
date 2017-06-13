#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
   printf("Current user is: %d, group is %d\n", getuid(), getgid());
   exit(0);
}
