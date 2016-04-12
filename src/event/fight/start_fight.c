/*
** start_fight.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/event/fight/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Sun Apr 10 23:41:37 2016 Ethan Kerdelhue
** Last update Mon Apr 11 04:58:38 2016 Ethan Kerdelhue
*/

#include		"main.h"

int 			my_rand(int min, int max)
{
  return ((rand()%(max-min))+min);
}

int			prepare_fight(t_prog *prog, t_npc *npc)
{
  if ((prog->fight = xmalloc(sizeof(t_fight), &prog->ptr_list)) == NULL)
    return (-1);
  prog->fight->player = prog->player;
  prog->fight->npc = npc;
  prog->fight->npc->life = 100;
  prog->fight->nb_round = 1;
  prog->fight->round_state = 1;
  prog->fight->player->damage_min = 20;
  prog->fight->player->damage_max = 35;
  prog->fight->npc->damage_min = 20;
  prog->fight->npc->damage_max = 35;
  return (0);
}

int			loop_fight(t_prog *prog)
{
  t_bunny_position	player_pos;

  player_pos.x = prog->player->sprite->width / 2;
  player_pos.y = WIN_HEIGHT / 2 - (prog->player->sprite->height / 2);
  put_image(prog->fight_img, prog->pix, &prog->blit_pos);
  put_image(prog->player->sprite, prog->pix, &player_pos);
  printf("Round -> %d\n", prog->fight->nb_round);
  if (prog->fight->round_state == 1)
    {
      prog->fight->npc->life -= my_rand(prog->fight->npc->damage_min,
					prog->fight->npc->damage_max);
      printf("Npc life : %d\n", prog->fight->npc->life);
      prog->fight->nb_round += 1;
      prog->fight->round_state = 2;
    }
  if (prog->fight->round_state == 2)
    {
      prog->fight->player->life -= my_rand(prog->fight->player->damage_min,
					prog->fight->player->damage_max);
      printf("Player life : %d\n", prog->fight->player->life);
      prog->fight->round_state = 1;
    }
  if (prog->player->life <= 0)
    {
      puts("npc win\n");
      prog->fight_state = 0;
    }
  if  (prog->fight->npc->life <= 0)
    {
      puts("player win\n");
      prog->fight_state = 0;
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
