/**
 * @file gpio.h
 * @author Omer Penso
 * @brief This file will contain all gpio function declarations and definitions.
 * The function implementation is in gpio.c file.
 * @date 26-01-2023
 */
#ifndef MY_GPIO_FILE_OP
#define MY_GPIO_FILE_OP

#define OUTPUT_GPIO "60"
#define INPUT_GPIO "50"

void setup_output_gpio();
void setup_input_gpio();
void cleanup_gpio();

#endif