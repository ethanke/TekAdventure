/*
** draw_fight.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/event/fight/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed Apr 13 19:36:12 2016 Ethan Kerdelhue
** Last update Sun Apr 17 06:37:24 2016 Gaëtan Léandre
*/

#include		"main.h"

void			draw_fight(t_prog *prog)
{
  t_hitbox		size;
  t_hitbox		size2;
  t_hitbox		size3;
  t_bunny_position	attack;
  t_bunny_position	defend;
  t_bunny_position	magic;
  t_bunny_position	skip;

  skip.x = WIN_WIDTH / 2 + 1 * prog->attack_button->width;
  skip.y = 600;
  set_val(prog, &magic, &defend, &attack);
  put_image(prog->fight_img, prog->pix, &prog->blit_pos);
  disp_npc(prog, prog->fight->npc);
  disp_player(prog, prog->player);
  put_image(prog->attack_button, prog->pix, &attack);
  put_image(prog->defend_button, prog->pix, &defend);
  put_image(prog->magic_button, prog->pix, &magic);
  put_image(prog->skip_button, prog->pix, &skip);
  prog->fight->player_action_size = 100;
  set_size(prog, &size, &size2, &size3);
  percent_bar(size, prog->fight->bar_action, prog, YELLOW);
  percent_bar(size2, prog->fight->bar_npc, prog, RED);
  percent_bar(size3, prog->fight->bar_player, prog, RED);
}
