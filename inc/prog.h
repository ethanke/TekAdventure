/*
** prog.h for  in /Users/leandr_g/Documents/Shared folder/TekAdventure/inc/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Thu Apr  7 00:11:13 2016 Gaëtan Léandre
** Last update Sat Apr 16 04:04:01 2016 Ethan Kerdelhue
*/

#ifndef			PROG_H_
# define		PROG_H_

#ifndef			PROG_STATE_
# define		PROG_STATE_
# define		STATE_MENU		0
# define		STATE_GAME		1
# define		STATE_NPC		2
# define		STATE_FIGHT		3
# define		STATE_NPC_CHOOSE	4
# define		STATE_DECOR_CHOOSE	5
# define		STATE_GAME_OVER		6
#endif			/*!PROG_STATE_*/

typedef struct		s_text
{
  int			turn;
  int 			nbr;
  char			*msg;
  t_font		font;
  t_bunny_position	pos;
  struct s_text		*next;
  struct s_text		*prev;
}			t_text;

typedef struct		s_map_click
{
  int			x;
  int			y;
  t_bunny_position	pos;
  t_bunny_position	*mouse_pos;
  t_npc			*npc;
  t_decors		*decors;
}			t_map_click;

typedef	struct		s_prog
{
  t_bunny_window	*win;
  int			pix_id;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*pix0;
  t_bunny_pixelarray	*pix1;
  t_bunny_pixelarray	*pix2;
  t_font		*font;
  t_text		*text;
  t_ptr_list		*ptr_list;
  t_bunny_position	blit_pos;
  int			state;
  float			percent;
  int			disp_delay;
  char			*disp_str;
  struct s_fight	*fight;

  char			need_init_fight;

  t_texture		*fight_img;
  t_texture		*npc_choose;
  t_texture		*exchange_sprite;
  t_texture		*equip_sprite;
  t_texture		*attack_button;
  t_texture		*defend_button;
  t_texture		*magic_button;
  t_texture		*skip_button;
  t_texture		*attack_button_hover;
  t_texture		*defend_button_hover;
  t_texture		*magic_button_hover;
  t_texture		*skip_button_hover;
  t_texture		*game_over_img;
  t_texture		*over_quit;
  t_texture		*over_continue;

  t_map_click		current_click;

  t_player		*player;
  t_scene		*scene;
}			t_prog;

#endif			/* !PROG_H_ */
