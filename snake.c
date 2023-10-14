/*
 *  Functions related to updating the position and direction of
 *  snake head and tail, and the drawing of them.
 * */
#include "snake.h"

#include <stdlib.h>

/*
 *  Helper function for internal use.
 *  Given a direction, returns its opposite.
 *  If given M_DISABLED, returns M_DISABLED.
 * */
enum direction invert_dir(enum direction dir) {
  switch (dir) {
    case M_UP:
      return M_DOWN;
      break;
    case M_DOWN:
      return M_UP;
      break;
    case M_RIGHT:
      return M_LEFT;
      break;
    case M_LEFT:
      return M_RIGHT;
      break;
    case M_DISABLED:
      return M_DISABLED;
      break;
  }
  return M_DISABLED;  // will never happen
}

/*
 *  Helper function for internal use.
 *  Given a direction, updates a position struct according to it.
 *  If given M_DISABLED, does nothing.
 * */
void update_for_dir(point *pos, enum direction dir) {
  switch (dir) {
    case M_UP:
      pos->y--;
      break;
    case M_DOWN:
      pos->y++;
      break;
    case M_RIGHT:
      pos->x++;
      break;
    case M_LEFT:
      pos->x--;
      break;
    case M_DISABLED:
      break;
  }
}

/*
 * Initializes the next tail piece.
 * Given a snakepart struct, adds a new snakepart to the end of the list.
 * */
void init_snakepart(snakepart **fp) {
  if (*fp != NULL) return init_snakepart(&(*fp)->next);
  *fp = (snakepart *)malloc(sizeof(snakepart));
  ifnullexit(fp);
  (*fp)->dir = M_DISABLED;
  (*fp)->next = NULL;
}

/*
 *  Cleanup function.
 *  Given a snakepart, deletes all snakeparts ahead of it, including it.
 * */
void delete_snakeparts(snakepart *fp) {
  if (fp == NULL) return;
  snakepart *next = fp->next;
  free(fp);
  delete_snakeparts(next);
}

/*
 *  Draws the snake tail according to updated position.
 *  Returns false if it is detected that a piece of tail
 *  touched the head, otherwise returns true.
 * */
bool draw_tail(WINDOW *win, snakepart *p, point pos, snakehead *head) {
  if (p == NULL) return true;

  update_for_dir(&pos, p->dir);
  if (p->dir == M_DISABLED)
    update_for_dir(&pos, invert_dir(head->headdir));
  else if (pos.x == head->pos.x && pos.y == head->pos.y)
    return false;  // head touched tail

  wattron(win, A_REVERSE);
  mvwaddch(win, pos.y, pos.x, ' ');
  wattroff(win, A_REVERSE);

  return draw_tail(win, p->next, pos, head);
}

/*
 *  Draws the snake head and tail in its position.
 *  If the head coincides with a score point, calls score
 *  update functions.
 *  Returns the result of draw_tail.
 * */
bool draw_head(WINDOW *win, snakehead *head, scorepoint *spoint,
               score *scoreboard, int max_y, int max_x) {
  wclear(win);
  wattron(win, A_REVERSE);
  mvwaddch(win, head->pos.y, head->pos.x, ' ');
  wattroff(win, A_REVERSE);

  if (head->pos.x == spoint->pos.x && head->pos.y == spoint->pos.y) {
    update_score(scoreboard, head);
    update_spoint(spoint, scoreboard, max_y, max_x);
    draw_spoint(spoint);
  }
  return draw_tail(win, head->next, head->pos, head);
}

/*
 *  Updates the direction of a tail piece according to
 *  previous direction given.
 * */
void update_tail_dir(snakepart *p, enum direction prevdir) {
  if (p == NULL) return;

  enum direction old = p->dir;
  p->dir = prevdir;

  update_tail_dir(p->next, old);
}

/*
 *  Updates the head and tail position according to head direction.
 *  Returns false if head is to go beyond border.
 *  Otherwise returns true.
 * */
bool update_head_pos(snakehead *head, enum direction dir, int max_y,
                     int max_x) {
  update_for_dir(&head->pos, dir);

  // snake goes out of game window
  // since pos values are unsigned, we only need to check for upper limits
  if (head->pos.x >= max_x || head->pos.y >= max_y) return false;
  update_tail_dir(head->next, invert_dir(dir));
  return true;
}
