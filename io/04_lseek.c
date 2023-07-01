#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main()
{

    int fd = open("file/03_write.txt", O_RDWR);
    if (fd == -1)
    {
        perror("open fail");
        return -1;
    }
    

    char *str = "Using CMake and lseek to write data into 04_lseek.txt.";
    ssize_t write_len = write(fd, (void *)str, strlen(str));
    if (write_len == -1)
    {
        perror("write fail");
        return -1;
    }

    off_t offset = lseek(fd, 0, SEEK_SET);
    if (offset == -1)
    {
        perror("lseek fail");
        return -1;
    }
    
    char read_buf[100] = {0};
    ssize_t read_len = read(fd, (void *)read_buf, 100);
    if (read_len == -1)
    {
        perror("read fail");
        return -1;
    }
    printf("%s\n", read_buf);
    
    

    return 0;
}