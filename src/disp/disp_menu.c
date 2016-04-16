/*
** disp_menu.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/disp/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr 16 06:31:23 2016 Victor Sousa
** Last update Sat Apr 16 07:05:32 2016 Victor Sousa
*/

#include		"main.h"

t_bunny_response	check_menu_button(t_prog *prog,
					  t_bunny_position *m_pos)
{
  t_hitbox		quit_pos;
  t_hitbox		cont_pos;

  quit_pos = create_hitbox(360, 525, 300, 79);
  cont_pos = create_hitbox(362, 380, 300, 85);
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

void			disp_menu(t_prog *prog)
{
  place_image(create_hitbox(prog->blit_pos.x, prog->blit_pos.y,
      			    prog->menu_bg->width, prog->menu_bg->height),
      	      create_hitbox(prog->menu_bg_pos.x, prog->menu_bg_pos.y,
      			    prog->menu_bg->width - 150,
      			    prog->menu_bg->height - 100),
      	      prog->menu_bg, prog->pix);
  place_image(create_hitbox(0, 0, prog->menu_text->width,
			    prog->menu_text->height),
	      create_hitbox(0, 0, prog->menu_text->width,
			    prog->menu_text->height),
	      prog->menu_text, prog->pix);
  if (prog->menu_dir == 0)
    {
      prog->menu_bg_pos.x++;
      if (prog->menu_bg_pos.x >= 150)
	prog->menu_dir = 1;
    }
  else
    {
      prog->menu_bg_pos.x--;
      if (prog->menu_bg_pos.x <= 0)
	prog->menu_dir = 0;
    }
}
