/*
** disp_game_over.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/disp/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Sat Apr 16 03:53:37 2016 Ethan Kerdelhue
** Last update Sat Apr 16 04:36:41 2016 Ethan Kerdelhue
*/

#include 		"main.h"

void			disp_game_over(t_prog *prog)
{
  t_bunny_position	pos;
  t_hitbox		quit_pos;
  t_hitbox		continu_pos;
  t_hitbox		quit_fetch;
  t_hitbox		continu_fetch;

  pos.x = 0;
  pos.y = 0;
  put_image(prog->game_over_img, prog->pix, &pos);
  quit_pos.x = 20;
  quit_pos.y = WIN_HEIGHT - prog->over_quit->height + 10;
  quit_pos.width = prog->over_quit->width;
  quit_pos.height = prog->over_quit->height;
  continu_pos.x = 20;
  continu_pos.y = WIN_HEIGHT - prog->over_continue->height + 10;
  continu_pos.width = prog->over_continue->width;
  continu_pos.height = prog->over_continue->height;
  quit_fetch.x = 0;
  quit_fetch.y = 0;
  quit_fetch.width = prog->over_quit->width;
  quit_fetch.height = prog->over_quit->height;
  continu_fetch.x = 0;
  continu_fetch.y = 0;
  continu_fetch.width = prog->over_continue->width;
  continu_fetch.height = prog->over_continue->height;
  place_image(continu_pos, continu_fetch, prog->over_continue, prog->pix);
  place_image(quit_pos, quit_fetch, prog->over_quit, prog->pix);
}
