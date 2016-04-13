/*
** fight.h for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/inc/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed Apr 13 06:17:45 2016 Ethan Kerdelhue
** Last update Wed Apr 13 10:19:54 2016 Ethan Kerdelhue
*/

#ifndef			FIGHT_H_
# define		FIGHT_H_

# include		"main.h"

typedef	struct		s_bar
{
  t_texture		*bar_sprite;
  int			*value_cur;
  int			value_default;
  void			(*ptr)(int val, int cur);
}			t_bar;

typedef struct		s_fight
{
  int			nb_round;
  char			round_state;
  t_player		*player;
  t_npc			*npc;
}			t_fight;

#endif
