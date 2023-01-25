/**
 * @file perph.h
 * @author Omer Penso
 * @brief This file will contain all peripheral function declarations and definitions.
 * The function implementation is in perph.c file.
 * @date 2023-01-24
 */
#ifndef MY_PERP_FILE_OP
#define MY_PERP_FILE_OP

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

/**
 * @brief This function will initialize the uart connection for the bbb. It will set all the options
 * and assign the uartfd file descriptor. 
 * 
 */
void init_uart();

/**
 * @brief This function will transmit the data in the global gps struct via uart to stm.
 * @return int - return ERROR (-1) if any error occurred, and SUCCESS (1) otherwise. 
 */
int uart_tx();

/**
 * @brief This function will receive the data received via uart from stm, and store the data
 * in the global gps struct to transmit to the server.
 */
void uart_rx();

/**
 * @brief This function will close all file descriptors that have been open during the program
 * runtime, and use exit function based on the status received as parameter.
 * 
 * @param status - the status with which we got into this function.
 */
void my_exit(int status);

#endif