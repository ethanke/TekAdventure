/*
** image.h for image in /Users/leandr_g/Documents/Shared folder/TekAdventure/inc/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Wed Apr  6 23:41:06 2016 Gaëtan Léandre
** Last update Thu Apr  7 00:06:56 2016 Gaëtan Léandre
*/

#ifndef			_IMAGE_H_
# define		_IMAGE_H_

#include		"main.h"

typedef struct		s_texture
{
  int			width;
  int			height;
  t_color		**color;
}			t_texture;

typedef struct		s_hitbox
{
  int			x;
  int			y;
  int			width;
  int			height;
}			t_hitbox;

t_texture      		*load_image(const char *file, t_ptr_list *ptr_list);
t_texture		*pix_array_to_texture(t_bunny_pixelarray *pix,
					      t_ptr_list *pr);
void			put_image(t_texture *bmp,
				  t_prog *prog,
				  t_bunny_position *pos);
void			place_image(t_hitbox *pos,
				    t_hitbox *fetch,
				    t_texture *tex,
				    t_prog *prog);
t_hitbox		create_hitbox(int x, int y, int width, int height);
t_hitbox		*create_hitbox_ptr(t_bunny_position pos, int width,
					   int height, t_ptr_list *ptr_list);
void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color *color);
void			tektranspa(t_bunny_pixelarray *pix,
				   t_bunny_position *pos,
				   t_color *color);

#endif			/*_IMAGE_H_*/
