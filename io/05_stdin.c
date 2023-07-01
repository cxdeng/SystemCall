#include <unistd.h>
#include <stdio.h>

int main()
{

    char read_buf[50] = {0};
    ssize_t read_len = read(0, (void *)read_buf, 50);
    if (read_len == -1)
    {
        perror("read fail");
    }
    
    printf("%s", read_buf);
    
    

    return 0;
}