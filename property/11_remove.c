#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fd = open("file/11_remove.txt", O_RDWR | O_CREAT, 0664);
    if (fd == -1)
    {
        perror("open fail");
        exit(-1);
    }
    

    int remove_ret = remove("file/11_remove.txt");
    if (remove_ret == -1)
    {
        perror("remove fail");
        exit(-1);
    }
    

    return 0;

}