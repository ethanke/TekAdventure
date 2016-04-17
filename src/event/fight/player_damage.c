/*
** player_damage.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/event/fight/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Sat Apr 16 08:00:22 2016 Ethan Kerdelhue
** Last update Sun Apr 17 07:55:00 2016 Ethan Kerdelhue
*/

#include		"main.h"

void			npc_damage_more(t_prog *prog,
					t_player *player,
					int *damage)
{
  if (((rand() % (100 - 0)) + 0) <= 5)
    {
      bunny_sound_play(&prog->music->fight_critic->sound);
      *damage = *damage * 1.5;
      event_on_player(prog, 0);
    }
  if (((rand() % (100 - 0)) + 0) <= player->caract->agility / 3)
    {
      bunny_sound_play(&prog->music->fight_dodge->sound);
      *damage = 0;
      event_on_player(prog, 1);
    }
}

int 			npc_damage(t_npc *npc, t_player *player, t_prog *prog)
{
  int			damage;
  int			max;
  int			min;

  max = npc->damage * 1200;
  min = npc->damage * 800;
  damage = ((rand() % (max - min)) + min);
  if (player->fight_defense == 1)
    {
      bunny_sound_play(&prog->music->fight_resist->sound);
      npc_damage_more(prog, player, &damage);
      player->fight_defense = 0;
      if (((rand() % (100 - 0)) + 0) <= player->caract->armor / 3)
	{
	  prog->fight->bonus_action += 20;
	  event_on_player(prog, 2);
	  damage = 0;
	}
      else
	{
	  damage = (damage / 1000) - player->caract->armor / 5;
	  event_on_player(prog, 3);
	  return (damage_on_player(prog, damage));
	}
    }
  return (damage_on_player(prog, damage / 1000));
}

int 			player_damage_magic(t_player *player,
					    t_fight *fight,
					    t_prog *prog)
{
  t_bunny_position	pos;
  int			damage;
  int			max;
  int			min;

  if (fight->player_action >= ATTACK_ENERGY)
    {
      min = player->magic_damage * 1200;
      max = player->magic_damage * 800;
      damage = ((rand() % (max - min )) + min);
      bunny_sound_play(&prog->music->fight_magic->sound);
      if (((rand() % (100 - 0)) + 0) <= player->caract->critical)
	{
	  damage = damage * 1.5;
	  event_on_npc(prog);
	}
      pos.x = WIN_WIDTH / 2;
      pos.y = WIN_HEIGHT / 2;
      pos = pos;
      fight->player_action -= MAGIC_ENERGY;
      return (damage_on_npc(prog, damage / 1000));
    }
  return (0);
}

int 			player_damage(t_player *player,
				      t_fight *fight,
				      t_prog *prog)
{
  int			damage;
  int			max;
  int			min;

  if (fight->player_action >= ATTACK_ENERGY)
    {
      bunny_sound_play(&prog->music->fight_sword->sound);
      min = player->damage * 1200;
      max = player->damage * 800;
      damage = ((rand() % (max - min )) + min);
      if (((rand() % (100 - 0)) + 0) <= player->caract->critical)
	{
	  bunny_sound_play(&prog->music->fight_critic->sound);
	  damage = damage * 1.5;
	  event_on_npc(prog);
	}
      fight->player_action -= ATTACK_ENERGY;
      return (damage_on_npc(prog, damage / 1000));
    }
  return (0);
}
