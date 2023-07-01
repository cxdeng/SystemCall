#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{

    int fd = open("file/02_read.txt", O_RDWR);
    if (fd == -1)
    {
        perror("open fail");
    }
    

    char read_buf[50] = {0};
    ssize_t read_len  = read(fd, (void *)read_buf, 20);
    if (read_len == -1)
    {
        perror("read fail");
    }

    printf("%s\n", read_buf);
    

    return 0;
}