#include "uart.h"

int uartfd;
gps_t gps;

void init_uart()
{
    uartfd = ERROR;
    
    // Open UART port
    uartfd = open("/dev/ttyS4", O_RDWR | O_NOCTTY | O_NDELAY);
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
    int bytes_written = write(uartfd, &gps , sizeof(gps_t));
    if (bytes_written == ERROR)
        perror("UART write error");
    else if (bytes_written < sizeof(gps_t))
        printf("Only %d bytes were transmitted instead of %ld\n", bytes_written, sizeof(gps_t));
        
    return SUCCESS;
}

void uart_rx()
{
    int bytes_read = read(uartfd, &gps, sizeof(gps_t));
    if (bytes_read == ERROR) 
    {
        perror("UART read error");
    } 
    else if (bytes_read < sizeof(gps_t)) 
    {
        printf("Only %d bytes were read instead of %ld\n", bytes_read, sizeof(gps_t));
    } 
}

