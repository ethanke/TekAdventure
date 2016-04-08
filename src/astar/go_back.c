/*
** go_back.c for astar in /Users/leandr_g/Documents/Shared folder/TekAdventure/astar/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Fri Apr  8 06:28:48 2016 Gaëtan Léandre
** Last update Fri Apr  8 06:29:44 2016 Gaëtan Léandre
*/

#include	"astar.h"

int		add_in_depla(t_star *star, int x, int y)
{
  t_depla	*depla;

  if ((depla = malloc(sizeof(t_depla))) == NULL)
    return (-1);
  depla->next = star->depla;
  depla->x = x;
  depla->y = y;
  star->depla = depla;
  return (1);
}

t_ind		take_way(t_star *star, int x, int y)
{
  t_ind		indice;

  indice.indice = star->ind_list[x][y];
  indice.x = x;
  indice.y = y;
  return (indice);
}

int		best_way(t_star *star)
{
  int		i;
  int		j;
  int		tmp_x;
  int		tmp_y;
  t_ind		ind;

  ind = take_way(star, star->cur_x, star->cur_y);
  i = -1;
  while (i < 2)
    {
      j = -1;
      while (j < 2)
	{
	  tmp_x = star->cur_x + i;
	  tmp_y = star->cur_y + j;
	  if ((TRAVERS == 1 || (j == 0 || i == 0)) && (tmp_x >= 0 && tmp_y >= 0
	       && tmp_x < star->x && tmp_y < star->y) && (j != 0 || i != 0)
	      && star->ind_list[tmp_x][tmp_y] > 0
	      && ind.indice > star->ind_list[tmp_x][tmp_y])
	    ind = take_way(star, tmp_x, tmp_y);
	  j++;
	}
      i++;
    }
  return (add_in_depla(star, (star->cur_x = ind.x), (star->cur_y = ind.y)));
}
