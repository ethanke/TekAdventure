/*
** tektext.c for  in /home/vicostudio/rendu/lapin/skilltest/flip_part_2020
**
** Made by sousa_v
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Feb 23 10:27:21 2016 sousa_v
** Last update Fri Apr 15 00:48:51 2016 Gaëtan Léandre
*/

#include	"main.h"

char		get_x_char(char *str, char c)
{
  int		i;

  i = -1;
  while (str[++i])
    {
      if (str[i] == c)
	return (i % 16);
    }
  return (-1);
}

char		get_y_char(char *str, char c)
{
  int		i;

  i = -1;
  while (str[++i])
    {
      if (str[i] == c)
	return (i / 16);
    }
  return (-1);
}

static void		place_char(t_hitbox *pos,
				   t_hitbox *fetch,
				   t_font *font,
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
	  if (font->font_img->color[(int)(((float)i / (float)pos->height) *
				     (float)(fetch->height) + (float)fetch->y)]
	      [(int)(((float)j / (float)pos->width)
		* (float)(fetch->width) + (float)fetch->x)].argb[ALPHA_CMP] != 0)
	    tektranspa(pix, &tmp, &font->font_color);
	  tmp.x++;
	  j++;
	}
      tmp.y++;
      i++;
    }
}

void		tekchar(t_bunny_pixelarray *out,
			t_font *font,
			const t_bunny_position *pos,
			const char c)
{
  t_bunny_position	let_pos;
  t_hitbox		print_pos;
  t_hitbox		fetch_pos;
  char			*str;

  str = malloc(98);
  str = my_strcpy(str, " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOP");
  str = my_strcat(str, "QRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~");
  let_pos.x = get_x_char(str, c) * 25;
  let_pos.y = get_y_char(str, c) * 25;
  print_pos = create_hitbox(pos->x, pos->y, font->font_size, font->font_size);
  fetch_pos = create_hitbox(let_pos.x, let_pos.y, 25, 25);
  place_char(&print_pos, &fetch_pos, font, out);
  free(str);
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
