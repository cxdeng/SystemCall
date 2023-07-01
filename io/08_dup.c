#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd1 = open("file/08_dup.txt", O_RDWR | O_TRUNC);
    if (fd1 == -1)
    {
        perror("open fail");
        _exit(-1);
    }

    int fd2 = dup(fd1);
    if (fd2 == -1)
    {
        perror("dup fail");
        _exit(-1);
    }

    printf("fd1 = %d, fd2 = %d\n", fd1, fd2);


    char *buf_fd1 = "Linux C/C++\n";
    ssize_t write_len_fd1 = write(fd1, (void *)buf_fd1, strlen(buf_fd1));

    char *buf_fd2 = "Cmake Tools\n";
    ssize_t write_len_fd2 = write(fd1, (void *)buf_fd2, strlen(buf_fd2));

    if (write_len_fd1 == -1 || write_len_fd2 == -1)
    {
        perror("write fail");
        _exit(-1);
    }
    

    return 0;
}