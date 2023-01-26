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
 * @brief This function will close all file descriptors that have been open during the program
 * runtime, and use exit function based on the status received as parameter.
 * 
 * @param status - the status with which we got into this function.
 */
void my_exit(int status);

#endif