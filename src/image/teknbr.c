/*
** teknbr.c for image in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/image/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Thu Apr 14 05:07:56 2016 Gaëtan Léandre
** Last update Sat Apr 16 00:06:59 2016 Gaëtan Léandre
*/

#include	"main.h"

static int	inv_nbr(int nb, const t_bunny_position *pos,
		       t_bunny_pixelarray *out, t_font *font)
{
  t_bunny_position	pix;

  pix.y = pos->y;
  pix.x = pos->x;
  tekchar(out, font, &pix, '-');
  nb *= -1;
  return (nb);
}

void		teknbr(int nb, const t_bunny_position *pos,
		       t_bunny_pixelarray *out, t_font *font)
{
  int			i;
  int			j;
  t_bunny_position	pix;
  int			len;

  len = 0;
  pix.y = pos->y;
  j = (nb < 0) ? 1 : 0;
  nb = (nb < 0) ? inv_nbr(nb, pos, out, font) : nb;
  i = nb;
  while (i > 0)
    {
      i /= 10;
      len++;
    }
  i = 0;
  while (len-- > 1)
    {
      pix.x = pos->x + j * font->font_size + (font->font_size / 4) * j;
      tekchar(out, font, &pix, nb / pow(10, len)  + '0');
      nb %= (int)pow(10, len);
      j++;
    }
  pix.x = pos->x + j * font->font_size + (font->font_size / 4) * j;
  tekchar(out, font, &pix, nb  + '0');
}
