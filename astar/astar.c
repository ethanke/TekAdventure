/*
** astar.c for astar in /Users/leandr_g/Documents/Shared folder/TekAdventure/astar/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** stared on  Fri Apr  8 00:39:34 2016 Gaëtan Léandre
** Last update Fri Apr  8 05:01:19 2016 Gaëtan Léandre
*/

#include	"a_star.h"

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

int		calculDistance(int xA, int xB, int yA, int yB)
{
  int distanceAC;
  int distanceBC;
  int distanceTotale;

  distanceAC = (int)sqrt(pow(xB-xA,2));
  distanceBC = (int)sqrt(pow(yA-yB,2));
  distanceTotale = distanceAC + distanceBC + 1;
  return (distanceTotale);
}

int		calcul_indice(t_star *star, int x, int y)
{
  int		i;
  int		j;
  int		tmp_x;
  int		tmp_y;
  int		indice;

  i = -1;
  indice = 0;
  while (i < 2)
    {
      j = -1;
      while (j < 2)
	{
	  tmp_x = x + i;
	  tmp_y = y + j;
	  if ((TRAVERS == 1 || (j == 0 || i == 0)) && (tmp_x >= 0 && tmp_y >= 0
		  && tmp_x < star->x && tmp_y < star->y)
	      && star->ind_list[tmp_x][tmp_y] > 0
	      && (indice > star->ind_list[tmp_x][tmp_y] || indice == 0))
	    indice = star->ind_list[tmp_x][tmp_y];
	  j++;
	}
      i++;
    }
  return (indice);
}

void		set_coef(t_star *star, int x, int y)
{
  int		coef;

  if (star->open_list[x][y] != -1)
    {
      coef = calculDistance(x, star->end_x, y, star->end_y) * 10;
      coef += calcul_indice(star, x, y) + 1;
      star->open_list[x][y] = coef;
    }
}

void		add_proc(t_star *star, int x, int y)
{
  int		i;
  int		j;
  int		tmp_x;
  int		tmp_y;

  i = -1;
  while (i < 2)
    {
      j = -1;
      while (j < 2)
	{
	  tmp_x = x + i;
	  tmp_y = y + j;
	  if ((TRAVERS == 1 || (j == 0 || i == 0))
	      && (tmp_x >= 0 && tmp_y >= 0
		  && tmp_x < star->x && tmp_y < star->y)
      	      && star->ind_list[tmp_x][tmp_y] >= 0)
	    set_coef(star, tmp_x, tmp_y);
      	  j++;
      	}
      i++;
    }
}

void		caseProche(t_star *star)
{
  int		i;
  int		j;
  int		distance;

  distance = -1;
  i = 0;
  while (i < star->x)
    {
      j = 0;
      while (j < star->y)
	{
	  if ((star->open_list[i][j] <= distance || distance < 0)
	      && star->open_list[i][j] > 0)
	    {
	      distance = star->open_list[i][j];
	      star->cur_x = i;
	      star->cur_y = j;
	    }
	  j++;
	}
      i++;
    }
  star->open_list[star->cur_x][star->cur_y] = -1;
  star->ind_list[star->cur_x][star->cur_y]
  = calcul_indice(star, star->cur_x, star->cur_y) + 1;
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
  int		i;
  int		j;

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
  i = - 1;
  while (++i < 5)
    {
      j = - 1;
      while (++j < 5)
	{
	  if (star.ind_list[i][j] != -1)
	    printf("%d ", star.ind_list[i][j]);
	  else
	    printf("# ");
	}
      printf("\n");
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
