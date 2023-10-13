#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "menus.h"
#include "scommons.h"
#include "snake.h"

#define DELAYU 100000UL

snakehead head = {{0, 0}, M_UP, NULL};
scorepoint spoint;
score scoreboard;
int max_y, max_x;
bool force_exit = false;

void init_structs(void) {
  init_snakepart(&head.next);
  head.pos.x = max_x / 2;
  head.pos.y = max_y / 2;
  update_spoint(&spoint, &scoreboard, max_y, max_x);
  spoint.win = newwin(1, 1, spoint.pos.y, spoint.pos.x);
  scoreboard.val = 0;
  // 3 digits + null char
  scoreboard.stringval = (char *)malloc(4 * sizeof(char));
  ifnullexit(scoreboard.stringval);
  *scoreboard.stringval = '0';
  *(scoreboard.stringval + 1) = '\0';
  scoreboard.stringlen = 1;
}

void init_curses(void) {
  initscr();
  cbreak();
  noecho();
  curs_set(0);
}

void load_start_menu(void) {
  int c;
  int y, x;
  int totalwidth = TYPEWIDTH * 5 + TYPEGAP * 4;
  WINDOW *startwin = newwin(0, 0, 0, 0);
  ifnullexit(startwin);
  keypad(startwin, TRUE);
  getmaxyx(startwin, y, x);

  point start_logo = {
      (y - TYPEHEIGHT) / 4,
      (x - totalwidth) / 2,
  };
  char *msg = strdup("PRESS <ENTER> TO START");
  point start_msg = {
      (int)y / 1.5,
      (x - strlen(msg)) / 2,
  };
  print_start_logo(startwin, start_logo);
  print_menu_msg(startwin, start_msg, msg);
  mvwaddstr(startwin, 0, 0, "PRESS <F3> TO EXIT");
  wrefresh(startwin);

  while ((c = wgetch(startwin)) != '\n' && c != KEY_F(3))
    ;
  if (c == KEY_F(3)) force_exit = true;
  wclear(startwin);
  delwin(startwin);
  free(msg);
}

void load_end_menu(void) {
  int y, x;
  int totalwidth = TYPEWIDTH * 4 + TYPEGAP * 3;
  WINDOW *endwin = newwin(0, 0, 0, 0);
  ifnullexit(endwin);
  getmaxyx(endwin, y, x);

  point end_logo = {
      (y - TYPEHEIGHT * 2 - TYPEGAP) / 2 - 2,
      (x - totalwidth) / 2,
  };
  char *msg = strdup("PRESS <ENTER> TO EXIT");
  char *msg2 = strdup("FINAL SCORE: ");
  point end_msg = {
      y - 2,
      (x - strlen(msg)) / 2,
  };
  print_end_logo(endwin, end_logo);
  mvwaddstr(endwin, y - 3, (x - strlen(msg2) - scoreboard.stringlen) / 2, msg2);
  waddstr(endwin, scoreboard.stringval);
  print_menu_msg(endwin, end_msg, msg);
  wrefresh(endwin);

  while (wgetch(endwin) != '\n')
    ;
  wclear(endwin);
  delwin(endwin);
  free(msg);
  free(msg2);
}

void init_game(WINDOW **gamewin) {
  *gamewin = newwin(0, 0, 0, 0);
  ifnullexit(*gamewin);
  wtimeout(*gamewin, 0);
  keypad(*gamewin, TRUE);
  getmaxyx(*gamewin, max_y, max_x);
}

void cleanup(WINDOW *gamewin) {
  wclear(spoint.win);
  delwin(spoint.win);
  wclear(gamewin);
  delwin(gamewin);
  delete_snakeparts(head.next);
}

int main() {
  WINDOW *gamewin;
  int c;

  init_curses();

  load_start_menu();

  init_game(&gamewin);
  srandom(time(NULL));
  init_structs();

  enum direction default_dir = head.headdir;
  draw_spoint(&spoint);
  while ((c = wgetch(gamewin)) != KEY_F(3) && !force_exit) {
    flushinp();
    draw_score(&scoreboard, gamewin, max_x);
    if (!draw_head(gamewin, &head, &spoint, &scoreboard, max_y, max_x)) break;
    redrawwin(spoint.win);
    wrefresh(spoint.win);

    usleep(DELAYU);
    switch (c) {
      case KEY_UP:
        default_dir = M_UP;
        break;
      case KEY_DOWN:
        default_dir = M_DOWN;
        break;
      case KEY_LEFT:
        default_dir = M_LEFT;
        break;
      case KEY_RIGHT:
        default_dir = M_RIGHT;
        break;
    }
    if (!update_head_pos(&head, default_dir, max_y, max_x)) break;
  }
  cleanup(gamewin);

  if (!force_exit && c != KEY_F(3)) load_end_menu();

  free(scoreboard.stringval);
  endwin();
  return 0;
}
