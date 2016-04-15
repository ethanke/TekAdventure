/*
** disp_choose_npc_action.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/disp/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Wed Apr 13 05:44:24 2016 Victor Sousa
** Last update Fri Apr 15 22:14:02 2016 Victor Sousa
*/

#include		"main.h"

int	 		get_highlight(t_prog *prog,
				      t_bunny_position *pos)
{
  t_bunny_position	*m_pos;
  int			size;

  size = (prog->npc_choose->height - prog->npc_choose->height / 3) / 3;
  m_pos = (t_bunny_position *)bunny_get_mouse_position();
  if (m_pos->x >= WIN_WIDTH / 2 + prog->npc_choose->width / 2
      - prog->npc_choose->width / 3 / 2 - 25 &&
      m_pos->x <= WIN_WIDTH / 2 + prog->npc_choose->width / 2
      - prog->npc_choose->width / 3 / 2 &&
      m_pos->y >= WIN_HEIGHT / 2 - prog->npc_choose->height / 2
      + prog->npc_choose->height / 3  / 2 &&
      m_pos->y <= WIN_HEIGHT / 2 - prog->npc_choose->height / 2
      + prog->npc_choose->height / 3  / 2 + 25)
    return (-2);
  else if (m_pos->x >= pos->x && m_pos->x <= pos->x + prog->npc_choose->width -
	   prog->npc_choose->width / 3 && m_pos->y >= pos->y
	   && m_pos->y <= pos->y + 3 * size)
    return ((m_pos->y - pos->y) / size);
  return (-1);
}

static void 		disp_choice1(t_prog *prog, t_font font,
				     t_bunny_position pos, int hoover)
{
  if (hoover == 0)
    font.font_size += 3;
  tektext("Trade with npc", &pos, prog->pix, &font);
  if (hoover == 0)
    font.font_size -= 3;
}

static void 		disp_choice2(t_prog *prog, t_font font,
				     t_bunny_position pos, int hoover)
{
  if (hoover == 1)
    font.font_size += 3;
  tektext("Fight with npc", &pos, prog->pix, &font);
  if (hoover == 1)
    font.font_size -= 3;
}

static void 		disp_choice3(t_prog *prog, t_font font,
				     t_bunny_position pos, int hoover)
{
  if (hoover == 2)
    font.font_size += 3;
  tektext("Interract", &pos, prog->pix, &font);
  if (hoover == 1)
    font.font_size -= 3;
}

void			disp_choose_npc_action(t_prog *prog)
{
  t_bunny_position	pos;
  int			hoover;
  t_font		font;

  pos.x = WIN_WIDTH / 2 - prog->npc_choose->width / 2
      + prog->npc_choose->width / 3 / 2;
  pos.y = WIN_HEIGHT / 2 - prog->npc_choose->height / 2
      + prog->npc_choose->height / 3  / 2;
  place_image(create_hitbox(pos.x, pos.y, prog->npc_choose->width -
			    prog->npc_choose->width / 3,
			    prog->npc_choose->height -
			    prog->npc_choose->height / 3),
	      create_hitbox(0, 0, prog->npc_choose->width,
			    prog->npc_choose->height),
	      prog->npc_choose, prog->pix);
  font.font_img = prog->font->font_img;
  font.font_size = (font.font_color.full = 0xFF4F4F4F) * 0 + 10;
  hoover = get_highlight(prog, &pos);
  pos.x += 20;
  pos.y += 20;
  disp_choice1(prog, font, pos, hoover);
  pos.y += 40;
  disp_choice2(prog, font, pos, hoover);
  pos.y += 40;
  disp_choice3(prog, font, pos, hoover);
}
