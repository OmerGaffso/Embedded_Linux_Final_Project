#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <stdlib.h>
#include "uart.h"

int uartfd;
gps_t gps = { 0 };

void init_uart()
{
    uartfd = ERROR;
    
    // Open UART port
    uartfd = open("/dev/ttyS4", O_RDWR | O_NOCTTY );
    if (uartfd == ERROR)
    {
        perror("Failed to open UART device");
        exit(EXIT_FAILURE);
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

void uart_tx()
{
    // Transmit data through UART
    int bytes_written = 0;
    int total_sent = 0;
    do
    {
        bytes_written = write(uartfd, &gps , sizeof(gps_t));
        if (bytes_written == ERROR)
        {    
            perror("UART write error");
            exit(EXIT_FAILURE);
        }    
        total_sent += bytes_written;
    } while (total_sent < sizeof(gps_t));
    
        printf("The message was sent\n");

}

void uart_rx()
{
    int bytes_read = 0;
    int total_read = 0;
    do
    {
        bytes_read = read(uartfd, &gps, sizeof(gps_t));
        if (bytes_read == ERROR)
        {
            perror("UART receive error");
            exit(EXIT_FAILURE);
        }
        total_read += bytes_read;
    } while (total_read < sizeof(gps_t));
     
    printf("The message was received\n");
    
}

void close_uart()
{
    // Close UART port
    if (uartfd)
    {
        if(close(uartfd) < 0)
            printf("Uart closed successfuly.\n");
    }
}

void reset_gps_packet()
{
    gps.coordinates = 0;
    gps.end_flag = 0;
    gps.start_flag = 0;
    gps.unique_id = 0;
}

