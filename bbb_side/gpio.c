#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include "gpio.h"

static int output_fd;
static int input_fd;

void setup_output_gpio() {
    // Export the output GPIO
    int fd = open("/sys/class/gpio/export", O_WRONLY);
    if (fd < 0) {
        perror("Failed to open export file");
        exit(EXIT_FAILURE);
    }
    write(fd, OUTPUT_GPIO, strlen(OUTPUT_GPIO));
    close(fd);

    // Set the output GPIO as an output
    char buf[64];
    sprintf(buf, "/sys/class/gpio/gpio%s/direction", OUTPUT_GPIO);
    output_fd = open(buf, O_WRONLY);
    if (output_fd < 0) {
        perror("Failed to open direction file");
        exit(EXIT_FAILURE);
    }
    write(output_fd, "out", 3);
}

void setup_input_gpio() {
    // Export the input GPIO
    int fd = open("/sys/class/gpio/export", O_WRONLY);
    if (fd < 0) {
        perror("Failed to open export file");
        exit(EXIT_FAILURE);
    }
    write(fd, INPUT_GPIO, strlen(INPUT_GPIO));
    close(fd);

    // Set the input GPIO as an input
    char buf[64];
    sprintf(buf, "/sys/class/gpio/gpio%s/direction", INPUT_GPIO);
    input_fd = open(buf, O_RDONLY);
    if (input_fd < 0) {
        perror("Failed to open direction file");
        exit(EXIT_FAILURE);
    }
    write(input_fd, "in", 2);

    sprintf(buf, "/sys/class/gpio/gpio%s/pull", INPUT_GPIO);
    int pull_fd = open(buf, O_WRONLY);
    if (pull_fd < 0) {
        perror("Failed to open pull file");
        exit(EXIT_FAILURE);
    }
    write(pull_fd, "down", 4);
    close(pull_fd);
}

void cleanup_gpio() {
    // Clean up by unexporting the pins
    int fd = open("/sys/class/gpio/unexport", O_WRONLY);
    if (fd < 0) {
        perror("Failed to open unexport file");
        exit(EXIT_FAILURE);
    }
    write(fd, OUTPUT_GPIO, strlen(OUTPUT_GPIO));
    write(fd, INPUT_GPIO, strlen(INPUT_GPIO));
    close(fd);
}