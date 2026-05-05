#include "input_parser.h"

#include <ctype.h>

size_t parse_input(char* input, char* argv[], const size_t max_arguments) {
  size_t argc = 0;
  char* cursor = input;

  // Loop through the input string and tokenize it based on whitespace
  while (*cursor) {
    // Skip leading whitespace
    while (*cursor && (isspace((unsigned char) *cursor) != 0)) {
      cursor++;
    }

    // If we reached the end of the string, break
    if (!(*cursor)) {
      break;
    }

    if (argc == max_arguments) {
      break;
    }

    argv[argc] = cursor; // Set the current argument to the start of the token
    argc++;

    // Move the cursor to the end of the current token
    while (*cursor && (isspace((unsigned char) *cursor) == 0)) {
      cursor++;
    }

    // Null-terminate the current token
    if (*cursor == '\0') {
      break;
    }

    *cursor = '\0';
    cursor++;
  }

  return argc;
}