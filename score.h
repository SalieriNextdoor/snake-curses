#ifndef SSCORE_H
#define SSCORE_H

#include "scommons.h"
typedef struct _scorepoint {
  point pos;
  WINDOW *win;
} scorepoint;
typedef struct _score {
  uint val;
  char *stringval;
  uint stringlen;
} score;

#include "snake.h"
void draw_spoint(scorepoint *spoint);
void update_spoint(scorepoint *spoint, score *scoreboard, int max_y, int max_x);
void update_score(score *scoreboard, snakehead *head);
void draw_score(score *scoreboard, WINDOW *gamewin, int max_x);
#endif

