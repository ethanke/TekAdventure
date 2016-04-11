/*
** start_fight.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/event/fight/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Sun Apr 10 23:41:37 2016 Ethan Kerdelhue
** Last update Mon Apr 11 03:40:06 2016 Victor Sousa
*/

#include		 "main.h"

int			prepare_fight(t_prog *prog, t_npc *npc)
{
  if ((prog->fight = xmalloc(sizeof(t_fight), &prog->ptr_list)) == NULL)
    return (-1);
  prog->fight->player = prog->player;
  prog->fight->npc = npc;
  prog->fight->nb_round = 0;
  prog->fight->round_state = 0;
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

  if (prog->need_init_fight == 1)
    {
      if (prepare_fight(prog, npc) == -1)
	return (-1);
      pos.x = 0;
      pos.y = 0;
      player.x = 0 + prog->player->sprite->width / 2;
      player.y = WIN_HEIGHT / 2 - (prog->player->sprite->height / 2);
      put_image(prog->fight_img, prog->pix, &pos);
      put_image(prog->player->sprite, prog->pix, &player);
      prog->need_init_fight = 0;
    }
  loop_fight(prog->fight);
  return (0);
}
