#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int fd = open("file/08_truncate.txt", O_RDWR | O_CREAT, 0664);
    if (fd == -1)
    {
        perror("open fail");
        exit(-1);
    }

    char *write_buf = "Hello, World.";
    ssize_t write_len = write(fd, (void *)write_buf, strlen(write_buf));
    if (write_len == -1)
    {
        perror("write fail");
        exit(-1);
    }

    
    int trun = truncate("file/08_truncate.txt", 100);
    if (trun == -1)
    {
        perror("truncate fail");
        exit(-1);
    }

    int ftrun = ftruncate(fd, 200);
    if (ftrun == -1)
    {
        perror("truncate fail");
        exit(-1);
    }

    close(fd);

    return 0;
}
