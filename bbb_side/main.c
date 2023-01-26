#include "uart.h"

int main(void)
{

    return 0;
}

void my_exit(int status)
{
    // Close UART port
    close(uartfd);
    if (status == ERROR)
        exit(EXIT_FAILURE);
    else if(status == SUCCESS)
        exit(EXIT_SUCCESS);
    else
    {
        printf("Unknown status.\n");
        exit(EXIT_FAILURE);
    }
}