/*
** get_npc_trade_click.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/event/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Wed Apr 13 01:32:04 2016 Victor Sousa
** Last update Wed Apr 13 03:20:54 2016 Victor Sousa
*/

#include		"main.h"

int			get_click_place_npc_trade(t_prog *prog,
						  t_bunny_position *click_pos)
{
  if (click_pos->x >= WIN_WIDTH / 2 -
      prog->scene->object->texture->width / 2 - 15 &&
      click_pos->x <= WIN_WIDTH / 2 -
      prog->scene->object->texture->width / 2 + 19 &&
      click_pos->y >= WIN_HEIGHT / 2 -
      prog->scene->object->texture->height / 2 + 90 &&
      click_pos->y <= WIN_HEIGHT / 2 -
      prog->scene->object->texture->height / 2 + 122)
    return (0);
  return (-1);
}
