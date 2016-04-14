/*
** catch_button.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/event/fight/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Thu Apr 14 02:48:28 2016 Victor Sousa
** Last update Thu Apr 14 04:35:31 2016 Victor Sousa
*/

#include		"main.h"

int			catch_button(t_prog *prog)
{
  t_bunny_position	*m_pos;
  t_bunny_position	center;
  int			i;

  m_pos = (t_bunny_position *)bunny_get_mouse_position();
  center.y = 600 + prog->magic_button->height / 2;
  i = -2;
  while (i < 2)
    {
      center.x = WIN_WIDTH / 2 + (i * prog->magic_button->width) + prog->magic_button->width / 2;
      if ((m_pos->x - center.x) * (m_pos->x - center.x) +
	  (m_pos->y - center.y) * (m_pos->y - center.y) <=
	  (prog->magic_button->width / 2) * (prog->magic_button->width / 2))
	prog->fight->last_action = i + 2;
      i++;
    }
  return (-1);
}
