#ifndef COMMAND_DISPATCHER_H
#define COMMAND_DISPATCHER_H

#include <stdio.h>

/**
 * Dispatches the command based on the provided arguments.
 *
 * @param argc The number of arguments in argv.
 * @param argv An array of strings representing the command and its arguments.
 * @param output_stream The stream to which the command's output should be written.
 * @return An integer status code indicating the result of command execution.
 */
int dispatch_command(size_t argc, char* argv[], FILE* output_stream);

#endif