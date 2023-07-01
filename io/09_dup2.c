#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd1 = open("file/09_dup2.txt", O_RDWR | O_TRUNC);
    if (fd1 == -1)
    {
        perror("open fail");
        _exit(-1);
    }

    char *buf_fd1 = "Linux C/C++\n";
    ssize_t write_len_fd1 = write(fd1, (void *)buf_fd1, strlen(buf_fd1));
    if (write_len_fd1 == -1)
    {
        perror("write fail");
        _exit(-1);
    }
    

    int fd2 = dup2(fd1, STDIN_FILENO);
    if (fd2 == -1)
    {
        perror("dup2 fail");
        _exit(-1);
    }
    
    __off_t offset = lseek(fd2, 0, SEEK_SET);
    if (offset == -1)
    {
        perror("offset fail");
        _exit(-1);
    }
    
    
    char read_buf[50] = {0};
    ssize_t read_len = read(fd2, (void *)read_buf, 50);
    if (read_len == -1)
    {
        perror("read fail");
        _exit(-1);
    }
    printf("%s", read_buf);
    


    int fd3 = dup2(fd1, STDOUT_FILENO);
    if (fd3 == -1)
    {
        perror("dup2 fail");
        _exit(-1);
    }
    printf("Cmake Tools\n");   

    return 0;
}