#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "palindrome.h"

char *str_reverse(char const *str) {
  int len, i;
  char *result;

  len = strlen(str);
  result = (char*) calloc(len+1, sizeof(char));
  for (i=0; i<len; ++i) {
    result[i] = str[len-i-1];
  }
  result[len] = '\0';
  
  return result;
}

char *palindrome(char const *str) {
  char *rev;
  int i;
  bool result = true;
  char *answer;

  rev = str_reverse(str);
  i = 0;
  while (result && str[i]) {
    if (str[i] != rev[i]) {
      result = false;
    }
    ++i;
  }

  free(rev);  // Free the reversed string

  if (result) {
    answer = (char*) calloc(4, sizeof(char));  // Allocates 4 bytes for "Yes\0"
    strcpy(answer, "Yes");
  } else {
    answer = (char*) calloc(3, sizeof(char));  // Allocates 3 bytes for "No\0"
    strcpy(answer, "No");
  }

  return answer;
}
