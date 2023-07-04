#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

int main(int argc, char** argv)
{
    printf("argc = %d, argv[0] = %s, argv[1] = %s\n", argc, argv[0], argv[1]);
    if (argc != 2)
    {
        printf("Invalid arguments\n");
        exit(-1);
    }

    char *dir_name = argv[1];
    DIR* p_dir = opendir(dir_name);
    if (p_dir == NULL)
    {
        perror("opendir fail");
        exit(-1);
    }

    struct dirent *entry;
    while ((entry = readdir(p_dir)) != NULL) {
        printf("inodeID = %ld,\tfilename = %s\n", entry->d_ino, entry->d_name);
    }   
    
    if (errno != 0)
    {
        perror("readdir fail");
        exit(-1);
    }
    

    return 0;
}