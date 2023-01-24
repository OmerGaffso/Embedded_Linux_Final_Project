/**
 * @file uart.h
 * @author Omer Penso
 * @brief This file will contain all uart function declarations and definitions.
 * The function implementation is in uart.c file.
 * @date 2023-01-24
 */
#ifndef MY_UART_FILE_OP
#define MY_UART_FILE_OP

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include "main.h"

/**
 * @brief This function will initialize the uart connection for the bbb. It will set all the options
 * and assign the uartfd file descriptor. 
 * 
 */
void init_uart();

/**
 * @brief This function will transmit the data in the buffer via uart to stm.
 * @param buff - the data to transmit
 * @return int - return ERROR (-1) if any error occurred, and SUCCESS (1) otherwise. 
 */
int uart_tx(char *buff);

#endif