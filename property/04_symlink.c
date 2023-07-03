#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    int fd = open("file/04_symlink_lstat.txt", O_RDWR | O_TRUNC | O_CREAT, 0664);
    if (fd == -1)
    {
        perror("open fail");
        exit(-1);
    }

    int sym = symlink("04_symlink_lstat.txt", "file/link_file");
    if (sym == -1)
    {
        perror("symlink fail");
        exit(-1);
    }
    

    return 0;
}