#include "command_registry.h"

#include <string.h>
#include <stdlib.h>

static int command_exit(const size_t argc, char* argv[], const FILE* output_stream) {
  (void)output_stream;
  int exit_code = 0;
  if (argc > 1) {
    constexpr int DECIMAL_BASE = 10;
    exit_code = (int)strtol(argv[1], nullptr, DECIMAL_BASE);
  }
  _Exit(exit_code);
}

static int command_echo(const size_t argc, char* argv[], FILE* output_stream) {
  for (size_t i = 1; i < argc; i++) {
    if (i > 1) {
      if (fputc(' ', output_stream) == EOF) {
        return 1;
      }
    }
    if (fputs(argv[i], output_stream) == EOF) {
      return 1;
    }
  }
  if (fputc('\n', output_stream) == EOF) {
    return 1;
  }

  return 0;
}

static const Command COMMANDS[] = {
    {.name = "echo", .handler = command_echo},
    {.name = "exit", .handler = (CommandHandler)command_exit},
};

const Command* find_command(const char* command_name) {
  constexpr size_t command_count = sizeof(COMMANDS) / sizeof(COMMANDS[0]);
  for (size_t i = 0; i < command_count; i++) {
    if (strcmp(COMMANDS[i].name, command_name) == 0) {
      return &COMMANDS[i];
    }
  }

  return nullptr;
}