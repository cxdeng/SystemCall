#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ret_rmdir = rmdir("file/14_mkdir");
    if (ret_rmdir == -1)
    {
        perror("rmdir fail");
        exit(-1);
    }
    

    return 0;
}