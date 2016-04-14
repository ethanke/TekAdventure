/*
** init_tab.c for astar in /Users/leandr_g/Documents/Shared folder/TekAdventure/astar/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Fri Apr  8 06:25:15 2016 Gaëtan Léandre
** Last update Thu Apr 14 06:12:43 2016 Gaëtan Léandre
*/

#include	"astar.h"

int		init_tab(t_star *star)
{
  int		i;
  int		j;

  if ((star->ind_list = malloc(sizeof(int *) * star->x)) == NULL
      || (star->open_list = malloc(sizeof(int *) * star->x)) == NULL)
    return (-1);
  i = 0;
  while (i < star->x)
    {
      if ((star->ind_list[i] = malloc(sizeof(int) * star->y)) == NULL
	  || (star->open_list[i] = malloc(sizeof(int) * star->y)) == NULL)
	return (-1);
      j = 0;
      while (j < star->y)
	{
	  star->ind_list[i][j] = 0;
	  star->open_list[i][j] = 0;
	  j++;
	}
      i++;
    }
  return (0);
}

void	 	case_is_free(t_ground *ground, t_star *star, t_posi *end)
{
  int		i;
  int		j;

  i = 0;
  while (i < star->x)
    {
      j = 0;
      while (j < star->y)
	{
	  if (ground[i + j * star->x].npc != NULL
	      || ground[i + j * star->x].decors != NULL
	      || (ground[i + j * star->x].gate != NULL
		  && (end->x != i || end->y != j)))
	    {
	      star->ind_list[i][j] = -1;
	      star->open_list[i][j] = -1;
	    }
	  j++;
	}
      i++;
    }
}

int		init_star(t_star *star, t_posi *size, t_posi *pos, t_posi *end)
{
  star->x = size->x;
  star->y = size->y;
  if (size->x < 1 || size->y < 1)
    return (-1);
  star->cur_x = pos->x;
  star->cur_y = pos->y;
  if (pos->x < 0 || pos->y < 0 || pos->x >= size->x || pos->y >= size->y)
    return (-1);
  star->end_x = end->x;
  star->end_y = end->y;
  if (end->x < 0 || end->y < 0 || end->x >= size->x || end->y >= size->y)
    return (-1);
  star->depla = NULL;
  return (0);
}
