/*
** disp_p_a.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/disp/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Sun Apr 17 08:50:14 2016 Ethan Kerdelhue
** Last update Sun Apr 17 09:15:18 2016 Ethan Kerdelhue
*/

#include			"main.h"


t_bunny_response	check_p_a_button(t_prog *prog,
					       t_bunny_position *m_pos)
{
  t_hitbox		cont_pos;

  cont_pos = create_hitbox(770, 574,
                              239,
                              40);
  if (m_pos->x >= cont_pos.x && m_pos->x <= cont_pos.x + cont_pos.width &&
      m_pos->y >= cont_pos.y && m_pos->y <= cont_pos.y + cont_pos.height)
    {
      prog->state = STATE_MENU;
      disp_menu(prog);
    }
  return (GO_ON);
}

void			disp_p_a(t_prog *prog)
{
  t_bunny_position	pos;

  pos.x = 0;
  pos.y = 0;
  put_image(prog->p_a_img, prog->pix, &pos);
}
