/*
** prog.h for  in /Users/leandr_g/Documents/Shared folder/TekAdventure/inc/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Thu Apr  7 00:11:13 2016 Gaëtan Léandre
** Last update Thu Apr  7 00:19:54 2016 Gaëtan Léandre
*/

#ifndef			PROG_H_
# define		PROG_H_

typedef	struct		s_prog
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_ptr_list		*ptr_list;
  t_bunny_position	blit_pos;
}			t_prog;

#endif			/* !PROG_H_ */
