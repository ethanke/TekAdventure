/*
** draw_fight.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/event/fight/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed Apr 13 19:36:12 2016 Ethan Kerdelhue
** Last update Sat Apr 16 08:15:20 2016 Ethan Kerdelhue
*/

#include		"main.h"


void			set_attack(t_prog *prog, t_bunny_position *attack)
{
  attack->x = WIN_WIDTH / 2 - 2 * prog->skip_button->width;
  attack->y = 600;
}

void			draw_fight(t_prog *prog)
{
  t_hitbox		size;
  t_hitbox		size2;
  t_hitbox		size3;
  t_bunny_position	player_pos;
  t_bunny_position	attack;
  t_bunny_position	defend;
  t_bunny_position	magic;
  t_bunny_position	skip;


  player_pos.x = prog->fight->player->sprite->width / 2;
  player_pos.y = WIN_HEIGHT / 2 - (prog->fight->player->sprite->height / 2);
  skip.x = WIN_WIDTH / 2 + 1 * prog->attack_button->width;
  skip.y = 600;
  magic.x = WIN_WIDTH / 2 + 0 * prog->defend_button->width;
  magic.y = 600;
  defend.x = WIN_WIDTH / 2 - 1 * prog->defend_button->width;
  defend.y = 600;
  set_attack(prog, &attack);
  put_image(prog->fight_img, prog->pix, &prog->blit_pos);
  put_image(prog->player->sprite, prog->pix, &player_pos);
  put_image(prog->attack_button, prog->pix, &attack);
  put_image(prog->defend_button, prog->pix, &defend);
  put_image(prog->magic_button, prog->pix, &magic);
  put_image(prog->skip_button, prog->pix, &skip);
  prog->fight->player_action_size = 100;
  size.x = (WIN_WIDTH / 2) - prog->fight->bar_action->bar_sprite->width / 2;
  size.y = WIN_HEIGHT - prog->fight->bar_action->bar_sprite->height + 5;
  size.width = prog->fight->bar_action->bar_sprite->width;
  size.height = prog->fight->bar_action->bar_sprite->height;
  size2.x = WIN_WIDTH - 20 - prog->fight->bar_npc->bar_sprite->width;
  size2.y = 100;
  size2.width = size.width;
  size2.height = size.height;
  size3.x = 20;
  size3.y = 100;
  size3.width = size.width;
  size3.height = size.height;
  prog->fight->bar_action->value_cur = prog->fight->player_action;
  prog->fight->bar_player->value_cur = prog->fight->player->life;
  prog->fight->bar_npc->value_cur = prog->fight->npc->life;
  percent_bar(size, prog->fight->bar_action, prog, YELLOW);
  percent_bar(size2, prog->fight->bar_npc, prog, RED);
  percent_bar(size3, prog->fight->bar_player, prog, RED);
}
