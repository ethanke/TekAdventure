/*
** tektext.c for  in /home/vicostudio/rendu/lapin/skilltest/flip_part_2020
**
** Made by sousa_v
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Feb 23 10:27:21 2016 sousa_v
** Last update Mon Apr 11 01:51:57 2016 Victor Sousa
*/

#include	"main.h"

void		tekchar(t_bunny_pixelarray *out,
			t_font *font,
			const t_bunny_position *pos,
			const char c)
{
  t_bunny_position	pix_pos;
  t_bunny_position	let_pos;

  let_pos.y = -1;
  while (++let_pos.y <= font->font_img->height)
    {
      pix_pos.x = pos->x;
      let_pos.x = 5 * c - 1;
      while (++let_pos.x < 5 * c + 5)
	{
	  pix_pos.y = pos->y + let_pos.y;
	  tekpixel(out, &pix_pos, &font->font_img->color[let_pos.x][let_pos.y]);
	  pix_pos.x++;
	}
    }
}

void		tektext(const char *str,
			const t_bunny_position *pos,
			t_bunny_pixelarray *out,
			t_font *font)
{
  int			i;
  int			j;
  t_bunny_position	pix;

  pix.y = pos->y;
  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[i] == '\n')
	{
	  pix.y += 8;
	  j = 0;
	  i++;
	}
      else
	{
	  pix.x = pos->x + j * 5;
	  tekchar(out, font, &pix, str[i++]);
	  j++;
	}
    }
}
