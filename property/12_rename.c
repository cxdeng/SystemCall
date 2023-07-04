#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fd = open("file/11_remove.txt", O_RDWR | O_CREAT, 0664);
    if (fd == -1)
    {
        perror("open fail");
        exit(-1);
    }
    

    int rename_ret = rename("file/11_remove.txt", "./11_remove_rename.txt");
    if (rename_ret == -1)
    {
        perror("rename fail");
        exit(-1);
    }
    

    return 0;

}