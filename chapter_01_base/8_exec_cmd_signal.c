//waiting for achieving
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

// 信号处理函数
static void sig_interupt(int signo)
{
	printf("Interupt!\n%% ");
}

int main(int argc, char *argv[])
{
	// 扑捉 SIGINT 信号并交由信号处理函数处理
    if (signal(SIGINT, sig_interupt) == SIG_ERR)
    {

    }  


	return 0;
}