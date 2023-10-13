#ifndef SLETTERS_H
#define SLETTERS_H
#include <curses.h>

#include "scommons.h"

#define print_highlight_horizontal(_prwin, _prstarty, _prstartx, _prcnt) \
  wmove(_prwin, _prstarty, _prstartx);                                   \
  for (int i = 0; i < _prcnt; i++) waddch(_prwin, ' ')

#define print_highlight_vertical(_prwin, _prstarty, _prstartx, _prcnt) \
  for (int i = 0; i < _prcnt; i++)                                     \
  mvwaddch(_prwin, _prstarty + i, _prstartx, ' ')

#define TYPEWIDTH 8
#define TYPEHEIGHT 8
#define TYPEGAP 2

void print_s(WINDOW *win, int height, int width, point start);
void print_n(WINDOW *win, int height, int width, point start);
void print_a(WINDOW *win, int height, int width, point start);
void print_k(WINDOW *win, int height, int width, point start);
void print_e(WINDOW *win, int height, int width, point start);

void print_g(WINDOW *win, int height, int width, point start);
void print_m(WINDOW *win, int height, int width, point start);
void print_o(WINDOW *win, int height, int width, point start);
void print_v(WINDOW *win, int height, int width, point start);
void print_r(WINDOW *win, int height, int width, point start);
#endif
