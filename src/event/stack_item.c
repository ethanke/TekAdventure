/*
** stack_item.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/event/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Sat Apr 16 06:45:17 2016 Ethan Kerdelhue
** Last update Sat Apr 16 06:45:28 2016 Ethan Kerdelhue
*/

#include		"main.h"

void			stack_item(t_prog *prog, int need_to_move)
{
  prog->player->inventory[(int)prog->player->inv_selected].amount +=
  prog->player->inventory[need_to_move].amount;
  prog->player->inventory[need_to_move].id = -1;
  prog->player->inventory[need_to_move].amount = 0;
  prog->player->inventory[need_to_move].object = NULL;
}
