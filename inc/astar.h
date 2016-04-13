/*
** a_star.h for a_star in /Users/leandr_g/Documents/Shared folder/TekAdventure/inc/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Fri Apr  8 04:51:26 2016 Gaëtan Léandre
** Last update Wed Apr 13 14:35:31 2016 Gaëtan Léandre
*/

#ifndef			_A_STAR_H_
# define		_A_STAR_H_

#define			TRAVERS		0

#include 		"stdlib.h"
#include 		"math.h"
#include		"main.h"

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

typedef struct		s_star
{
  int			x;
  int			y;
  int			cur_x;
  int			cur_y;
  int			end_x;
  int			end_y;
  int			**ind_list;
  int			**open_list;
  t_depla		*depla;
}			t_star;

int			add_in_depla(t_star *star, int x, int y);
int			init_tab(t_star *star);
void	 		case_is_free(t_ground *ground, t_star *star);
int			calculDistance(int xA, int xB, int yA, int yB);
int			calcul_indice(t_star *star, int x, int y);
void			set_coef(t_star *star, int x, int y);
void			add_proc(t_star *star, int x, int y);
int			caseProche(t_star *star);
t_ind			take_way(t_star *star, int x, int y);
int			best_way(t_star *star);
t_depla			*free_star(t_star *star);
int			init_star(t_star *star, t_posi *size,
				  t_posi *pos, t_posi *end);
t_depla			*a_star(t_ground *ground, t_posi *size,
				t_posi *pos, t_posi *end);

#endif		/*_A_STAR_H_*/
