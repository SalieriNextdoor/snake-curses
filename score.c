#include "score.h"

#include <curses.h>
#include <stdlib.h>
#include <string.h>

void draw_spoint(scorepoint *spoint) {
  delwin(spoint->win);
  spoint->win = newwin(1, 1, spoint->pos.y, spoint->pos.x);
  ifnullexit(spoint->win);
  wattron(spoint->win, A_REVERSE);
  mvwaddch(spoint->win, 0, 0, ' ');
  wattroff(spoint->win, A_REVERSE);
  wrefresh(spoint->win);
}

void update_spoint(scorepoint *spoint, score *scoreboard, int max_y,
                   int max_x) {
  spoint->pos.y = random() % max_y;
  spoint->pos.x = random() % max_x;

  // edge case where point spawn behind score
  if (spoint->pos.y == 2 &&
      spoint->pos.x > 1 + (max_x - scoreboard->stringlen) / 2 &&
      spoint->pos.x < max_x / 2 + 3)
    update_spoint(spoint, scoreboard, max_y, max_x);
}

void update_score(score *scoreboard, snakehead *head) {
  scoreboard->stringval = itoa(++scoreboard->val, scoreboard->stringval);
  scoreboard->stringlen = strlen(scoreboard->stringval);
  init_snakepart(&head->next);
}

void draw_score(score *scoreboard, WINDOW *gamewin, int max_x) {
  mvwprintw(gamewin, 1, 1 + (max_x - scoreboard->stringlen) / 2, "%s",
            scoreboard->stringval);
  wrefresh(gamewin);
}

