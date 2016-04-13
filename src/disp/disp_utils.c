/*
** disp_utils.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/disp/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Mon Apr 11 00:51:48 2016 Gaëtan Léandre
** Last update Wed Apr 13 04:37:56 2016 Gaëtan Léandre
*/

#include		"main.h"

t_grille		get_grille_param(t_hitbox *place,
					 t_scene *scene)
{
  t_grille		grille;

  grille.size_x = place->width - 20;
  grille.case_x = (place->width - 20) / (scene->size.x);
  grille.case_y = (place->height) / (scene->size.y + 1);
  grille.start_y = place->y;
  grille.grille_x = scene->size.x;
  grille.grille_y = scene->size.y + 1;
  scene->coef = (float)(EQUART *  2) / (float)scene->size.y;
  grille.coef = scene->coef;
  grille.height = place->height;
  return (grille);
}

int			get_pos_y(int y, t_grille *grille)
{
  int			i;
  int			pos;

  i = 0;
  pos = 0;
  while (i <= (y + 1))
    {
      pos += grille->case_y
	  * (grille->size_x - (int)(grille->coef
			       * (float)(grille->grille_y - i - 1)))
      / (grille->size_x);
      i++;
    }
  return (pos);
}

int			calc_x_h(t_grille *grille, t_bunny_position *pos,
				 float percent, int x)
{
  int			result;

  result = (int)(((float)(grille->coef *
		  (float)(grille->grille_y  - pos->y - 1))) * percent) + x;
  return (result);
}

float			calc_case_x(t_grille *grille, int pos_y,
				    t_bunny_position *palier, int y)
{
  float			y_pos;
  float			coef;
  float			case_x;

  y_pos = (float)((float)(pos_y - palier->x) / (float)(palier->y - palier->x))
      + (float)y;
  coef = (float)((float)grille->size_x - (float)(grille->coef
		 * (float)(grille->grille_y - y_pos + 1)))
  / (float)(grille->size_x);
  case_x = ((float)grille->case_x * coef);
  return (case_x);
}

t_grille		get_grille_with_place(t_scene *scene)
{
  t_hitbox		place;
  t_grille		grille;

  place = create_hitbox(0, WIN_HEIGHT - scene->height,
		      WIN_WIDTH, scene->height - 206 / 4);
  grille = get_grille_param(&place, scene);
  return (grille);
}
