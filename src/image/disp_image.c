/*
** disp_image.c for image in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/image/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Wed Apr  6 23:28:22 2016 Gaëtan Léandre
** Last update Thu Apr  7 01:15:46 2016 Gaëtan Léandre
*/

#include 		"main.h"

void			put_image(t_texture *bmp,
				  t_bunny_pixelarray *pix,
				  t_bunny_position *pos)
{
  t_bunny_position	tmp;
  int			i;
  int			j;

  i = 0;
  tmp.y = pos->y;
  while (i < bmp->height)
    {
      j = 0;
      tmp.x = pos->x;
      while (j < bmp->width)
	{
	  tektranspa(pix, &tmp, &bmp->color[i][j]);
	  tmp.x++;
	  j++;
	}
      tmp.y++;
      i++;
    }
}

void			place_image(t_hitbox *pos,
				    t_hitbox *fetch,
				    t_texture *tex,
				    t_bunny_pixelarray *pix)
{
  t_bunny_position	tmp;
  int			i;
  int			j;

  if (fetch == NULL || pos == NULL)
    return;
  i = 0;
  tmp.y = pos->y;
  while (i < pos->height)
    {
      j = 0;
      tmp.x = pos->x;
      while (j < pos->width)
	{
	  tektranspa(pix, &tmp,
		     &tex->color[(int)(((float)i / (float)pos->height) *
				  (float)(fetch->height) + (float)fetch->y)]
		     [(int)(((float)j / (float)pos->width)
		       * (float)(fetch->width))]);
	  tmp.x++;
	  j++;
	}
      tmp.y++;
      i++;
    }
}
