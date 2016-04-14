/*
** teknbr.c for image in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/image/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Thu Apr 14 05:07:56 2016 Gaëtan Léandre
** Last update Thu Apr 14 05:08:25 2016 Gaëtan Léandre
*/

#include	"main.h"

void		teknbr(int nb, const t_bunny_position *pos,
		       t_bunny_pixelarray *out,
		       t_font *font)
{
  int			i;
  int			j;
  t_bunny_position	pix;
  int			len;

  i = nb;
  len = 0;
  while (i > 0)
    {
      i /= 10;
      len++;
    }
  pix.y = pos->y;
  i = 0;
  j = 0;
  while (len-- > 1)
    {
      pix.x = pos->x + j * font->font_size + (font->font_size / 4) * j;
      tekchar(out, font, &pix, nb / 10  + '0');
      nb %= 10;
      j++;
    }
  pix.x = pos->x + j * font->font_size + (font->font_size / 4) * j;
  tekchar(out, font, &pix, nb  + '0');
}
