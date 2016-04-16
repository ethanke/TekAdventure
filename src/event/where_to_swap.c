/*
** where_to_swap.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/event/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Sat Apr 16 06:45:50 2016 Ethan Kerdelhue
** Last update Sat Apr 16 06:45:55 2016 Ethan Kerdelhue
*/

#include		"main.h"

int			where_to_swap(t_prog *prog, int need_to_move)
{
  if (prog->player->inv_selected >= 48 && need_to_move < 48)
      is_valid_equip(prog, need_to_move);
  else if (prog->player->inv_selected < 48 && need_to_move >= 48)
    {
      if (prog->player->inventory[(int)prog->player->inv_selected].id == -1)
	pull_out_equip(prog, need_to_move);
    }
  else if (prog->player->inventory[need_to_move].id == prog->player->inventory
	   [(int)prog->player->inv_selected].id && need_to_move !=
	   prog->player->inv_selected)
    stack_item(prog, need_to_move);
  else
    {
      if (prog->player->inv_selected < 48 && need_to_move < 48)
	{
	  my_swap_item(&prog->player->inventory[need_to_move],
			     &prog->player->inventory[(int)prog->player->
			     inv_selected]);
	}
    }
  return (0);
}
