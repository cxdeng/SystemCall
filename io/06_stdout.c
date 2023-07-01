#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{

    char *write_buf = "Standard out descriptor 1\n";
    ssize_t write_len = write(STDOUT_FILENO, (void *)write_buf, strlen(write_buf));
    if (write_len == -1)
    {
        perror("write fail");
        return -1;
    }

    int num = 65;
    char str[20];
    sprintf(str, "%d", num);
    write_len = write(STDOUT_FILENO, (void *)str, strlen(str));
    if (write_len == -1)
    {
        perror("write fail");
        return -1;
    }
    write_len = write(STDOUT_FILENO, "\n", strlen("\n"));
    if (write_len == -1)
    {
        perror("write fail");
        return -1;
    }


    close(1);
    write_buf = "Close descriptor 1\n";
    write_len = write(STDOUT_FILENO, (void *)write_buf, strlen(write_buf));
    if (write_len == -1)
    {
        perror("write fail");
        return -1;
    }

    return 0;
}