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
    } else {
        printf("Failed to get file status.\n");
    }

    return 0;
}