/*
** handle_red_cross.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/event/npc/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Fri Apr 15 08:38:49 2016 Victor Sousa
** Last update Fri Apr 15 08:39:12 2016 Victor Sousa
*/

#include		"main.h"

void			handle_red_cross(t_prog *prog,
					 t_bunny_position *click_pos)
{
  if (click_pos->x >= WIN_WIDTH / 2 + prog->exchange_sprite->width / 2 - 30 &&
      click_pos->x <= WIN_WIDTH / 2 + prog->exchange_sprite->width / 2 &&
      click_pos->y >= WIN_HEIGHT / 2 - prog->exchange_sprite->height / 2 &&
      click_pos->y <= WIN_HEIGHT / 2 - prog->exchange_sprite->height / 2 + 30)
    prog->state = STATE_GAME;
}
