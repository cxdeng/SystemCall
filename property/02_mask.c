#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    printf("argc = %d, argv[0] = %s, argv[1] = %s\n", argc, argv[0], argv[1]);
    if (argc != 2)
    {
        printf("Invalid arguments\n");
        exit(-1);
    }

    const char* filename = argv[1];
    mode_t fileMode;
    struct stat fileStat;

    // Get the permission bits of a file
    if (stat(filename, &fileStat) == 0) {
        fileMode = fileStat.st_mode;

        // Check the read permission of the file
        if (fileMode & S_IRUSR) {
            printf("File has read permission.\n");
        } else {
            printf("File does not have read permission.\n");
        }

        // Check the write permission of the file
        if (fileMode & S_IWUSR) {
            printf("File has write permission.\n");
        } else {
            printf("File does not have write permission.\n");
        }

        // Check the execute permission of the file
        if (fileMode & S_IXUSR) {
            printf("File has execute permission.\n");
        } else {
            printf("File does not have execute permission.\n");
        }


        if (S_ISREG(fileMode))
        {
            printf("File is regular file.\n");
        }else if (S_ISDIR(fileMode))
        {
            printf("File is directory file.\n");
        }else if (S_ISLNK(fileMode))
        {
            printf("File is link file.\n");
        }else if (S_ISFIFO(fileMode))
        {
            printf("File is pipe file.\n");
        }else if (S_ISCHR(fileMode))
        {
            printf("File is character device file.\n");
        }else if (S_ISBLK(fileMode))
        {
            printf("File is block device file.\n");
        }else if (S_ISSOCK(fileMode))
        {
            printf("File is socket file.\n");
        }
        
    } else {
        printf("Failed to get file status.\n");
    }

    return 0;
}