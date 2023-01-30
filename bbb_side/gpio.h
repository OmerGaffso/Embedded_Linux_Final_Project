/**
 * @file gpio.h
 * @author Omer Penso
 * @brief This file will contain all gpio function declarations and definitions.
 * The function implementation is in gpio.c file.
 * @date 26-01-2023
 */
#ifndef MY_GPIO_FILE_OP
#define MY_GPIO_FILE_OP

#define INPUT_GPIO "67"             // Pin P8.08 on the bbb
#define GPIO_BUFF_SIZE 64
#define BUTTON_ON 1
#define BUTTON_OFF 0

extern int button_state;

/**
 * @brief this function read the input fd for simulated button value.
 * 
 * @return int 1 (BUTTON_ON) if the circuit is connected (button is pressed), 0 (BUTTON_OFF) if 
 *                          the circuit is not connected (button is not pressed).
 */
int check_button();

#endif