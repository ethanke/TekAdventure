/*
** disp_hotbar.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/disp/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr  9 08:30:39 2016 Victor Sousa
** Last update Sat Apr  9 15:34:52 2016 Victor Sousa
*/

#include		"main.h"

static void		disp_hotbar_sprite(t_prog *prog, t_bunny_position *pos)
{
  place_image(create_hitbox_ptr(*pos, prog->player->hotbar_sprite->width / 4,
				prog->player->hotbar_sprite->height / 4,
				prog->ptr_list),
	      create_hitbox_ptr(prog->blit_pos,
				prog->player->hotbar_sprite->width,
				prog->player->hotbar_sprite->height,
				prog->ptr_list),
	      prog->player->hotbar_sprite, prog->pix);
}

void			disp_hotbar(t_prog *prog)
{
  float			x;
  t_bunny_position	pos;
  int			i;

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
	place_image(create_hitbox_ptr(pos, 36, 30, prog->ptr_list),
		    prog->player->inventory[i].object->texture_hitbox,
		    prog->player->inventory[i].object->texture, prog->pix);
      x += 40.45;
    }
  disp_selected_hotbar_inv_item(prog);
}
