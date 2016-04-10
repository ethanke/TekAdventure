/*
** npc.h for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/inc/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed Apr  6 23:24:51 2016 Ethan Kerdelhue
** Last update Sun Apr 10 23:43:58 2016 Ethan Kerdelhue
*/

#ifndef 		NPC_H_
# define 		NPC_H_

# include 		"main.h"

typedef struct		s_trade
{
  unsigned int		item_player_id;
  unsigned int		item_npc_id;
  t_object		*item_player;
  t_object		*item_npc;
  int			amount_player;
  int			amount_npc;
}			t_trade;

typedef struct 		s_npc
{
  int			npc_id;
  char 			*name;
  char			*text;
  t_trade		*trade;
  int			sprite_id;
  t_hitbox		*texture_hitbox;
  t_texture		*texture;
  int			damage_min;
  int			damage_max;
  struct s_npc 		*next;
  struct s_npc		*prev;
} 			t_npc;

#endif			/* !NPC_H_ */
