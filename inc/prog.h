/*
** prog.h for  in /Users/leandr_g/Documents/Shared folder/TekAdventure/inc/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Thu Apr  7 00:11:13 2016 Gaëtan Léandre
** Last update Tue Apr 12 21:11:51 2016 Victor Sousa
*/

#ifndef			PROG_H_
# define		PROG_H_

# include		"utils.h"
# include		"image.h"
# include		"scene.h"
# include		"player.h"

#ifndef			PROG_STATE_
# define		PROG_STATE_
# define		STATE_MENU		0
# define		STATE_GAME		1
# define		STATE_NPC		2
# define		STATE_FIGHT		3
#endif			/*!PROG_STATE_*/

typedef	struct		s_prog
{
  t_bunny_window	*win;
  int			pix_id;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*pix0;
  t_bunny_pixelarray	*pix1;
  t_bunny_pixelarray	*pix2;
  t_font		*font;
  t_ptr_list		*ptr_list;
  t_bunny_position	blit_pos;
  int			state;

  struct s_fight	*fight;
  char			need_init_fight;

  t_texture		*lion_img;
  t_texture		*fight_img;
  t_texture		*exchange_sprite;

  t_player		*player;
  t_scene		*scene;
}			t_prog;

#endif			/* !PROG_H_ */
