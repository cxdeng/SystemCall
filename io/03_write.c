#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{

    int fd = open("file/03_write.txt", O_RDWR);
    if (fd == -1)
    {
        perror("open fail");
    }
    

    char *str = "Using CMake to write data into 03_write.txt\n";
    ssize_t write_len = write(fd, (void *)str, strlen(str));
    if (write_len == -1)
    {
        perror("write fail");
    }
    
    

    return 0;
}