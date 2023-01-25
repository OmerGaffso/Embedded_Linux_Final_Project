#include "perph.h"

int uartfd;

void init_uart()
{
    uartfd = ERROR;

    // Open UART port
    uartfd = open("/dev/ttyS4", O_RDWR | O_NOCTTY | O_NDELAY);
    if (uartfd == ERROR)
    {
        printf("Error opening UART port.\n");
        return ERROR;
    }

    // Configure UART port
    struct termios options;
    tcgetattr(uartfd, &options);
    /* Set the uart connection settings */
    options.c_cflag = B115200 | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    tcflush(uartfd, TCIFLUSH);
    tcsetattr(uartfd, TCSANOW, &options);

}

int uart_tx()
{
    // Transmit data through UART
    int bytes_written = write(uartfd, (gps_t *) &gps , sizeof(gps_t));
    if (bytes_written <= 0)
    {
        perror("UART Transmit");
        return ERROR;
    }



    return SUCCESS;
}

void uart_rx()
{

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