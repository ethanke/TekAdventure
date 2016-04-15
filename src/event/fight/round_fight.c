/*
** round_fight.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/event/fight/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Fri Apr 15 01:35:20 2016 Ethan Kerdelhue
** Last update Fri Apr 15 23:08:57 2016 Gaëtan Léandre
*/

#include		"main.h"

void			player_round(t_prog *prog)
{
  if (prog->fight->last_action != -1)
    {
      if (prog->fight->last_action == ATTACK)
	prog->fight->npc->life -= player_damage(prog->fight->player, prog->fight, prog);
      if (prog->fight->last_action == DEFEND)
	{
	  if (prog->fight->player_action >= DEFEND_ENERGY)
	    {
	      prog->fight->player->fight_defense = 1;
	      prog->fight->player_action -= DEFEND_ENERGY;
	    }
	}
      if (prog->fight->last_action == MAGIC)
	{
	  prog->fight->animate_fireball = 1;
	  prog->fight->npc->life -= player_damage_magic(prog->fight->player, prog->fight, prog);
	}
      if (prog->fight->last_action == SKIP)
	prog->fight->round_state = 2;
      prog->fight->last_action = -1;
    }
}

void			npc_round(t_prog *prog)
{
  prog->fight->player_action = prog->fight->round_energy;
  prog->fight->player->life -= npc_damage(prog->fight->npc, prog->player, prog);
  my_puts("Player life : ", prog->fight->player->life, 1);
  prog->fight->round_state = 1;
}

int			loop_fight(t_prog *prog)
{
  draw_fight(prog);
  if (prog->fight->round_state == 1)
    player_round(prog);
  if (prog->fight->round_state == 2)
    npc_round(prog);
  if (prog->player->life <= 0)
    {
      my_puts("npc win\n", 0, 0);
      prog->state = STATE_GAME;
      prog->need_init_fight = 1;
    }
  if  (prog->fight->npc->life <= 0)
    {
      my_puts("player win\n", 0, 0);
      prog->state = STATE_GAME;
      prog->need_init_fight = 1;
      prog->scene->ground[prog->current_click.x + prog->current_click.y
      * prog->scene->size.x].npc = NULL;
    }
  return (0);
}
