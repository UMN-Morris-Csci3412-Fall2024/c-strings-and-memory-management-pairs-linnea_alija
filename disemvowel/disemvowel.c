#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>  // Include stdbool.h for bool type
#include "disemvowel.h"

// Helper function to check if a character is a vowel
bool is_vowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

char *disemvowel(char *str) {
    int length = strlen(str);
    int new_len = 0;

    // First, count how many non-vowel characters there are
    for (int i = 0; i < length; i++) {
        if (!is_vowel(str[i])) {
            new_len++;
        }
    }

    // Allocate memory for the new string (non-vowel characters + null terminator)
    char *result = (char*) calloc(new_len + 1, sizeof(char));  // +1 for null terminator

    // Copy non-vowel characters to the new string
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (!is_vowel(str[i])) {
            result[j++] = str[i];
        }
    }

    return result;  // Caller is responsible for freeing the memory
}
