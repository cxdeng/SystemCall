#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd = open("file/13_readlink.txt", O_RDWR | O_CREAT, 0664);
    if (fd == -1)
    {
        perror("open fail");
        exit(-1);
    }

    int ret_symlink = symlink("13_readlink.txt", "file/link");
    if (ret_symlink == -1)
    {
        perror("symlink fail");
        exit(-1);
    }

    char readlink_buf[100];
    ssize_t buf_size = readlink("file/link", readlink_buf, sizeof(readlink_buf));
    if (buf_size == -1)
    {
        perror("readlink fail");
        exit(-1);
    }

    printf("readlink_buf = %s\n", readlink_buf);
    printf("buf_size = %ld\n", buf_size);

    return 0;
}