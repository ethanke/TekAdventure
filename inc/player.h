/*
** player.h for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/inc/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Wed Apr 13 03:51:52 2016 Gaëtan Léandre
** Last update Sun Apr 17 03:00:03 2016 Philippe Lefevre
*/

#ifndef			PLAYER_H_
# define		PLAYER_H_

# define		SIZE_INVENTORY	48
# ifndef		PLAYER_DEFAULT_TEXTURE_H_
#  define		PLAYER_DEFAULT_TEXTURE_H_
#  define		T_INVENTORY	 "ressources/sprites/inventory_full.png"
#  define		T_HOTBAR	"ressources/sprites/hotbar.png"
#  define		T_PLAYER	"ressources/sprites/player.png"

# endif			/* !PLAYER_DEFAULT_TEXTURE_H_ */

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
  float			x_vec;
  float			y_vec;
  int			life;
  char			*name;
  int			damage;
  int			magic_damage;
  t_anim		left;
  t_anim		right;
  t_anim		up;
  t_anim		down;
  t_anim		stop;
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
