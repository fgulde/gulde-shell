#include "shell.h"

#include "command_dispatcher.h"
#include "input_parser.h"

#include <stddef.h>

int shell_execute_input(char* input, FILE* output_stream) {
  constexpr size_t MAX_ARGUMENTS = 64;
  char* argv[MAX_ARGUMENTS]; // Array to hold pointers to the arguments

  const size_t argc = parse_input(input, argv, MAX_ARGUMENTS);

  return dispatch_command(argc, argv, output_stream);
}