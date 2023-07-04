#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fd = open("file/10_link_unlink.txt", O_RDWR | O_CREAT, 0664);
    if (fd == -1)
    {
        perror("open fail");
        exit(-1);
    }

    int linkret = link("file/10_link_unlink.txt", "file/link");
    if (linkret == -1)
    {
        perror("link fail");
        exit(-1);
    }
    
    int unlink_ret = unlink("file/link");
    if (unlink_ret == -1)
    {
        perror("unlink fail");
        exit(-1);
    }
    

    return 0;
}