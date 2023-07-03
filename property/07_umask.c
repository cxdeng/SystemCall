#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    mode_t old_umask = umask(0);
    printf("old_umask = %o\n", old_umask);

    int fd1 = open("file/07_umask_1.txt", O_RDWR | O_TRUNC | O_CREAT, 0777);
    if (fd1 == -1)
    {
        perror("open fail");
        exit(-1);
    }


    mode_t newMask = S_IRUSR | S_IWUSR | S_IXUSR; 
    mode_t oldMask = umask(newMask); 

    printf("Old umask: %o\n", oldMask);
    printf("New umask: %o\n", newMask);
    
    int fd2 = open("file/07_umask_2.txt", O_RDWR | O_TRUNC | O_CREAT, 0777);
    if (fd2 == -1)
    {
        perror("open fail");
        exit(-1);
    }

    return 0;
}