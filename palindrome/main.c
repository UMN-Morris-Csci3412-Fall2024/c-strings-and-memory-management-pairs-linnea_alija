#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palindrome.h"

int main(int argc, char *argv[]) {
  char *line;
  int size;
  char *palin;
  
  size = 100;
  line = (char*) calloc (size + 1, sizeof(char));

  // Loop to read input lines
  while (fgets(line, size, stdin) != NULL) {
    line[strcspn(line, "\n")] = '\0';  // Remove newline character

    palin = palindrome(line);          // Get palindrome result
    printf("Is the string <%s> a palindrome? %s\n", line, palin);

    free(palin);  // Free memory for palin after each iteration
  }

  free(line);  // Free the line buffer
}
