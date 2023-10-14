/*
 * Functions and structs related to snake head and tail handling.
 * */
#ifndef SNAKE_H
#define SNAKE_H

#include <stdbool.h>

#include "scommons.h"

enum direction { M_DISABLED, M_UP, M_DOWN, M_LEFT, M_RIGHT };
typedef struct _snakepart {  // tail parts
  enum direction dir;
  struct _snakepart *next;  // tail is a linked list
} snakepart;
typedef struct _snakehead {
  point pos;  // position of the head
  enum direction headdir;
  struct _snakepart *next;
} snakehead;

#include "score.h"

void init_snakepart(snakepart **fp);
void delete_snakeparts(snakepart *fp);
bool draw_tail(WINDOW *win, snakepart *p, point pos, snakehead *head);
bool draw_head(WINDOW *win, snakehead *head, scorepoint *spoint,
               score *scoreboard, int max_y, int max_x);
bool update_head_pos(snakehead *head, enum direction dir, int max_y, int max_x);
void update_tail_dir(snakepart *p, enum direction prevdir);
#endif

