#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{

    int fd1 = open("file/10_fcntl.txt", O_RDWR);
    if (fd1 == -1)
    {
        perror("open fail");
        _exit(-1);
    }


    // Simulate the dup function
    close(STDOUT_FILENO);
    int fd2 = fcntl(fd1, F_DUPFD, 0);
    if (fd2 == -1)
    {
        perror("fcntl fail");
        _exit(-1);
    }
    
    printf("Using fcntl function to simulate the dup function");

    
    // Simulate the dup2 function
    close(STDIN_FILENO);
    int fd3 = fcntl(fd1, F_DUPFD, STDIN_FILENO);
    if (fd3 == -1)
    {
        perror("fcntl fail");
        _exit(-1);
    }
    
    char read_buf[50] = {0};
    ssize_t read_len = read(fd3, (void *)read_buf, 50);
    if (read_len == -1)
    {
        perror("read fail");
        _exit(-1);
    }
    

    return 0;
}