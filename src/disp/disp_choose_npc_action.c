/*
** disp_choose_npc_action.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/disp/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Wed Apr 13 05:44:24 2016 Victor Sousa
** Last update Wed Apr 13 09:00:39 2016 Victor Sousa
*/

#include		"main.h"

static int 		get_highlight(t_prog *prog,
				      t_bunny_position *pos)
{
  int			i;
  t_bunny_position	*m_pos;

  i = 0;
  m_pos = (t_bunny_position *)bunny_get_mouse_position();
  while (i < 3)
    {
      if (m_pos->x >= pos->x && m_pos->x <= pos->x + prog->npc_choose->width -
	  prog->npc_choose->width / 3 &&
	  m_pos->y >= pos->y + (i * (prog->npc_choose->height -
				    prog->npc_choose->height / 3) / 3) &&
	  m_pos->y <= pos->y + (i * (prog->npc_choose->height -
				    prog->npc_choose->height / 3) / 3) +
	  (prog->npc_choose->height - prog->npc_choose->height / 3) / 3)
	return (i);
      i++;
    }
  return (-1);
}

void			disp_choose_npc_action(t_prog *prog)
{
  t_bunny_position	pos;
  int			hoover;

  pos.x = WIN_WIDTH / 2 - prog->npc_choose->width / 2 +
      prog->npc_choose->width / 3 / 2;
  pos.y = WIN_HEIGHT / 2 - prog->npc_choose->height / 2 +
      prog->npc_choose->height / 3  / 2;
  place_image(create_hitbox(pos.x, pos.y, prog->npc_choose->width -
			    prog->npc_choose->width / 3,
			    prog->npc_choose->height -
			    prog->npc_choose->height / 3),
	      create_hitbox(0, 0, prog->npc_choose->width,
			    prog->npc_choose->height),
	      prog->npc_choose, prog->pix);
  if ((hoover = get_highlight(prog, &pos)) != -1)
    {
      fill_image(create_hitbox(pos.x, pos.y + (hoover *
					       (prog->npc_choose->height -
						prog->npc_choose->height / 3)
					       / 3),
			       prog->npc_choose->width -
			       prog->npc_choose->width / 3,
			       (prog->npc_choose->height -
				prog->npc_choose->height / 3) / 3 + 1),
		 prog->pix, 0X04050505);
    }
}
