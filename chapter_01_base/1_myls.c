#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if (argc != 2) {
       //err_quit("usage: ls direct name");
       printf("usage: ls direct name\n");
       exit(1);
    }

    if ((dp = opendir(argv[1])) == NULL) {
       //err_sys("Cannot open dir %s", argv[1]);
       printf("Cannot open dir %s", argv[1]);
       exit(1);
    }

    while ((dirp = readdir(dp)) != NULL)
    {
        /*
        struct stat *buf;
        if (stat(dirp->d_name, buf) < 0) {
            printf("get %s infomation failed", dirp->d_name);
            exit(1);
        }
        printf("haha");
        printf("%s %s\n",dirp->d_name, buf->st_mtime);
        free(buf);
        */
        printf("%s\n", dirp->d_name);
    }

    closedir(dp);

    exit(0);
