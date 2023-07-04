#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ret_mkdir = mkdir("file/14_mkdir", 0775);
    if(ret_mkdir == -1)
    {
        perror("mkdir fail");
        exit(-1);
    }

    return 0;
}