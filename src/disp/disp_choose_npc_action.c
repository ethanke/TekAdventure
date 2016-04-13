/*
** disp_choose_npc_action.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/disp/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Wed Apr 13 05:44:24 2016 Victor Sousa
** Last update Wed Apr 13 10:51:11 2016 Victor Sousa
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
	break;
      i++;
    }
  if (i == -1 )
    return (-1);
  if (m_pos->x >= WIN_WIDTH / 2 + prog->npc_choose->width / 2 -
      prog->npc_choose->width / 3 / 2 - 17 &&
      m_pos->x <= WIN_WIDTH / 2 + prog->npc_choose->width / 2 -
      prog->npc_choose->width / 3 / 2 &&
      m_pos->y >= WIN_HEIGHT / 2 - prog->npc_choose->height / 2 +
      prog->npc_choose->height / 3  / 2 &&
      m_pos->y <= WIN_HEIGHT / 2 - prog->npc_choose->height / 2 +
      prog->npc_choose->height / 3  / 2 + 17)
    return (-2);
  return (i);
}

void			disp_choose_npc_action(t_prog *prog)
{
  t_bunny_position	pos;
  int			hoover;
  t_font		font;

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
  hoover = get_highlight(prog, &pos);
  if (hoover == -2 && bunny_get_mouse_button()[BMB_LEFT] == 1)
    prog->state = STATE_GAME;
  pos.x += 20;
  pos.y += 20;
  font.font_img = prog->font->font_img;
  font.font_color.full = 0xFF4F4F4F;
  font.font_size = 14;
  if (hoover == 0)
    font.font_size += 1;
  tektext("Trade with nnc", &pos, prog->pix, &font);
  if (hoover == 0)
    font.font_size -= 1;
  pos.y += 40;
  if (hoover == 1)
    font.font_size += 1;
  tektext("Fight with npc", &pos, prog->pix, &font);
  if (hoover == 1)
    font.font_size -= 1;
  pos.y += 40;
  if (hoover == 2)
    font.font_size += 1;
  tektext("Interract", &pos, prog->pix, &font);
}
