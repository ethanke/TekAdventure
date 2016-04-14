/*
** player.h for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/inc/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Wed Apr 13 03:51:52 2016 Gaëtan Léandre
** Last update Fri Apr 15 01:22:38 2016 Ethan Kerdelhue
*/

#ifndef			PLAYER_H_
# define		PLAYER_H_

# define		SIZE_INVENTORY	48

typedef struct		s_caract
{
  int			stamina;
  int			strength;
  int			critical;
  int			intellect;
  int			armor;
  int			agility;
}			t_caract;

typedef struct		s_item
{
  int			id;
  int			amount;
  t_object		*object;
}			t_item;

typedef struct		s_depla
{
  int			x;
  int			y;
  struct s_depla	*next;
}			t_depla;

typedef struct		s_move
{
  int			select_move;
  t_depla		*depla;
}			t_move;

typedef struct		s_player
{
  float			x;
  float			y;
  int			life;
  int			token;
  char			*name;
  int			damage;
  int			magic_damage;
  int			sprite_id;
  t_texture		*sprite;
  t_caract		*caract;
  t_hitbox		*sprite_hitbox;
  t_item		*inventory;
  char			inventory_open;
  char			inv_selected;
  char			fight_defense;
  t_texture		*inv_open_sprite;
  t_texture		*hotbar_sprite;
  t_move		move;
  int			item_selected;
}			t_player;

void			my_swap_item(t_item *a, t_item *b);

#endif			/* !PLAYER_H_ */
