#ifndef SSTARTMENU_H
#define SSTARTMENU_H
#include <curses.h>

#include "scommons.h"
void print_start_logo(WINDOW *win, point start);
void print_end_logo(WINDOW *win, point start);
void print_menu_msg(WINDOW *win, point start, char *msg);
#endif

#ifndef TYPEWIDTH
#define TYPEWIDTH 8
#define TYPEHEIGHT 8
#define TYPEGAP 2
#endif

