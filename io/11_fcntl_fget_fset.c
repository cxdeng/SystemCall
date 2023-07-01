#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{

    int fd = open("file/11_fcntl_fget_fset.txt", O_RDWR);
    if (fd == -1)
    {
        perror("open fail");
        _exit(-1);
    }


    // Get old flag from fd
    int old_flag = fcntl(fd, F_GETFL, 0);

    // Set new flag to fd
    int flag = old_flag | O_APPEND;
    int new_flag = fcntl(fd, F_SETFL, flag);
    if (new_flag == -1)
    {
        perror("fcntl fail");
        _exit(-1);
    }
    

    char *write_buf = "F_SETFL\n";
    ssize_t write_len = write(fd, (void *)write_buf, strlen(write_buf));   

    return 0;
}