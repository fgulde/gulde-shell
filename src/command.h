#ifndef COMMAND_H
#define COMMAND_H

#include <stdio.h>

/**
 * A function pointer type for command handlers.
 *
 * @param argc The number of arguments in argv.
 * @param argv An array of strings representing the command and its arguments.
 * @param output_stream The stream to which the command's output should be written.
 * @return An integer status code indicating the result of command execution.
 */
typedef int (*CommandHandler)(size_t argc, char* argv[], FILE* output_stream);

/**
 * Represents a command with its name and handler function.
 */
typedef struct {
  const char* name;
  CommandHandler handler;
} Command;

#endif