/*
** a_star.h for a_star in /Users/leandr_g/Documents/Shared folder/TekAdventure/inc/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Fri Apr  8 04:51:26 2016 Gaëtan Léandre
** Last update Fri Apr  8 06:15:38 2016 Gaëtan Léandre
*/

#ifndef			_A_STAR_H_
# define		_A_STAR_H_

#define			TRAVERS		0

#include 		"stdlib.h"
#include 		"math.h"

typedef struct		s_ind
{
  int			x;
  int			y;
  int			indice;
}			t_ind;

typedef struct		s_posi
{
  int			x;
  int			y;
}			t_posi;

typedef struct		s_depla
{
  int			x;
  int			y;
  struct s_depla	*next;
}			t_depla;

typedef struct		s_star
{
  int			x;
  int			y;
  int			cur_x;
  int			cur_y;
  int			end_x;
  int			end_y;
  char			**ind_list;
  char			**open_list;
  t_depla		*depla;
}			t_star;

#endif		/*_A_STAR_H_*/
