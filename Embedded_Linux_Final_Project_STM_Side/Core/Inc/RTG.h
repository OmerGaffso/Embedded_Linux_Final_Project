/*
 * RTG.h
 *
 *  Created on: 23/01/2023
 *  Author: Omer Penso
 *
 */
#ifndef INC_RTG_H_
#define INC_RTG_H_s
#include "main.h"
#include "stm32f7xx_hal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart7;

#define UART_DEBUG &huart3				//Debug UART
#define UART_CONNECTION &huart7			//UART Handle

#define COORDINATES_MAX 	100

#define TRUE 	1
#define FALSE	0

typedef struct gps_pack
{
	uint32_t unique_id;
	uint8_t coordinates;
	uint8_t start_flag;
	uint8_t end_flag;
}gps_t;

void rtg_main();

/**
 * Helper function to generate random coordinates in range 1-100
 * @return generated coordinates.
 */
uint8_t generate_coordinates();

/**
 * Helper function to reset all the buffers + packet.
 */
void reset_buffers();

#endif /* INC_RTG_H_ */
