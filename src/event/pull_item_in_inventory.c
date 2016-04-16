/*
** pull_item_in_inventory.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/event/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Sat Apr 16 06:47:08 2016 Ethan Kerdelhue
** Last update Sat Apr 16 06:47:19 2016 Ethan Kerdelhue
*/

#include		"main.h"

void			put_item_in_inventory(t_prog *prog, int need_to_move)
{
  prog->player->inventory[(int)prog->player->inv_selected].id =
  prog->player->inventory[need_to_move].id;
  if (prog->player->inventory[(int)prog->player->inv_selected].
	    amount == 0)
    {
      prog->player->inventory[(int)prog->player->inv_selected].
      amount++;
    }
  else
    {
      prog->player->inventory[(int)prog->player->inv_selected].
      amount = 1;
    }
  put_in_equip(prog, need_to_move);
  if (prog->player->inventory[need_to_move].amount == 0)
    {
      prog->player->inventory[need_to_move].id = -1;
      prog->player->inventory[need_to_move].object = NULL;
    }
}
