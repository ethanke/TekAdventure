/*
** my_draw_square.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/utils/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Apr 11 07:13:11 2016 Victor Sousa
** Last update Mon Apr 11 07:15:39 2016 Victor Sousa
*/

#include		"main.h"

void			my_draw_square(t_bunny_pixelarray *pix,
				       t_bunny_position *pos,
				       t_bunny_position *size,
				       unsigned int color)
{
  t_color		col;
  t_bunny_position	pix_pos;

  col.full = color;
  pix_pos.x = pos->x - 1;
  while (++pix_pos.x < pos->x + size->x)
    {
      pix_pos.y = pos->y - 1;
      while (++pix_pos.y < pos->y + size->y)
	tektranspa(pix, &pix_pos, &col);
    }
}
