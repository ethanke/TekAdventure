/*
** pnj.h for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/inc/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed Apr  6 23:24:51 2016 Ethan Kerdelhue
** Last update Wed Apr  6 23:33:40 2016 Ethan Kerdelhue
*/

#ifndef PNJ_H_
# define PNJ_H_

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
  unsigned int		id_sprite;
} 			t_pnj;

#endif
