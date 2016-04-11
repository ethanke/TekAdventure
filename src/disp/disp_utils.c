/*
** disp_utils.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/disp/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Mon Apr 11 00:51:48 2016 Gaëtan Léandre
** Last update Mon Apr 11 06:36:39 2016 Gaëtan Léandre
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
