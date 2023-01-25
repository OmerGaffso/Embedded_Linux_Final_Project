#include <time.h>
#include "RTG.h"
/*
 * author: Omer Penso
 * date: 23/01/2023
 *
 * This is the stm side of the Embedded Linux Project.
 *
*/

gps_t packet = { 0 };
int uart_receive_flag = 0;
uint32_t unq_id = 1;
uint32_t uart_rx_id = 0;

void rtg_main()
{
	srand(time(NULL));
	HAL_UART_Receive_IT(UART_CONNECTION, (uint8_t *)uart_rx_id, sizeof(uint32_t));

	while(1)
	{
		if(uart_receive_flag) // got new uart message
		{
			// received a message with initialized id, generate stop message.
			if(uart_rx_id)
			{
				packet.unique_id = uart_rx_id;
				packet.coordinates = 0; // No need for coordinated - end message.
				packet.end_flag = TRUE;
				packet.start_flag = FALSE;
			}
			// received a message with uninitialized id -> new user -> generate info + start message.
			else
			{
				packet.unique_id = unq_id++;
				packet.coordinates = generate_coordinates();
				packet.start_flag = TRUE;
				packet.end_flag = FALSE;
			}

			// Transmit the data back to BBB.
			HAL_UART_Transmit_IT(UART_CONNECTION, (uint8_t *)&packet, sizeof(gps_t));
			// reset packet struct & uart_rx_id & clear uart_receive_flag
			reset_buffers();
			// Reset the receive interrupt
			HAL_UART_Receive_IT(UART_CONNECTION, (uint8_t *)uart_rx_id, sizeof(uint32_t));
		}
	}
}

void reset_buffers()
{
	memset(&packet, 0, sizeof(gps_t));
	uart_rx_id = 0;
	uart_receive_flag = FALSE;
	HAL_GPIO_WritePin(GPIOB, LD2_Pin, GPIO_PIN_RESET);
}

uint8_t generate_coordinates()
{
	return (rand() % COORDINATES_MAX + 1);
	// + 1 so will return number between 1-100
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart == UART_CONNECTION)
	{
		HAL_GPIO_WritePin(GPIOB, LD2_Pin, GPIO_PIN_SET);
		uart_receive_flag = TRUE;
	}
}
