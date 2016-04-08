/*
** init_tab.c for astar in /Users/leandr_g/Documents/Shared folder/TekAdventure/astar/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Fri Apr  8 06:25:15 2016 Gaëtan Léandre
** Last update Fri Apr  8 06:25:47 2016 Gaëtan Léandre
*/

#include	"astar.h"

int		init_tab(t_star *star)
{
  int		i;
  int		j;

  if ((star->ind_list = malloc(sizeof(char *) * star->x)) == NULL
      || (star->open_list = malloc(sizeof(char *) * star->x)) == NULL)
    return (-1);
  i = 0;
  while (i < star->x)
    {
      if ((star->ind_list[i] = malloc(sizeof(char *) * star->y)) == NULL
	  || (star->open_list[i] = malloc(sizeof(char *) * star->y)) == NULL)
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

void	 	case_is_free(char **obj, t_star *star)
{
  int		i;
  int		j;

  i = 0;
  while (i < star->x)
    {
      j = 0;
      while (j < star->y)
	{
	  if (obj[i][j] != 0)
	    {
	      star->ind_list[i][j] = -1;
	      star->open_list[i][j] = -1;
	    }
	  j++;
	}
      i++;
    }
}
