/*
** get_grille_pos.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/event/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Tue Apr 12 03:41:45 2016 Gaëtan Léandre
** Last update Wed Apr 13 03:02:19 2016 Gaëtan Léandre
*/

#include	 	"main.h"

float			get_y(t_scene *scene, t_grille *grille, int pos)
{
  t_bunny_position	palier;
  float			y;

  y = 0;
  palier.x = grille->start_y + 10 + get_pos_y(y, grille);
  palier.y =  grille->start_y + 10 + get_pos_y(++y, grille);
  if (pos < palier.x)
    return (-1);
  while (pos > palier.y && y < scene->size.y)
    {
      palier.x = palier.y;
      palier.y = grille->start_y + 10 + get_pos_y(++y, grille);
    }
  if (pos > palier.y)
    return (-1);
  y += (float)((float)(pos - palier.x) / (float)(palier.y - palier.x));
  return (y - 1);
}

int			get_x(float percent, t_grille *grille, int pos,
			      float y_pos)
{
  float			case_x;
  float			coef;
  int			start_x;

  coef = (float)((float)grille->size_x - (float)(grille->coef
		 * (float)(grille->grille_y - y_pos)))
  / (float)(grille->size_x);
  case_x = ((float)grille->case_x * coef);
  start_x = ((float)((float)WIN_WIDTH - 30 -
	      (float)case_x * ((float)grille->grille_x)) * percent + 10);
  pos -= start_x;
  if (pos < 0)
    return (-1);
  pos = (int)((float)pos / case_x);
  if (pos > grille->grille_x - 1)
    return (-1);
  return (pos);
}

t_bunny_position	get_pos(t_scene *scene, float percent,
				t_bunny_position *mouse_pos)
{
  t_grille		grille;
  t_bunny_position	pos;
  float			y;

  grille = get_grille_with_place(scene);
  y = get_y(scene, &grille, mouse_pos->y);
  pos.y = (int)y;
  pos.x = get_x(percent, &grille, mouse_pos->x, y);
  return (pos);
}
