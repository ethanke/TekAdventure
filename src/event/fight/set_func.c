/*
** set_func.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/event/fight/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Sat Apr 16 08:26:18 2016 Ethan Kerdelhue
** Last update Sat Apr 16 09:07:46 2016 Ethan Kerdelhue
*/

#include		"main.h"

void			set_val(t_prog *prog,
				t_bunny_position *attack,
				t_bunny_position *defend,
				t_bunny_position *magic)
{
  magic->x = WIN_WIDTH / 2 - 2 * prog->skip_button->width;
  magic->y = 600;
  defend->x = WIN_WIDTH / 2 - 1 * prog->defend_button->width;
  defend->y = 600;
  attack->x = WIN_WIDTH / 2 + 0 * prog->defend_button->width;
  attack->y = 600;
}

void			set_size(t_prog *prog,
				 t_hitbox *size,
				 t_hitbox *size2,
				 t_hitbox *size3)
{
  size->x = (WIN_WIDTH / 2) - prog->fight->bar_action->bar_sprite->width / 2;
  size->y = WIN_HEIGHT - prog->fight->bar_action->bar_sprite->height + 5;
  size->width = prog->fight->bar_action->bar_sprite->width;
  size->height = prog->fight->bar_action->bar_sprite->height;
  size2->x = WIN_WIDTH - 20 - prog->fight->bar_npc->bar_sprite->width;
  size2->y = 100;
  size2->width = size->width;
  size2->height = size->height;
  size3->x = 20;
  size3->y = 100;
  size3->width = size->width;
  size3->height = size->height;
  prog->fight->bar_action->value_cur = prog->fight->player_action;
  prog->fight->bar_player->value_cur = prog->fight->player->life;
  prog->fight->bar_npc->value_cur = prog->fight->npc->life;
}
