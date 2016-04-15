/*
** disp_fight.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/disp/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Fri Apr 15 22:51:56 2016 Gaëtan Léandre
** Last update Sat Apr 16 00:19:54 2016 Gaëtan Léandre
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

void			event_on_player(t_prog *prog, int chose)
{
  t_bunny_position	pos;
  t_text		*text;

  pos = pos_alea(40, 500, 40, 500);
  if (chose == 0)
    text = create_text(pos, "CRITIC", 0, RED);
  else if (chose == 1)
    text = create_text(pos, "DODGE", 0, RED);
  else if (chose == 2)
    text = create_text(pos, "BLOCKED", 0, RED);
  else if (chose == 3)
    text = create_text(pos, "RESIST", 0, RED);
  add_text(prog, text);
}

int			damage_on_npc(t_prog *prog, int dmg)
{
  t_bunny_position	pos;
  t_text		*text;

  pos = pos_alea(40, 500, 40, 500);
  text = create_text(pos, NULL, -dmg, RED);
  add_text(prog, text);
  return (dmg);
}

int			damage_on_player(t_prog *prog, int dmg)
{
  t_bunny_position	pos;
  t_text		*text;

  pos = pos_alea(40, 500, 40, 500);
  text = create_text(pos, NULL, -dmg, RED);
  add_text(prog, text);
  return (dmg);
}

void			add_disp_txt(t_prog *prog, char *str)
{
  if ((prog->disp_str = malloc(my_strlen(str) + 1)) == NULL)
    return;
  prog->disp_str = my_strcpy(prog->disp_str, str);
  prog->disp_delay = 25;
}
