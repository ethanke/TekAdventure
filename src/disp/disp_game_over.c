/*
** disp_game_over.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/disp/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Sat Apr 16 03:53:37 2016 Ethan Kerdelhue
** Last update Sat Apr 16 05:29:53 2016 Victor Sousa
*/

#include 		"main.h"

t_bunny_response	check_game_over_button(t_prog *prog,
					       t_bunny_position *m_pos)
{
  t_hitbox		quit_pos;
  t_hitbox		cont_pos;

  quit_pos = create_hitbox(20, WIN_HEIGHT - (prog->over_quit->height + 10),
			   prog->over_quit->width,
			   prog->over_quit->height);
  cont_pos = create_hitbox((WIN_WIDTH - 20) - (prog->over_continue->width),
			   WIN_HEIGHT - (prog->over_continue->height + 10),
			   prog->over_continue->width,
			   prog->over_continue->height);
  if (m_pos->x >= quit_pos.x && m_pos->x <= quit_pos.x + quit_pos.width &&
      m_pos->y >= quit_pos.y && m_pos->y <= quit_pos.y + quit_pos.height)
    return (EXIT_ON_SUCCESS);
  if (m_pos->x >= cont_pos.x && m_pos->x <= cont_pos.x + cont_pos.width &&
      m_pos->y >= cont_pos.y && m_pos->y <= cont_pos.y + cont_pos.height)
    {
      prog->player->life = 100 + prog->player->caract->stamina * 2;
      prog->state = STATE_GAME;
    }
  return (GO_ON);
}

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
}
