/*
** npc.h for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/inc/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed Apr  6 23:24:51 2016 Ethan Kerdelhue
** Last update Thu Apr  7 00:37:11 2016 Philippe Lefevre
*/

#ifndef 		NPC_H_
# define 		NPC_H_
# include 		"main.h"

typedef struct		s_trade
{
  unsigned int		item_player_id;
  unsigned int		item_npc_id;
  int			amount;
}

typedef struct 		s_npc
{
  char 			*name;
  char			*text;
  t_trade		*trade;
  t_hitbox		*sprite_hitbox;
  t_texture		*sprite;
} 			t_npc;

#endif			/* !NPC_H_ */
