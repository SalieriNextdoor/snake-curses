/*
 * Score structs and functions
 * */
#ifndef SSCORE_H
#define SSCORE_H

#include "scommons.h"
typedef struct _scorepoint {
  point pos;    // point position in the map
  WINDOW *win;  // a 1x1 window representing the score point
} scorepoint;
typedef struct _score {
  uint val;         // the current score value
  char *stringval;  // the score value in string
  uint stringlen;   // the length of the string
} score;

#include "snake.h"
void draw_spoint(scorepoint *spoint);
void update_spoint(scorepoint *spoint, score *scoreboard, int max_y, int max_x);
void update_score(score *scoreboard, snakehead *head);
void draw_score(score *scoreboard, WINDOW *gamewin, int max_x);
#endif

