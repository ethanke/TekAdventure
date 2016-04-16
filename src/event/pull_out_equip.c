/*
** pull_out_inventory.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/event/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Sat Apr 16 06:48:16 2016 Ethan Kerdelhue
** Last update Sat Apr 16 06:48:22 2016 Ethan Kerdelhue
*/

#include 		"main.h"

void			pull_out_equip(t_prog *prog, int need_to_move)
{
  prog->player->inventory[(int)prog->player->inv_selected].id =
  prog->player->inventory[need_to_move].id;
  prog->player->inventory[(int)prog->player->inv_selected].amount =
  prog->player->inventory[need_to_move].amount;
  prog->player->inventory[(int)prog->player->inv_selected].object =
  prog->player->inventory[need_to_move].object;
  prog->player->caract->stamina -=
  prog->player->inventory[need_to_move].object->caract->stamina;
  prog->player->life -=
  prog->player->inventory[need_to_move].object->caract->stamina * 2;
  prog->player->caract->strength -=
  prog->player->inventory[need_to_move].object->caract->strength;
  prog->player->caract->critical -=
  prog->player->inventory[need_to_move].object->caract->critical;
  prog->player->caract->intellect -=
  prog->player->inventory[need_to_move].object->caract->intellect;
  prog->player->caract->armor -=
  prog->player->inventory[need_to_move].object->caract->armor;
  prog->player->caract->agility -=
  prog->player->inventory[need_to_move].object->caract->agility;
  prog->player->inventory[need_to_move].id = -1;
  prog->player->inventory[need_to_move].amount = 0;
  prog->player->inventory[need_to_move].object = NULL;
}
