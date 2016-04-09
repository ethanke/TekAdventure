/*
** disp_hotbar.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/disp/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr  9 08:30:39 2016 Victor Sousa
** Last update Sat Apr  9 08:32:28 2016 Victor Sousa
*/

#include		"main.h"

void			disp_hotbar(t_prog *prog)
{
  t_bunny_position	pos;
  int			i;

  pos.x = WIN_WIDTH / 2 - (prog->player->hotbar_sprite->width / 2) / 4;
  pos.y = WIN_HEIGHT - prog->player->hotbar_sprite->height / 4;
  place_image(create_hitbox_ptr(pos, prog->player->hotbar_sprite->width / 4,
				prog->player->hotbar_sprite->height / 4,
				prog->ptr_list),
	      create_hitbox_ptr(prog->blit_pos,
				prog->player->hotbar_sprite->width,
				prog->player->hotbar_sprite->height,
				prog->ptr_list),
	      prog->player->hotbar_sprite, prog->pix);
  pos.x += 10;
  pos.y += 10;
  i = -1;
  while (++i < 9)
    {
      if (prog->player->inventory[i].id != -1)
	place_image(create_hitbox_ptr(pos, 36, 30, prog->ptr_list),
		    prog->player->inventory[i].object->texture_hitbox,
		    prog->player->inventory[i].object->texture, prog->pix);
      pos.x += 41;
    }
}
