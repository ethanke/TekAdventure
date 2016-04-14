/*
** get_npc_trade_click.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/event/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Wed Apr 13 01:32:04 2016 Victor Sousa
** Last update Thu Apr 14 01:15:34 2016 Victor Sousa
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
    return (-2);
  if (click_pos->x >= WIN_WIDTH / 2 -
      prog->scene->object->texture->width / 2 + 100 &&
      click_pos->x <= WIN_WIDTH / 2 -
      prog->scene->object->texture->width / 2 + 134 &&
      click_pos->y >= WIN_HEIGHT / 2 -
      prog->scene->object->texture->height / 2 + 90 &&
      click_pos->y <= WIN_HEIGHT / 2 -
      prog->scene->object->texture->height / 2 + 122 &&
      prog->current_click.npc->trade->in_stock->amount >=
      prog->current_click.npc->trade->needed->amount)
    return (-3);
  return (-1);
}
