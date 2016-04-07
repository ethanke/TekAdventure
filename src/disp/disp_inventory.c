/*
** disp_inventory.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp
** 
** Made by victor sousa
** Login   <sousa_v@epitech.net>
** 
** Started on  Thu Apr  7 02:58:27 2016 victor sousa
** Last update Thu Apr  7 05:10:52 2016 victor sousa
*/

#include		"main.h"

void			disp_inventory(t_prog *prog)
{
  t_bunny_position	pos;

  if (prog->player.inventory_open == 1)
    {
      pos.x = WIN_WIDTH / 2 - prog->player.inv_open_sprite->width / 2;
      pos.y = WIN_HEIGHT / 2 - prog->player.inv_open_sprite->height / 2;
      put_image(prog->player.inv_open_sprite, prog->pix, &pos);
    }
}
