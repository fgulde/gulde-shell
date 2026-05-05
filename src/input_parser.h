#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include <stddef.h>

/**
 * Parses the input string into an array of arguments.
 *
 * @param input The input string to parse.
 * @param argv An array to store the parsed arguments.
 * @param max_arguments The maximum number of arguments to parse.
 * @return The number of arguments parsed and stored in argv.
 */
size_t parse_input(char* input, char* argv[], size_t max_arguments);

#endif