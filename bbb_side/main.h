/**
 * @file main.h
 * @author Omer Penso
 * @brief This file will contain general data and definitions for the entire project.
 * @date 24-01-2023
 */
#ifndef MY_MAIN_FILE_OP
#define MY_MAIN_FILE_OP

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

#endif