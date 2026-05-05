#include <stdio.h>

int main() {
  char input[256];

  for (;;) {
    printf("$ ");
    fflush(stdout);

    if (fgets(input, sizeof(input), stdin) == NULL) {
      break;
    }

    //
    char* command_name = input;
    while (*command_name == ' ' || *command_name == '\t') {
      command_name++;
    }

    char* end = command_name;
    while (*end != '\0' && *end != ' ' && *end != '\t' && *end != '\n') {
      end++;
    }
    *end = '\0';

    if (*command_name != '\0') {
      printf("%s: command not found\n", command_name);
    }
  }

  return 0;
}