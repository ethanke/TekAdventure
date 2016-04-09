/*
** get_click_inventory_pos.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/event/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr  9 11:47:01 2016 Victor Sousa
** Last update Sat Apr  9 13:47:45 2016 Victor Sousa
*/

#include		"main.h"

int			get_click_place_hotbar(t_prog *prog,
				       t_bunny_position *click_pos)
{
  if (click_pos->x >= WIN_WIDTH / 2 -
      (prog->player->hotbar_sprite->width / 2) / 4 + 10 &&
      click_pos->x <= WIN_WIDTH / 2 +
      (prog->player->hotbar_sprite->width / 2) / 4 - 10 &&
      click_pos->y >= WIN_HEIGHT -
      prog->player->hotbar_sprite->height / 4 + 10 &&
      click_pos->y <= WIN_HEIGHT - 10)
    {
      return ((click_pos->x -
	       (WIN_WIDTH / 2 - (prog->player->hotbar_sprite->width / 2)
		/ 4 + 10 )) / 40);
    }
  return (-1);
}

static int		find_y_place_inv(t_prog *prog,
					 t_bunny_position *click_pos)
{
  if (click_pos->x >= WIN_WIDTH / 2 -
      (prog->player->hotbar_sprite->width / 2) / 4 + 10 &&
      click_pos->x <= WIN_WIDTH / 2 +
      (prog->player->hotbar_sprite->width / 2) / 4 - 10 &&
      click_pos->y >= WIN_HEIGHT / 2 -
      (prog->player->inv_open_sprite->height / 2) / 4 + 12 &&
      click_pos->y <= WIN_HEIGHT / 2 +
      (prog->player->inv_open_sprite->height / 2) / 4 - 12)
    {
      return ((click_pos->y -
	       (WIN_HEIGHT / 2 +
               (prog->player->inv_open_sprite->height / 2) / 4 -
		10)) / 35 + 4);
    }
  return (-1);
}

static int		find_x_place_inv(t_prog *prog,
					 t_bunny_position *click_pos)
{
  if (click_pos->x >= WIN_WIDTH / 2 -
      (prog->player->inv_open_sprite->width / 2) / 4 + 10 &&
      click_pos->x <= WIN_WIDTH / 2 +
      (prog->player->inv_open_sprite->width / 2) / 4 - 10 &&
      click_pos->y >= WIN_HEIGHT / 2 -
      (prog->player->inv_open_sprite->height / 2) / 4 + 12 &&
      click_pos->y <= WIN_HEIGHT / 2 +
      (prog->player->inv_open_sprite->height / 2) / 4 - 12)
    {
      return ((click_pos->x -
	       (WIN_WIDTH / 2 - (prog->player->hotbar_sprite->width / 2)
		/ 4 + 12 )) / 40);
    }
  return (-1);
}

int			get_click_place_inventory(t_prog *prog,
				       t_bunny_position *click_pos)
{
  int			x;
  int			y;

  x = find_x_place_inv(prog, click_pos);
  y = find_y_place_inv(prog, click_pos);
  if (x != -1 && y != -1)
    return (x + (y % 4) * 12);
  return (-1);
}
