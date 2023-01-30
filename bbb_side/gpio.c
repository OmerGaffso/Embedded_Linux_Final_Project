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
    char buf[GPIO_BUFF_SIZE] = { 0 };
    int byte_read = 0;
    int state = -1;

    int value_fd = open("/sys/class/gpio/gpio67/value", O_RDONLY, 0666);
    if (value_fd < 0)
    {
        perror("Failed to open value file");
        exit(EXIT_FAILURE);
    }

    byte_read = read(value_fd, buf, GPIO_BUFF_SIZE);
    if (byte_read < 0)
    {
        perror("Value read error");
        exit(EXIT_FAILURE);
    }
    close(value_fd);

    printf("read %s from value file.\n", buf);
    state = atoi(buf);
    printf("state = %d\n", state);
    printf("button state = %d\n", button_state);
    if (state == BUTTON_ON && button_state == BUTTON_OFF) 
    {
        // Register the button press
        button_state = BUTTON_ON;
        button_cnt++;
        print_release_flag = 0;
        printf("%d. Button Pressed\n",button_cnt);
        return BUTTON_ON;
    } 
    else if (state == BUTTON_OFF && button_state == BUTTON_ON) 
    {
        // Register the button release
        button_state = BUTTON_OFF;
        if (print_release_flag == 0)
        {
            printf("%d.Button Released.\n",button_cnt);
            print_release_flag = 1;
        }
        return BUTTON_OFF;
    }
    else 
        return BUTTON_OFF; 
}
