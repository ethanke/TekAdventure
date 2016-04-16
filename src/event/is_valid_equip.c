/*
** is_valid_equip.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/event/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Sat Apr 16 06:44:42 2016 Ethan Kerdelhue
** Last update Sat Apr 16 06:44:55 2016 Ethan Kerdelhue
*/

#include		"main.h"

void			is_valid_equip(t_prog *prog, int need_to_move)
{
  if (prog->player->inventory[need_to_move].object->is_equipable == 1 &&
      prog->player->inventory[need_to_move].object->slot ==
      prog->player->inv_selected - 48 &&
      prog->player->inventory[(int)prog->player->inv_selected].amount
      < 1)
    put_item_in_inventory(prog, need_to_move);
}
