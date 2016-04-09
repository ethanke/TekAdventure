/*
** player.h for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/inc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed Apr  6 23:07:19 2016 Philippe Lefevre
** Last update Sat Apr  9 09:07:44 2016 Victor Sousa
*/

#ifndef			PLAYER_H_
# define		PLAYER_H_

# define		SIZE_INVENTORY	36

typedef struct		s_item
{
  int			id;
  int			amount;
  t_object		*object;
  char			selected;
}			t_item;

typedef struct		s_player
{
  int			life;
  unsigned int		token;
  char			*name;
  t_texture		*sprite;
  t_hitbox		*sprite_hitbox;
  t_item		*inventory;
  char			inventory_open;
  t_texture		*inv_open_sprite;
  t_texture		*hotbar_sprite;
}			t_player;

#endif			/* !PLAYER_H_ */
