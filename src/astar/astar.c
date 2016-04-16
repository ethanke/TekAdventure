/*
** astar.c for astar in /Users/leandr_g/Documents/Shared folder/TekAdventure/astar/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** stared on  Fri Apr  8 00:39:34 2016 Gaëtan Léandre
** Last update Fri Apr  8 05:01:19 2016 Gaëtan Léandre
*/

#include	"astar.h"

t_depla		*free_star(t_star *star)
{
  int		i;

  i = 0;
  while (i < star->x)
    {
      free(star->ind_list[i]);
      free(star->open_list[i]);
      i++;
    }
  free(star->ind_list);
  free(star->open_list);
  return (star->depla);
}

t_depla		*a_star(t_ground *ground,
			t_posi *size,
			t_posi *pos,
			t_posi *end)
{
  t_star	star;
  int		cont;

  if (init_star(&star, size, pos, end) == -1)
    return (NULL);
  cont = 1;
  if (init_tab(&star) == -1)
    return (NULL);
  case_is_free(ground, &star, end);
  star.open_list[pos->x][pos->y] = -1;
  star.ind_list[pos->x][pos->y] = 1;
  while ((star.cur_x != star.end_x || star.cur_y != star.end_y) && cont != -1)
    {
      add_proc(&star, star.cur_x, star.cur_y);
      cont = caseProche(&star);
    }
  if ((star.cur_x != star.end_x || star.cur_y != star.end_y)
      || add_in_depla(&star, star.cur_x, star.cur_y) == -1)
    return (NULL);
  while (star.cur_x != pos->x || star.cur_y != pos->y)
    {
      if (best_way(&star) == -1)
	return (NULL);
    }
  return (free_star(&star));
}
