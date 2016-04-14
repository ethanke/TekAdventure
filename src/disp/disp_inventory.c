/*
** disp_inventory.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Thu Apr  7 02:58:27 2016 victor sousa
** Last update Thu Apr 14 04:57:35 2016 Gaëtan Léandre
*/

#include		"main.h"

static void		disp_big_inventory(t_prog *prog, t_bunny_position *pos)
{
  place_image(create_hitbox(pos->x, pos->y, prog->player->inv_open_sprite->width / 4,
			    prog->player->inv_open_sprite->height / 4),
	      create_hitbox(0, 0, prog->player->inv_open_sprite->width,
			    prog->player->inv_open_sprite->height),
	      prog->player->inv_open_sprite, prog->pix);
}

static void		disp_top_big_inventory(t_prog *prog,
					       t_bunny_position *_pos,
					       t_bunny_position *m_pos)
{
  float			x;
  int			i;
  t_bunny_position	pos;
  t_font		font;

  font.font_img = prog->font->font_img;
  font.font_size = 11;
  font.font_color.full = 0xFF050505;
  pos.x = _pos->x + 10;
  pos.y = _pos->y + 12;
  x = pos.x;
  i = 11;
  while (++i < 48)
    {
      if (i % 12 == 0 && i != 12)
	{
	  x = _pos->x + 10;
	  pos.y += 35;
	}
      pos.x = (int)x;
      if (prog->player->inventory[i].id != -1)
	{
	  place_image(create_hitbox(pos.x, pos.y, 36, 30),
		      *prog->player->inventory[i].object->texture_hitbox,
		      prog->player->inventory[i].object->texture, prog->pix);
	  teknbr(prog->player->inventory[i].amount, &pos, prog->pix, &font);
	  if (m_pos->x >= pos.x && m_pos->x <= pos.x + 40.45 &&
	      m_pos->y >= pos.y && m_pos->y <= pos.y + 36)
	    disp_item_info(prog, &prog->player->inventory[i], &pos);
	}
      x += 40.45;
    }
}

static void		disp_floating_item(t_prog *prog,
					   t_bunny_position *click_pos)
{
  t_bunny_position	pos;

  if (prog->player->inv_selected != -1)
    {
      pos.x = click_pos->x - 20;
      pos.y = click_pos->y - 18;
      if (prog->state == STATE_NPC && prog->player->inv_selected == -2)
	{
	  place_image(create_hitbox(pos.x, pos.y, 36, 30),
		      *prog->current_click.npc->trade->needed->object->texture_hitbox,
		      prog->current_click.npc->trade->needed->object->texture,
		      prog->pix);
	}
      else if (prog->state == STATE_NPC && prog->player->inv_selected == -3)
	{
	  place_image(create_hitbox(pos.x, pos.y, 36, 30),
		      *prog->current_click.npc->trade->given->object->texture_hitbox,
		      prog->current_click.npc->trade->given->object->texture,
		      prog->pix);
	}
      else
	{
	  place_image(create_hitbox(pos.x, pos.y, 36, 30),
		      *prog->player->inventory
		      [(int)prog->player->inv_selected].object->texture_hitbox,
		      prog->player->inventory
		      [(int)prog->player->inv_selected].object->texture,
		      prog->pix);
	}
    }
}

void			disp_inventory(t_prog *prog)
{
  t_bunny_position	*click_pos;
  t_bunny_position	pos;

  click_pos = (t_bunny_position *)bunny_get_mouse_position();
  if (prog->player->inventory_open == 1)
    {
      pos.x = WIN_WIDTH / 2 - (prog->player->inv_open_sprite->width / 2) / 4;
      pos.y = WIN_HEIGHT / 2 - (prog->player->inv_open_sprite->height / 2) / 4;
      disp_big_inventory(prog, &pos);
      disp_top_big_inventory(prog, &pos, click_pos);
      disp_selected_full_inv_item(prog);
    }
  disp_hotbar(prog, click_pos);
  disp_floating_item(prog, click_pos);
}
