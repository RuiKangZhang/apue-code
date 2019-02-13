#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#define BUFFSIZE 4096

// 信号处理函数
static void sig_interupt(int signo)
{
	printf("Interupt!\n%% ");
	return;
}

int main(int argc, char *argv[])
{
    char buf[BUFFSIZE];
	pid_t pid;

	// 扑捉 SIGINT 信号并交由信号处理函数处理
    if (signal(SIGINT, sig_interupt) == SIG_ERR)
    {
        perror("Signal error!");
        exit(1);
    }  


	return 0;
}