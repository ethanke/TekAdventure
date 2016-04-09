/*
** disp_inventory.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Thu Apr  7 02:58:27 2016 victor sousa
** Last update Sat Apr  9 18:36:00 2016 Victor Sousa
*/

#include		"main.h"

static void		disp_big_inventory(t_prog *prog, t_bunny_position *pos)
{
  place_image(create_hitbox_ptr(*pos, prog->player->inv_open_sprite->width / 4,
				prog->player->inv_open_sprite->height / 4,
				prog->ptr_list),
	      create_hitbox_ptr(prog->blit_pos,
				prog->player->inv_open_sprite->width,
				prog->player->inv_open_sprite->height,
				prog->ptr_list),
	      prog->player->inv_open_sprite, prog->pix);
}

static void		disp_top_big_inventory(t_prog *prog,
					       t_bunny_position *_pos)
{
  float			x;
  int			i;
  t_bunny_position	pos;

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
	place_image(create_hitbox_ptr(pos, 36, 30, prog->ptr_list),
		    prog->player->inventory[i].object->texture_hitbox,
		    prog->player->inventory[i].object->texture, prog->pix);
      x += 40.45;
    }
}

void			disp_inventory(t_prog *prog)
{
  t_bunny_position	pos;

  if (prog->player->inventory_open == 1)
    {
      pos.x = WIN_WIDTH / 2 - (prog->player->inv_open_sprite->width / 2) / 4;
      pos.y = WIN_HEIGHT / 2 - (prog->player->inv_open_sprite->height / 2) / 4;
      disp_big_inventory(prog, &pos);
      disp_top_big_inventory(prog, &pos);
      disp_selected_full_inv_item(prog);
    }
  disp_hotbar(prog);
}
