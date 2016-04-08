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
  int		j;

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

t_depla		*a_star(char **obj, t_posi size, t_posi pos, t_posi end)
{
  t_star	star;

  star.x = size.x;
  star.y = size.y;
  star.cur_x = pos.x;
  star.cur_y = pos.y;
  star.end_x = end.x;
  star.end_y = end.y;
  star.depla = NULL;
  if (init_tab(&star) == -1)
    return (NULL);
  case_is_free(obj, &star);
  star.open_list[pos.x][pos.y] = -1;
  star.ind_list[pos.x][pos.y] = 1;
  while (star.cur_x != star.end_x || star.cur_y != star.end_y)
    {
      add_proc(&star, star.cur_x, star.cur_y);
      caseProche(&star);
    }
  if (add_in_depla(&star, star.cur_x, star.cur_y) == -1)
    return (NULL);
  while (star.cur_x != pos.x || star.cur_y != pos.y)
    if (best_way(&star) == -1)
      return (NULL);
  return (free_star(&star));
}

int		main()
{
  t_posi	size;
  t_posi	pos;
  t_posi	end;
  char		**map;
  t_depla	*depla;

  map = malloc(sizeof(char*) * 5);
  map[0] = malloc(sizeof(char) * 5);
  map[0][0] = 0;
  map[0][1] = 0;
  map[0][2] = 0;
  map[0][3] = 0;
  map[0][4] = 0;
  map[1] = malloc(sizeof(char) * 5);
  map[1][0] = 0;
  map[1][1] = 1;
  map[1][2] = 0;
  map[1][3] = 0;
  map[1][4] = 0;
  map[2] = malloc(sizeof(char) * 5);
  map[2][0] = 0;
  map[2][1] = -1;
  map[2][2] = 0;
  map[2][3] = 0;
  map[2][4] = 0;
  map[3] = malloc(sizeof(char) * 5);
  map[3][0] = 0;
  map[3][1] = -1;
  map[3][2] = 0;
  map[3][3] = 0;
  map[3][4] = 0;
  map[4] = malloc(sizeof(char) * 5);
  map[4][0] = 0;
  map[4][1] = -1;
  map[4][2] = 0;
  map[4][3] = 0;
  map[4][4] = 0;
  size.x = 5;
  size.y = 5;
  pos.x = 0;
  pos.y = 0;
  end.x = 4;
  end.y = 4;
  depla = a_star(map, size, pos, end);
  while (depla != NULL)
    {
      printf("%d %d\n", depla->x, depla->y);
      depla = depla->next;
    }
  return (0);
}
