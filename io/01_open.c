#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{

    int fd = open("file/01_open.txt", O_RDWR);
    if (fd == -1)
    {
        perror("open fail");
    }
    

    return 0;
}