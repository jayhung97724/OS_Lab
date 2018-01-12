#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    DIR *dp;
    char *dir = "./YoYo";
    struct stat statbuf;
    struct dirent *entry;

    if ((dp = opendir(dir)) == NULL)    {
        printf("error on opendir\n");
        return;
    }
    chdir(dir);
    while((entry = readdir(dp)) != NULL) {
        lstat(entry -> d_name, &statbuf);
        if (strcmp(entry -> d_name, ".") == 0 || strcmp(entry -> d_name, "..") == 0)
            continue;
        printf("name:%10s [%d]\n", entry -> d_name, S_ISDIR(statbuf.st_mode));
    }
    closedir(dp);
    exit(0);
}