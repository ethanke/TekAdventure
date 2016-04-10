/*
** start_fight.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/event/fight/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Sun Apr 10 23:41:37 2016 Ethan Kerdelhue
** Last update Mon Apr 11 00:20:51 2016 Ethan Kerdelhue
*/

#include		 "main.h"

int			prepare_fight(t_prog *prog, t_npc *npc, t_fight *fight)
{
  t_bunny_position	pos;

  pos.x = 0;
  pos.y = 0;
  if ((fight = xmalloc(sizeof(t_fight), &prog->ptr_list)) == NULL)
    return (-1);
  fight->player = prog->player;
  fight->npc = npc;
  fight->nb_round = 0;
  fight->round_state = 0;
  put_image(prog->fight_img, prog->pix, &pos);
  return (0);
}

int			loop_fight(t_fight *fight)
{
  if (fight->round_state == 0)
    {

    }
  if (fight->round_state == 1)
    {

    }
  return (0);
}

int			start_fight(t_prog *prog, t_npc *npc)
{
  t_fight		*fight;

  fight = NULL;
  puts("lol");
  if (prepare_fight(prog, npc, fight) == -1)
    return (-1);
  loop_fight(fight);
  return (0);
}
