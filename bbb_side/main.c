#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include "gpio.h"
#include "uart.h"
#include "main.h"

int main(void)
{
    init_uart();

    while(1)
    {
        if(check_button())
        {
            // transmit the gps variable. initially filled with 0's. if the gps is filled, will 
            // tranmit it's data to generate an end message.
            uart_tx();
            print_gps();
            uart_rx(); 
            print_gps(); 
            op_read();
            /*  MAYBE SEND TO ANOTHER FUNCTION (STATE MACHINE) THAT BASED ON START/END FLAG 
            *   SEND TO SERVER. IF THE END FLAG IS ON, TRANSMIT TO SERVER AND RESET THE gps_t
            * 1. transmit empty struct
            * 2. wait for response
            * 3. send to server 
            */
        }
    }

    close_uart();
    return 0;
}

void op_read()
{
    // transmit the gps packet to the server for operation.
    // send_to_server(); // TODO- add function
    if(gps.end_flag)
    // if it's an end flag, reset the packet to generate another in the next loop iteration.
        reset_gps_packet(); 

}

void print_gps()
{
    printf("gps values:\n");
    printf("unique id = %d\n", gps.unique_id);
    printf("coord = %hhu\n", gps.coordinates);
    printf("start = %hhu\n", gps.start_flag);
    printf("end = %hhu\n", gps.end_flag);
}