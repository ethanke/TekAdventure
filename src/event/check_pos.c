/*
** check_pos.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/event/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Wed Apr 13 21:16:37 2016 Gaëtan Léandre
** Last update Thu Apr 14 06:39:03 2016 Gaëtan Léandre
*/

#include		"main.h"

int			is_near(int x_player, int y_player,
				int x_case, int y_case)
{
  if ((TRAVERS == 0 && (x_player - x_case == 0 || y_player - y_case == 0))
      || TRAVERS == 1)
    {
      if (x_player - x_case >= -1 && x_player - x_case <= 1
	  && y_player - y_case >= -1 && y_player - y_case <= 1)
	return (1);
    }
  return (-1);
}

void			on_gate(t_prog *prog)
{
  t_player		*player;
  t_gate		*gate;

  player = prog->player;
  gate = prog->scene->ground[(int)player->x
      + (int)player->y * prog->scene->size.x].gate;
  if (player->move.depla == NULL && gate != NULL)
    {
      prog->scene = gate->scene;
      player->x = prog->scene->start_pos->x;
      player->y = prog->scene->start_pos->y;
    }
}
