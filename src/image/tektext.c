/*
** tektext.c for  in /home/vicostudio/rendu/lapin/skilltest/flip_part_2020
**
** Made by sousa_v
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Feb 23 10:27:21 2016 sousa_v
** Last update Mon Apr 11 03:03:28 2016 Victor Sousa
*/

#include	"main.h"

void		tekchar(t_bunny_pixelarray *out,
			t_font *font,
			const t_bunny_position *pos,
			const char c)
{
  t_bunny_position	pix_pos;
  t_bunny_position	let_pos;

  /*let_pos.x =
  place_image(create_hitbox_ptr(pos, ,
				font_size, prog->ptr_list),
	      create_hitbox_ptr(prog->blit_pos, prog->lion_img->width,
				prog->lion_img->height, prog->ptr_list),
	      font->font_img, out);*/
  let_pos.y = -1;
  while (++let_pos.y < font->font_img->height)
    {
      pix_pos.x = pos->x;
      let_pos.x = 5 * c - 1;
      while (++let_pos.x < 5 * c + 5)
	{
	  pix_pos.y = pos->y + let_pos.y;
	  tektranspa(out, &pix_pos, &font->font_img->color[let_pos.y][let_pos.x]);
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
	  pix.y += font->size + font->size / 4;
	  j = 0;
	  i++;
	}
      else
	{
	  pix.x = pos->x + j * font->size;
	  tekchar(out, font, &pix, str[i++]);
	  j++;
	}
    }
}
