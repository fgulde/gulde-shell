#include <stdio.h>

#include "command_dispatcher.h"
#include "command_registry.h"

int dispatch_command(const size_t argc, char* argv[], FILE* output_stream) {
  if (argc == 0) {
    return 0;
  }

  const Command* command = find_command(argv[0]);

  // If the command is not found, print an error message to the output stream
  if (command == NULL) {
    if (fputs(argv[0], output_stream) == EOF) {
      return 1;
    }
    if (fputs(": command not found\n", output_stream) == EOF) {
      return 1;
    }
    return 0;
  }

  return command->handler(argc, argv, output_stream);
}