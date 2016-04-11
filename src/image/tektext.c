/*
** tektext.c for  in /home/vicostudio/rendu/lapin/skilltest/flip_part_2020
**
** Made by sousa_v
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Feb 23 10:27:21 2016 sousa_v
** Last update Mon Apr 11 03:42:27 2016 Victor Sousa
*/

#include	"main.h"

void		tekchar(t_bunny_pixelarray *out,
			t_font *font,
			const t_bunny_position *pos,
			const char c)
{
  t_bunny_position	let_pos;
  t_hitbox		print_pos;
  t_hitbox		fetch_pos;

  let_pos.x = c * 5;
  let_pos.y = 0;
  print_pos = create_hitbox(pos->x, pos->y, font->font_size, font->font_size);
  fetch_pos = create_hitbox(let_pos.x, let_pos.y, 5, font->font_img->height);
  place_image(&print_pos, &fetch_pos, font->font_img, out);
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
	  pix.y += font->font_size + font->font_size / 4;
	  j = 0;
	  i++;
	}
      else
	{
	  pix.x = pos->x + j * font->font_size + (font->font_size / 4) * j;
	  tekchar(out, font, &pix, str[i++]);
	  j++;
	}
    }
}
