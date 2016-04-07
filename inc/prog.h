/*
** prog.h for  in /Users/leandr_g/Documents/Shared folder/TekAdventure/inc/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Thu Apr  7 00:11:13 2016 Gaëtan Léandre
** Last update Thu Apr  7 05:24:21 2016 victor sousa
*/

#ifndef			PROG_H_
# define		PROG_H_

typedef	struct		s_prog
{
  t_bunny_window	*win;
  int			pix_id;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*pix0;
  t_bunny_pixelarray	*pix1;
  t_bunny_pixelarray	*pix2;
  t_ptr_list		*ptr_list;
  t_bunny_position	blit_pos;

  t_texture		*lion_img;
  
  t_player		player;
  int			inv[36][2];
}			t_prog;

#endif			/* !PROG_H_ */
