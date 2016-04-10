/*
** start_fight.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/event/fight/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Sun Apr 10 23:41:37 2016 Ethan Kerdelhue
** Last update Mon Apr 11 01:28:03 2016 Ethan Kerdelhue
*/

#include		 "main.h"

int			prepare_fight(t_prog *prog, t_npc *npc, t_fight *fight)
{
  t_fight		*fight;

  if ((fight = xmalloc(sizeof(t_fight), &prog->ptr_list)) == NULL)
    return (-1);
  fight->player = prog->player;
  fight->npc = npc;
  fight->nb_round = 0;
  fight->round_state = 0;
  return (0);
}

int			loop_fight(t_fight *fight)
{
  if (fight->round_state == 1)
    {

    }
  if (fight->round_state == 2)
    {

    }
  return (0);
}

int			start_fight(t_prog *prog, t_npc *npc)
{
  t_bunny_position	pos;
  t_bunny_position	player;

  if (prog->need_init-fight == 1)
    {
      pos.x = 0;
      pos.y = 0;
      player.x = 0 + prog->player->sprite->width / 2;
      player.y = WIN_HEIGHT / 2 - (prog->player->sprite->height / 2);
      put_image(prog->fight_img, prog->pix, &pos);
      put_image(prog->player->sprite, prog->pix, &player);
      prog->need_init-fight = 0;
    }
  loop_fight(fight);
  return (0);
}
