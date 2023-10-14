/*
 * Functions related to printing letters used for the menu logos.
 * Typefont based on the Commodore 64 typefont.
 * */
#include "letters.h"

void print_s(WINDOW *win, int height, int width, point start) {
  print_highlight_horizontal(win, start.y, start.x + 1, width - 2);
  print_highlight_horizontal(win, start.y + 1, start.x, 2);
  print_highlight_horizontal(win, start.y + 2, start.x, 2);
  print_highlight_horizontal(win, start.y + 1, start.x + width - 2, 2);
  print_highlight_horizontal(win, start.y + 3, start.x + 1, width - 2);
  print_highlight_vertical(win, start.y + 4, start.x + width - 2, 3);
  print_highlight_vertical(win, start.y + 4, start.x + width - 1, 3);
  print_highlight_horizontal(win, start.y + height - 1, start.x + 1, width - 2);
  print_highlight_horizontal(win, start.y + height - 2, start.x, 2);
}

void print_n_helper(WINDOW *win, int width, point start) {
  int accum = 1;
  while (accum < width - 1) {
    mvwaddch(win, start.y + accum, start.x + accum, ' ');
    mvwaddch(win, start.y + accum + 1, start.x + accum, ' ');
    accum++;
  }
}

void print_n(WINDOW *win, int height, int width, point start) {
  print_highlight_vertical(win, start.y, start.x, height);
  print_highlight_vertical(win, start.y, start.x + 1, height);
  print_highlight_vertical(win, start.y, start.x + width - 1, height);
  print_highlight_vertical(win, start.y, start.x + width - 2, height);
  start.x++;
  print_n_helper(win, width, start);
}

void print_a(WINDOW *win, int height, int width, point start) {
  print_highlight_vertical(win, start.y + 2, start.x, height - 2);
  print_highlight_vertical(win, start.y + 2, start.x + width - 1, height - 2);
  print_highlight_vertical(win, start.y + 2, start.x + 1, height - 2);
  print_highlight_vertical(win, start.y + 2, start.x + width - 2, height - 2);
  print_highlight_horizontal(win, start.y + 1, start.x + 1, width - 2);
  print_highlight_horizontal(win, start.y, start.x + 2, width - 4);
  print_highlight_horizontal(win, start.y + height / 2, start.x + 1, width - 2);
}

void print_k_helper(WINDOW *win, int height, int width, point start) {
  start.x--;
  while (width > 0 && height > 0) {
    mvwaddch(win, start.y, start.x + width - 1, ' ');
    mvwaddch(win, start.y, start.x + width - 2, ' ');
    mvwaddch(win, start.y + height - 1, start.x + width - 1, ' ');
    mvwaddch(win, start.y + height - 1, start.x + width - 2, ' ');
    start.y++;
    width--;
    height -= 2;
  }
}

void print_k(WINDOW *win, int height, int width, point start) {
  print_highlight_vertical(win, start.y, start.x, height);
  start.x++;
  print_highlight_vertical(win, start.y, start.x, height);
  print_highlight_horizontal(win, start.y + height / 2, start.x + 1, width / 4);
  print_k_helper(win, height, width, start);
}

void print_e(WINDOW *win, int height, int width, point start) {
  print_highlight_horizontal(win, start.y, start.x, width);
  print_highlight_horizontal(win, start.y + height - 1, start.x, width);
  print_highlight_horizontal(win, start.y + height / 2 - 1, start.x,
                             2 * width / 3 + 1);
  print_highlight_vertical(win, start.y, start.x, height);
  print_highlight_vertical(win, start.y, start.x + 1, height);
}

void print_g(WINDOW *win, int height, int width, point start) {
  print_highlight_horizontal(win, start.y, start.x + 2, width - 3);
  print_highlight_horizontal(win, start.y + 1, start.x + 1, 2);
  print_highlight_horizontal(win, start.y + 1, start.x + width - 2, 2);
  print_highlight_vertical(win, start.y + 2, start.x, 4);
  print_highlight_vertical(win, start.y + 2, start.x + 1, 4);
  print_highlight_horizontal(win, start.y + height - 2, start.x + 1, 2);
  print_highlight_horizontal(win, start.y + height - 1, start.x + 2, 5);
  print_highlight_vertical(win, start.y + height - 4, start.x + width - 1, 3);
  print_highlight_vertical(win, start.y + height - 4, start.x + width - 2, 3);
  print_highlight_horizontal(win, start.y + height - 4, start.x + width - 4, 2);
}
void print_m(WINDOW *win, int height, int width, point start) {
  print_highlight_vertical(win, start.y, start.x, height);
  print_highlight_vertical(win, start.y, start.x + 1, height);
  print_highlight_vertical(win, start.y, start.x + width - 1, height);
  print_highlight_vertical(win, start.y, start.x + width - 2, height);
  print_highlight_vertical(win, start.y + 1, start.x + 2, 2);
  print_highlight_vertical(win, start.y + 1, start.x + 5, 2);
  print_highlight_vertical(win, start.y + 2, start.x + 3, 2);
  print_highlight_vertical(win, start.y + 2, start.x + 4, 2);
}
void print_o(WINDOW *win, int height, int width, point start) {
  print_highlight_vertical(win, start.y + 1, start.x, height - 2);
  print_highlight_vertical(win, start.y + 1, start.x + width - 1, height - 2);
  print_highlight_vertical(win, start.y, start.x + 1, height);
  print_highlight_vertical(win, start.y, start.x + width - 2, height);
  print_highlight_horizontal(win, start.y, start.x + 2, width - 4);
  print_highlight_horizontal(win, start.y + 1, start.x + 2, width - 4);
  print_highlight_horizontal(win, start.y + height - 1, start.x + 2, width - 4);
  print_highlight_horizontal(win, start.y + height - 2, start.x + 2, width - 4);
}
void print_v(WINDOW *win, int height, int width, point start) {
  print_highlight_vertical(win, start.y, start.x, height - 2);
  print_highlight_vertical(win, start.y, start.x + 1, height - 1);
  print_highlight_vertical(win, start.y, start.x + width - 1, height - 2);
  print_highlight_vertical(win, start.y, start.x + width - 2, height - 1);
  print_highlight_horizontal(win, start.y + height - 2, start.x + 2, 4);
  print_highlight_horizontal(win, start.y + height - 1, start.x + 3, 2);
}
void print_r(WINDOW *win, int height, int width, point start) {
  print_highlight_vertical(win, start.y, start.x, height);
  print_highlight_vertical(win, start.y, start.x + 1, height);
  print_highlight_horizontal(win, start.y, start.x, width - 1);
  print_highlight_vertical(win, start.y, start.x + width - 2, 4);
  print_highlight_vertical(win, start.y + 1, start.x + width - 1, 2);
  print_highlight_horizontal(win, start.y + 3, start.x + 2, 4);
  print_highlight_horizontal(win, start.y + 4, start.x + 2, 3);
  print_highlight_horizontal(win, start.y + 5, start.x + 4, 2);
  print_highlight_horizontal(win, start.y + 6, start.x + 5, 2);
  print_highlight_horizontal(win, start.y + 7, start.x + 6, 2);
}
