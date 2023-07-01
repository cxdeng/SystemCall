#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define FILE "file/07_shared_file.txt"

int main()
{

    int fd1 = open(FILE, O_RDWR | O_APPEND | O_TRUNC);
    if (fd1 == -1)
    {
        perror("open fail");
        _exit(-1);
    }

    int fd2 = open(FILE, O_RDWR | O_APPEND | O_TRUNC);
    if (fd2 == -1)
    {
        perror("open fail");
        _exit(-1);
    }

    char *buf1 = "Hello, ";
    ssize_t write_len1 = write(fd1, (void *)buf1, strlen(buf1));
    if (write_len1 == -1)
    {
        perror("write fail");
        _exit(-1);
    }
    

    char *buf2 = "World.\n";
    size_t write_len2 = write(fd2, (void *)buf2, strlen(buf2));
    if (write_len2 == -1)
    {
        perror("write fail");
        _exit(-1);
    }

    

    return 0;
}