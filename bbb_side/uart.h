/**
 * @file uart.h
 * @author Omer Penso
 * @brief This file will contain all uart function declarations and definitions.
 * The function implementation is in uart.c file.
 * @date 24-01-2023
 */
#ifndef MY_UART_FILE_OP
#define MY_UART_FILE_OP


/// INCLUDES:
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#include <inttypes.h>

/// DEFINITIONS:
#define ERROR -1
#define SUCCESS 1

/// STRUCTS:
typedef struct gps_pack
{
	uint32_t unique_id;
	uint8_t coordinates;
	uint8_t start_flag;
	uint8_t end_flag;
}gps_t;

/// GLOBAL VARIABLES:
extern uartfd;
extern gps;

/// FUNCTIONS:
/**
 * @brief This function will initialize the uart connection for the bbb. It will set all the options
 * and assign the uartfd file descriptor. 
 * 
 */
void init_uart();

/**
 * @brief This function will transmit the data in the global gps struct via uart to stm.
 */
void uart_tx();

/**
 * @brief This function will receive the data received via uart from stm, and store the data
 * in the global gps struct to transmit to the server.
 */
void uart_rx();

#endif