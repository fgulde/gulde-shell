#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>

/**
 * Parses the input string and executes the corresponding command.
 *
 * @param input The input string containing the command and its arguments.
 * @param output_stream The stream to which the command's output should be written.
 * @return An integer status code indicating the result of command execution.
 */
int shell_execute_input(char* input, FILE* output_stream);

#endif