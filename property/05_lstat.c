#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
    printf("argc = %d, argv[0] = %s, argv[1] = %s\n", argc, argv[0], argv[1]);
    if (argc != 2)
    {
        printf("Invalid arguments\n");
        exit(-1);
    }


    struct stat sta;
    int res = lstat(argv[1], &sta);
    if (res == -1)
    {
       perror("stat fail");
       exit(-1);
    }

    printf("file name = %s\n", argv[1]);
    printf("st_uid = %d\n", sta.st_uid);
    printf("st_gid = %d\n", sta.st_gid);
    printf("st_mode = %u\n", sta.st_mode);
    printf("st_nlink = %ld\n", sta.st_nlink);
    printf("st_size = %ld\n", sta.st_size);
}