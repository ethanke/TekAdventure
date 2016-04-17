/*
** disp_move.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/event/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Apr 17 02:40:55 2016 Gaëtan Léandre
** Last update Sun Apr 17 07:36:02 2016 Gaëtan Léandre
*/

#include		"main.h"

t_anim			*chose_deplacement(t_player *player)
{
  if (ABS(player->x_vec) >= ABS(player->y_vec) && player->x_vec < 0)
    return (&player->left);
  else if (ABS(player->x_vec) >= ABS(player->y_vec) && player->x_vec > 0)
    return (&player->right);
  else if (ABS(player->x_vec) <= ABS(player->y_vec) && player->y_vec < 0)
    return (&player->up);
  else if (ABS(player->x_vec) <= ABS(player->y_vec) && player->y_vec > 0)
    return (&player->down);
  else if (player->x_vec == 0 && player->y_vec == 0)
    return (&player->stop);
  else
    return (&player->down);
}
