#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{

    char *write_buf = "Standard out descriptor 1\n";
    ssize_t write_len = write(1, (void *)write_buf, strlen(write_buf));
    if (write_len == -1)
    {
        perror("write fail");
        return -1;
    }

    close(1);
    write_buf = "Close descriptor 1\n";
    write_len = write(1, (void *)write_buf, strlen(write_buf));
    if (write_len == -1)
    {
        perror("write fail");
        return -1;
    }

    return 0;
}