#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disemvowel.h"

int main(int argc, char *argv[]) {
    char *line = NULL;  // getline will allocate memory
    size_t size = 0;
    char *disemvoweled;

    // Read input line by line
    while (getline(&line, &size, stdin) > 0) {
        disemvoweled = disemvowel(line);  // Call disemvowel
        printf("%s\n", disemvoweled);     // Print the disemvoweled string

        free(disemvoweled);               // Free memory allocated by disemvowel
    }

    free(line);  // Free memory allocated by getline
}
