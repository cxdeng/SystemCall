#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *path;

    path = getcwd(NULL, 0);
    if (path == NULL)
    {
        perror("getcwd fail");
        exit(-1);
    }

    printf("path = %s\n", path);


    path = "/home/cxdeng/Projects/VsCodeProjects/SystemCall/property/build/file";
    int ret = chdir(path);
    if (ret == -1)
    {
        perror("chdir fail");
        exit(-1);
    }


    path = getcwd(NULL, 0);
    if (path == NULL)
    {
        perror("getcwd fail");
        exit(-1);
    }

    printf("path = %s\n", path);
    


}