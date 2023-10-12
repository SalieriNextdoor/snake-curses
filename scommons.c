#include "scommons.h"

#include <stdlib.h>
#include <string.h>

char *reverse(char *str, uint length) {
  char *temp = strdup(str);
  temp += length;

  while (*str != '\0') *str++ = *--temp;
  free(temp);
  return str - length;
}

char *itoa(uint val, char *buf) {
  char *bufbegin = buf;
  do {
    *buf++ = (val % 10) + '0';
    val /= 10;
  } while (val != 0);
  *buf = '\0';
  return reverse(bufbegin, buf - bufbegin);
}

