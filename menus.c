/*
 * Prints the menus logos and messages.
 * */
#include "menus.h"

#include <curses.h>

#include "letters.h"

void print_menu_msg(WINDOW *win, point start, char *msg) {
  wattron(win, A_BLINK | A_BOLD);
  mvwaddstr(win, start.y, start.x, msg);
  wattroff(win, A_BLINK | A_BOLD);
}

void print_start_logo(WINDOW *win, point start) {
  int gap = TYPEGAP + TYPEWIDTH;
  wattron(win, A_REVERSE);
  print_s(win, TYPEHEIGHT, TYPEWIDTH, start);
  start.x += gap;
  print_n(win, TYPEHEIGHT, TYPEWIDTH, start);
  start.x += gap;
  print_a(win, TYPEHEIGHT, TYPEWIDTH, start);
  start.x += gap;
  print_k(win, TYPEHEIGHT, TYPEWIDTH, start);
  start.x += gap;
  print_e(win, TYPEHEIGHT, TYPEWIDTH, start);
  wattroff(win, A_REVERSE);
}

void print_end_logo(WINDOW *win, point start) {
  int gap = TYPEGAP + TYPEWIDTH;
  wattron(win, A_REVERSE);
  print_g(win, TYPEHEIGHT, TYPEWIDTH, start);
  start.x += gap;
  print_a(win, TYPEHEIGHT, TYPEWIDTH, start);
  start.x += gap;
  print_m(win, TYPEHEIGHT, TYPEWIDTH, start);
  start.x += gap;
  print_e(win, TYPEHEIGHT, TYPEWIDTH, start);

  start.x -= gap * 3;
  start.y += TYPEHEIGHT + TYPEGAP;
  print_o(win, TYPEHEIGHT, TYPEWIDTH, start);
  start.x += gap;
  print_v(win, TYPEHEIGHT, TYPEWIDTH, start);
  start.x += gap;
  print_e(win, TYPEHEIGHT, TYPEWIDTH, start);
  start.x += gap;
  print_r(win, TYPEHEIGHT, TYPEWIDTH, start);
  wattroff(win, A_REVERSE);
}

