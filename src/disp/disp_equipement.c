/*
** disp_equipement.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/disp/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Fri Apr 15 22:27:24 2016 Victor Sousa
** Last update Fri Apr 15 22:32:25 2016 Victor Sousa
*/

#include		"main.h"

static void		disp_equip_sprite(t_prog *prog, t_font font,
					  t_bunny_position *m_pos,
					  t_bunny_position pos)
{
  int			i;

  i = 47;
  while (++i < 52)
    {
      if (prog->player->inventory[i].id != -1)
	{
	  teknbr(prog->player->inventory[i].amount, &pos, prog->pix, &font);
	  place_image(create_hitbox(pos.x, pos.y, 34, 34),
		      *prog->player->inventory[i].object->texture_hitbox,
		      prog->player->inventory[i].object->texture, prog->pix);
	  if (m_pos->x >= pos.x && m_pos->x <= pos.x + 35 &&
	      m_pos->y >= pos.y && m_pos->y <= pos.y + 35)
	    disp_item_info(prog, &prog->player->inventory[i], &pos);
	}
      pos.y += 36;
    }
}

void			disp_equip(t_prog *prog, t_bunny_position *m_pos)
{
  t_bunny_position	pos;
  t_font		font;

  font.font_img = prog->font->font_img;
  font.font_size = 11;
  font.font_color.full = 0xFF050505;
  pos.x = WIN_WIDTH / 2 - ((prog->player->inv_open_sprite->width / 4) / 2) -
      prog->equip_sprite->width;
  pos.y = WIN_HEIGHT / 2 - prog->equip_sprite->height / 2;
  place_image(create_hitbox(pos.x, pos.y, prog->equip_sprite->width,
			    prog->equip_sprite->height),
	      create_hitbox(0, 0, prog->equip_sprite->width,
			    prog->equip_sprite->height),
	      prog->equip_sprite, prog->pix);
  pos.x += 1;
  pos.y += 2;
  disp_equip_sprite(prog, font, m_pos, pos);
}
