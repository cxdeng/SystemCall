#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd = open("file/03_chmod.txt", O_RDWR | O_CREAT, 0664);
    if (fd == -1)
    {
        perror("open fail");
        exit(-1);
    }

    char *write_buf = "03_chmod.c\n";
    ssize_t write_len = write(fd, (void *)write_buf, strlen(write_buf));
    if (write_len == -1)
    {
        perror("write fail");
        exit(-1);
    }
    
    mode_t permission =  S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    int ret = chmod("file/03_chmod.txt", permission);
    if (ret == -1)
    {
        perror("chmod fail");
        exit(-1);
    }
    

    return 0;
}