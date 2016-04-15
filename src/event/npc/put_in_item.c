/*
** put_in_item.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/event/npc/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Fri Apr 15 08:33:34 2016 Victor Sousa
** Last update Fri Apr 15 08:35:34 2016 Victor Sousa
*/

#include		"main.h"

void			put_in_item(t_prog *prog, int need_to_move)
{
  if (prog->player->inv_selected == -2 &&
      prog->player->inventory[need_to_move].id ==
      prog->current_click.npc->trade->needed->id)
    {
      my_swap_item(&prog->player->inventory[need_to_move],
		   prog->current_click.npc->trade->in_stock);
    }
  else if (need_to_move == -2 &&
	   prog->player->inventory[(int)prog->player->inv_selected].id == -1)
    {
      my_swap_item(&prog->player->inventory[(int)prog->player->inv_selected],
		   prog->current_click.npc->trade->in_stock);
    }
}
