#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include "gpio.h"

int button_state = BUTTON_OFF;
int button_cnt = 0;
int print_release_flag = 0;

int check_button()
{
    char input = 0;
    int byte_read = 0;
    int state = -1;

    // open file of the input gpio
    int value_fd = open("/sys/class/gpio/gpio67/value", O_RDONLY, 0666); 
    if (value_fd < 0)
    {
        perror("Failed to open value file");
        exit(EXIT_FAILURE);
    }

    // read the input from the file
    byte_read = read(value_fd, &input, sizeof(char));
    if (byte_read < 0)
    {
        perror("Value read error");
        exit(EXIT_FAILURE);
    }
    close(value_fd);
    
    // change the readed input to int value
    state = input - ASCII_CHAR_TO_DIGIT;
    
    // if the button is not pressed yet, and readed '1' from the input gpio, simulate button press
    if (state == BUTTON_ON && button_state == BUTTON_OFF) 
    {
        // Register the button press
        button_state = BUTTON_ON;
        /*
        button_cnt++;
        print_release_flag = 0;
        printf("%d. Button Pressed\n",button_cnt);
            TODO- DELETE, USED FOR DEBUGGING.
        */
        return BUTTON_ON;
    } 
    else if (state == BUTTON_OFF && button_state == BUTTON_ON) 
    {
        // Register the button release
        button_state = BUTTON_OFF;
        /*
        if (print_release_flag == 0)
        {
            printf("%d.Button Released.\n",button_cnt);
            print_release_flag = 1;
        }
            TODO- DELETE, USED FOR DEBUGGING.
        */
        return BUTTON_OFF;
    }
    else 
        return BUTTON_OFF; 
}
