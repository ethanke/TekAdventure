/*
** draw_fight.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/event/fight/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed Apr 13 19:36:12 2016 Ethan Kerdelhue
** Last update Wed Apr 13 22:24:23 2016 Ethan Kerdelhue
*/

#include		"main.h"

void			draw_fight(t_prog *prog)
{
  t_bunny_position	player_pos;
  t_bunny_position	attack;
  t_bunny_position	defend;
  t_bunny_position	magic;
  t_bunny_position	skip;
  t_bunny_position	bar1;
  t_bunny_position	bar2;
  t_bunny_position	bar3;

  sleep(4);
  player_pos.x = prog->fight->player->sprite->width / 2;
  player_pos.y = WIN_HEIGHT / 2 - (prog->fight->player->sprite->height / 2);
  skip.x = WIN_WIDTH / 2 + 1 * prog->attack_button->width;
  skip.y = 600;
  magic.x = WIN_WIDTH / 2 + 0 * prog->defend_button->width;
  magic.y = 600;
  defend.x = WIN_WIDTH / 2 - 1 * prog->defend_button->width;
  defend.y = 600;
  attack.x = WIN_WIDTH / 2 - 2 * prog->skip_button->width;
  attack.y = 600;
  bar1.x = 20;
  bar1.y = 100;
  bar2.x =  WIN_WIDTH - 20 - prog->npc_bar->bar_sprite->width;
  bar2.y = 100;
  bar3.x = (WIN_WIDTH / 2) - (prog->life_bar->bar_sprite->width / 2);
  bar3.y = WIN_HEIGHT / 2;
  put_image(prog->fight_img, prog->pix, &prog->blit_pos);
  put_image(prog->player->sprite, prog->pix, &player_pos);
  put_image(prog->attack_button, prog->pix, &attack);
  put_image(prog->defend_button, prog->pix, &defend);
  put_image(prog->magic_button, prog->pix, &magic);
  put_image(prog->skip_button, prog->pix, &skip);
  put_image(prog->life_bar->bar_sprite, prog->pix, &bar1);
  put_image(prog->npc_bar->bar_sprite, prog->pix, &bar2);
  update_bar_player(prog->life_bar, prog);
  update_bar_npc(prog->npc_bar, prog);
  update_bar_action(prog->action_bar, prog);
  put_image(prog->npc_bar->bar_sprite, prog->pix, &bar3);
}
