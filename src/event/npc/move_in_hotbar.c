/*
** move_in_hotbar.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/event/npc/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Fri Apr 15 08:31:07 2016 Victor Sousa
** Last update Fri Apr 15 08:32:10 2016 Victor Sousa
*/

#include	"main.h"

void		move_in_hotbar(t_prog *prog, int need_to_move)
{
  if (prog->player->inventory[need_to_move].id ==
      prog->player->inventory[(int)prog->player->inv_selected].id &&
      need_to_move != prog->player->inv_selected)
    {
      prog->player->inventory[(int)prog->player->inv_selected].amount +=
      prog->player->inventory[need_to_move].amount;
      prog->player->inventory[need_to_move].id = -1;
      prog->player->inventory[need_to_move].amount = 0;
      prog->player->inventory[need_to_move].object = NULL;
    }
  else
    my_swap_item(&prog->player->inventory[need_to_move],
		 &prog->player->inventory[(int)prog->player->inv_selected]);
}
