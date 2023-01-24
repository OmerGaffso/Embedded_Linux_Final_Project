#include "uart.h"

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

    // TODO - MOVE TO WRITE FUNCTION
    // Transmit data through UART
    // const char *data = "Hello, World!\n";
    // int bytes_written = write(uartfd, data, strlen(data));
    // if (bytes_written > 0)
    // {
    //     printf("Transmitted %d bytes: %s\n", bytes_written, data);
    // }

    // // Close UART port
    // close(uartfd);
}