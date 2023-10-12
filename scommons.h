#ifndef SCOMMONS_H
#define SCOMMONS_H
#include <curses.h>

#define ifnullexit(_pntr) \
  if (_pntr == NULL) exit(1)

typedef unsigned int uint;
typedef struct _point {
  uint y;
  uint x;
} point;

char *reverse(char *str, uint length);
char *itoa(uint val, char *buf);
#endif

