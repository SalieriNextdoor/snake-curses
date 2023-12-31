/*
 *  Utilities functions for internal use of other functions.
 * */
#include "scommons.h"

#include <stdlib.h>
#include <string.h>

/*
 *  Given a string and its length, reverses it.
 *  Returns a pointer to the first character.
 * */
char *reverse(char *str, uint length) {
  char *temp = strdup(str);
  ifnullexit(temp);
  temp += length;

  while (*str != '\0') *str++ = *--temp;
  free(temp);
  return str - length;
}

/*
 *  Given an int value and a char buffer, adds digits in character
 *  form to buffer.
 *  Returns a pointer to the first char of the buffer.
 * */
char *itoa(uint val, char *buf) {
  char *bufbegin = buf;
  do {
    *buf++ = (val % 10) + '0';
    val /= 10;
  } while (val != 0);
  *buf = '\0';
  return reverse(bufbegin, buf - bufbegin);
}

