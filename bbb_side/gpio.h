/**
 * @file gpio.h
 * @author Omer Penso
 * @brief This file and it's function simulate a press of a button using gpio.
 * To configure the gpio settings for the BBB, run the following commands on BBB: 
 *      config-pin P9.13 uart
 *      config-pin P9.11 uart
 *      config-pin P8.08 gpio_input
 * 
 * Connect a jumper to the P9.04 pin (constant 3.3V output), and to simulate a press of a button
 * connect the jumper to the P8.08 pin.
 * @date 26-01-2023
 */
#ifndef MY_GPIO_FILE_OP
#define MY_GPIO_FILE_OP

#define INPUT_GPIO "67"             // Pin P8.08 on the bbb
#define ASCII_CHAR_TO_DIGIT 48      // any digit char - 48 will equal to its value as int.
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