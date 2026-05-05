#include <stdio.h>

#include "shell.h"

int main() {
  constexpr size_t MAX_INPUT_LENGTH = 1024;
  char input[MAX_INPUT_LENGTH];

  // REPL (Read-Evaluate-Print Loop)
  for (;;) {
    printf("$ ");
    (void)fflush(stdout);

    if (fgets(input, sizeof(input), stdin) == NULL) {
      break;
    }

    (void)shell_execute_input(input, stdout);
  }

  return 0;
}