/*
** start_fight.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/event/fight/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Sun Apr 10 23:41:37 2016 Ethan Kerdelhue
** Last update Sun Apr 10 19:49:04 2016 Kerdelhue Ethan
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

int			loop_fight(t_prog *prog)
{
  t_bunny_position	player_pos;

  player_pos.x = 0 + prog->player->sprite->width / 2;
  player_pos.y = WIN_HEIGHT / 2 - (prog->player->sprite->height / 2);
  put_image(prog->fight_img, prog->pix, &prog->blit_pos);
  put_image(prog->player->sprite, prog->pix, &player_pos);
  if (prog->fight->round_state == 1)
    {

    }
  if (prog->fight->round_state == 2)
    {

    }
  return (0);
}

int			start_fight(t_prog *prog, t_npc *npc)
{
  if (prog->need_init_fight == 1)
    {
      if (prepare_fight(prog, npc) == -1)
	return (-1);
      prog->need_init_fight = 0;
    }
  loop_fight(prog);
  return (0);
}
