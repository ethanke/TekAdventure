/*
** disp_fight.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/disp/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Fri Apr 15 22:51:56 2016 Gaëtan Léandre
** Last update Fri Apr 15 23:27:12 2016 Gaëtan Léandre
*/

#include		"main.h"

void			event_on_npc(t_prog *prog)
{
  t_bunny_position	pos;
  t_text		*text;

  pos = pos_alea(40, 500, 40, 500);
  text = create_text(pos, "CRITIC", 0, RED);
  add_text(prog, text);
}
