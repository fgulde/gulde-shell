#include <stdio.h>

int main() {
  printf("$ ");
  fflush(stdout);

  // Wait for user input
  char input[256];
  fgets(input, 256, stdin);

  return 0;
}