/*
** disp_inventory.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp
** 
** Made by victor sousa
** Login   <sousa_v@epitech.net>
** 
** Started on  Thu Apr  7 02:58:27 2016 victor sousa
** Last update Thu Apr  7 05:37:56 2016 victor sousa
*/

#include		"main.h"

void			disp_inventory(t_prog *prog)
{
  t_bunny_position	pos;

  if (prog->player.inventory_open == 1)
    {
      pos.x = WIN_WIDTH / 2 - (prog->player.inv_open_sprite->width / 2) / 4;
      pos.y = WIN_HEIGHT / 2 - (prog->player.inv_open_sprite->height / 2) / 4;
      place_image(create_hitbox_ptr(pos, prog->player.inv_open_sprite->width / 4,
				    prog->player.inv_open_sprite->height / 4, prog->ptr_list),
		  create_hitbox_ptr(prog->blit_pos, prog->player.inv_open_sprite->width,
				    prog->player.inv_open_sprite->height, prog->ptr_list),
		  prog->player.inv_open_sprite, prog->pix);
    }
}
