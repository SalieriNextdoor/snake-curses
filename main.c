#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "snake.h"

#define DELAYU 100000UL

snakehead head = {{0, 0}, M_UP, NULL};
scorepoint spoint;
score scoreboard;
int max_y, max_x;

void init_structs(void) {
  init_snakepart(&head.next);
  head.pos.x = max_x / 2;
  head.pos.y = max_y / 2;
  update_spoint(&spoint, &scoreboard, max_y, max_x);
  spoint.win = newwin(1, 1, spoint.pos.y, spoint.pos.x);
  scoreboard.val = 0;
  scoreboard.stringval = strdup("0");
  scoreboard.stringlen = 1;
}

void init_curses(WINDOW **gamewin) {
  initscr();
  cbreak();
  noecho();
  curs_set(0);

  *gamewin = newwin(0, 0, 0, 0);
  wtimeout(*gamewin, 0);
  keypad(*gamewin, TRUE);
  getmaxyx(*gamewin, max_y, max_x);
}

int main() {
  WINDOW *gamewin;
  int c;

  init_curses(&gamewin);
  srandom(time(NULL));
  init_structs();

  enum direction default_dir = head.headdir;
  draw_spoint(&spoint);
  while ((c = wgetch(gamewin)) != KEY_F(3)) {
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

  delwin(gamewin);
  delete_snakeparts(head.next);
  endwin();
  return 0;
}
