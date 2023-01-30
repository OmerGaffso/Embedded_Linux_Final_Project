#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include "gpio.h"
#include "uart.h"

int main(void)
{
    init_uart();

    while(1)
    {
        sleep(1);
        if(check_button())
        {
            /*  MAYBE SEND TO ANOTHER FUNCTION (STATE MACHINE) THAT BASED ON START/END FLAG 
            *   SEND TO SERVER. IF THE END FLAG IS ON, TRANSMIT TO SERVER AND RESET THE gps_t
            * 1. transmit empty struct
            * 2. wait for response
            * 3. send to server 
            */
        }
    }
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