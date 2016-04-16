/*
** disp_case.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/disp/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Sat Apr 16 19:19:56 2016 Ethan Kerdelhue
** Last update Sat Apr 16 19:20:07 2016 Ethan Kerdelhue
*/

#include		"main.h"

void			disp_cases(t_scene *scene, t_bunny_pixelarray *pix,
				   float percent)
{
  t_grille		grille;
  t_bunny_position	pos;
  t_bunny_position	palier;
  t_bunny_position	tmp;
  float			case_x;
  t_color		color;

  tmp.y = (grille = get_grille_with_place(scene)).grille_x * 0;
  palier.x = (pos.y = grille.start_y + 10 - 1);
  palier.y =  grille.start_y + 10 + get_pos_y(tmp.y, &grille);
  while (++pos.y < grille.start_y + grille.height + 2)
    {
      if (pos.y > palier.y)
    norm_triste(&palier, &tmp, &grille);
      case_x = calc_case_x(&grille, pos.y, &palier, tmp.y);
      tmp.x = (pos.x = ((float)((float)WIN_WIDTH - 30 - (float)case_x
		* ((float)grille.grille_x)) * percent + 10)) * 0 - 1;
      while (tmp.y >= 1 && ++(tmp.x) < case_x * (float)((grille.grille_x)))
	{
	  color.full = chose_color(tmp.x / case_x, tmp.y - 1,
				   grille.grille_x, scene->ground);
	  tektranspa(pix, &pos, &color);
	  pos.x++;
	}
    }
}
