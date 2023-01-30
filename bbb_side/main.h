/**
 * @file main.h
 * @author Omer Penso
 * @brief This file will contain general data and definitions for the entire project.
 * @date 24-01-2023
 */
#ifndef MY_MAIN_FILE_OP
#define MY_MAIN_FILE_OP

/// FUNCTIONS:

/**
 * @brief This function will read the operation assigned to the gps global variable, and send to 
 * the server. If the end flag is on, reset the gps global variable.
 */
void op_read();

void print_gps();

#endif