/*
** fight.h for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/inc/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed Apr 13 06:17:45 2016 Ethan Kerdelhue
** Last update Thu Apr 14 03:09:50 2016 Ethan Kerdelhue
*/

#ifndef			FIGHT_H_
# define		FIGHT_H_

# include		"main.h"

# define		ATTACK		0
# define		DEFEND 		1
# define		MAGIC		2
# define 		SKIP		3

typedef	struct		s_bar
{
  t_texture		*bar_sprite;
  int			*value_cur;
  int			value_default;
}			t_bar;

typedef struct		s_fight
{
  int			nb_round;
  char			round_state;
  int			player_action;
  t_player		*player;
  t_npc			*npc;
  t_font		font;
  int			animate;
  int			last_action;
  t_bar			*bar_action;
}			t_fight;

void			draw_fight(t_prog *prog);
void			percent_bar(t_hitbox size, t_bar *bar, t_prog *prog,
				    unsigned int color);
void			update_bar_npc(t_bar *bar, t_prog *prog);
void			update_bar_player(t_bar *bar, t_prog *prog);
void			update_bar_action(t_bar *bar, t_prog *prog);
int			catch_button(t_prog *prog);

#endif
