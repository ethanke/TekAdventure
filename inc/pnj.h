/*
** pnj.h for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/inc/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed Apr  6 23:24:51 2016 Ethan Kerdelhue
** Last update Wed Apr  6 23:51:19 2016 Ethan Kerdelhue
*/

#ifndef 		PNJ_H_
# define 		PNJ_H_

# include 		"main.h"

typedef struct		s_trade
{
  unsigned int		item_player_id;
  unsigned int		item_pnj_id;
  int			amount;
}

typedef struct 		s_pnj
{
  char 			*name;
  char			*text;
  t_trade		*trade;
  t_hitbox		*sprite_hitbox;
  t_texture		*sprite;
} 			t_pnj;

#endif
