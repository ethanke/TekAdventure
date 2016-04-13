/*
** fill_image.c for image in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/image/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Wed Apr 13 14:55:59 2016 Gaëtan Léandre
** Last update Wed Apr 13 14:59:18 2016 Gaëtan Léandre
*/

#include 		"main.h"

void			fill_pix(t_bunny_pixelarray *pix, unsigned int col)
{
  t_bunny_position	tmp;
  t_color		color;

  tmp.y = 0;
  color.full = col;
  while (tmp.y < pix->clipable.clip_height)
    {
      tmp.x = 0;
      while (tmp.x < pix->clipable.clip_width)
	{
	  tekpixel(pix, &tmp, &color);
	  tmp.x++;
	}
      tmp.y++;
    }
}

void			fill_image(t_hitbox box, t_bunny_pixelarray *pix,
				   unsigned int col)
{
  t_bunny_position	tmp;
  t_color		color;

  tmp.y = box.y;
  color.full = col;
  while (tmp.y < box.y + box.height)
    {
      tmp.x = box.x;
      while (tmp.x < box.x + box.width)
	{
	  tekpixel(pix, &tmp, &color);
	  tmp.x++;
	}
      tmp.y++;
    }
}
