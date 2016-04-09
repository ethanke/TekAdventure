/*
** player.h for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/inc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed Apr  6 23:07:19 2016 Philippe Lefevre
** Last update Sat Apr  9 14:53:07 2016 Victor Sousa
*/

#ifndef			PLAYER_H_
# define		PLAYER_H_

# define		SIZE_INVENTORY	48

typedef struct		s_item
{
  int			id;
  int			amount;
  t_object		*object;
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
  char			inv_selected;
  t_texture		*inv_open_sprite;
  t_texture		*hotbar_sprite;
}			t_player;

void			my_swap_item(t_item *a, t_item *b);

#endif			/* !PLAYER_H_ */
