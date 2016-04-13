/*
** disp_hotbar.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/disp/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr  9 08:30:39 2016 Victor Sousa
** Last update Wed Apr 13 03:45:23 2016 Victor Sousa
*/

#include		"main.h"

static void		disp_hotbar_sprite(t_prog *prog, t_bunny_position *pos)
{
  place_image(create_hitbox(pos->x, pos->y, prog->player->hotbar_sprite->width / 4,
			    prog->player->hotbar_sprite->height / 4),
	      create_hitbox(0, 0, prog->player->hotbar_sprite->width,
			    prog->player->hotbar_sprite->height),
	      prog->player->hotbar_sprite, prog->pix);
}

void			disp_hotbar(t_prog *prog, t_bunny_position *m_pos)
{
  float			x;
  t_bunny_position	pos;
  int			i;
  t_font		font;

  font.font_img = prog->font->font_img;
  font.font_size = 11;
  font.font_color.full = 0xFF050505;
  pos.x = WIN_WIDTH / 2 - (prog->player->hotbar_sprite->width / 2) / 4;
  pos.y = WIN_HEIGHT - prog->player->hotbar_sprite->height / 4;
  disp_hotbar_sprite(prog, &pos);
  pos.x += 10;
  pos.y += 10;
  x = pos.x;
  i = -1;
  while (++i < 12)
    {
      pos.x = (int)x;
      if (prog->player->inventory[i].id != -1)
	{
	  place_image(create_hitbox(pos.x, pos.y, 36, 30),
		      *prog->player->inventory[i].object->texture_hitbox,
		      prog->player->inventory[i].object->texture, prog->pix);
	  tektext(my_itoa(prog->player->inventory[i].amount), &pos, prog->pix, &font);
	  if (m_pos->x >= pos.x && m_pos->x <= pos.x + 40.45 &&
	      m_pos->y >= pos.y && m_pos->y <= pos.y + 36)
	    disp_item_info(prog, &prog->player->inventory[i], &pos);
	}
      x += 40.45;
    }
  disp_selected_hotbar_inv_item(prog);
}
