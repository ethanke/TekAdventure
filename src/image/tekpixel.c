/*
** tekpixel.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/utils/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Wed Apr  6 23:31:37 2016 Gaëtan Léandre
** Last update Thu Apr  7 00:18:55 2016 Gaëtan Léandre
*/

#include 		"main.h"

void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color *color)
{
  if (pos->x < pix->clipable.clip_width &&
      pos->y < pix->clipable.clip_height &&
      pos->x >= 0 && pos->y >= 0)
    {
      ((t_color *)pix->pixels)[pos->x + pix->clipable.clip_width * pos->y]
	= *color;
    }
}

void			tektranspa(t_bunny_pixelarray *pix,
				   t_bunny_position *pos,
				   t_color *color)
{
  t_color	prev;

  if (pos->x < pix->clipable.clip_width &&
      pos->y < pix->clipable.clip_height &&
      pos->x >= 0 && pos->y >= 0)
    {
      prev =
	((t_color *)pix->pixels)[pos->x + pix->clipable.clip_width * pos->y];

      prev.argb[0] = (float)prev.argb[0] * ((255 -
					     (float)color->argb[3]) / 255)
	+ ((float)color->argb[0] * ((float)color->argb[3] / 255));
      prev.argb[1] = (float)prev.argb[1] * ((255 -
					     (float)color->argb[3]) / 255)
	+ ((float)color->argb[1] * ((float)color->argb[3] / 255));
      prev.argb[2] = (float)prev.argb[2] * ((255 -
					     (float)color->argb[3]) / 255)
	+ ((float)color->argb[2] * ((float)color->argb[3] / 255));
      prev.argb[3] = 255;
      ((t_color *)pix->pixels)[pos->x + pix->clipable.clip_width * pos->y]
	= prev;
    }
}
