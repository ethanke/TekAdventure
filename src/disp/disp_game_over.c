/*
** disp_game_over.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/disp/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Sat Apr 16 03:53:37 2016 Ethan Kerdelhue
** Last update Sat Apr 16 05:20:45 2016 Ethan Kerdelhue
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
  quit_pos = create_hitbox(20, WIN_HEIGHT - (prog->over_quit->height + 10),
			   prog->over_quit->width,
			   prog->over_quit->height);
  quit_fetch = create_hitbox(0, 0, prog->over_quit->width,
			   prog->over_quit->height);
  continu_pos = create_hitbox((WIN_WIDTH - 20) - (prog->over_continue->width),
			      WIN_HEIGHT - (prog->over_continue->height + 10),
			      prog->over_continue->width,
			      prog->over_continue->height);
  continu_fetch = create_hitbox(0, 0, prog->over_continue->width,
			      prog->over_continue->height);
  place_image(continu_pos, continu_fetch, prog->over_continue, prog->pix);
  place_image(quit_pos, quit_fetch, prog->over_quit, prog->pix);
 /* if (in_hitbox(&quit_pos, ) == 1)
    {
      printf("mdr on quitte");
    }
  if (in_hitbox(&continu_pos, ) == 1)
    {
      prog->player->life = 100;
      prog->state = STATE_GAME;
    }
  */
}
