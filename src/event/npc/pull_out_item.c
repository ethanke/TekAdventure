/*
** pull_out_item.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/event/npc/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Fri Apr 15 08:28:59 2016 Victor Sousa
** Last update Fri Apr 15 08:29:36 2016 Victor Sousa
*/

#include		"main.h"

void			pull_out_item(t_prog *prog)
{
  prog->player->inventory[(int)prog->player->inv_selected].id =
  prog->current_click.npc->trade->given->id;
  prog->player->inventory[(int)prog->player->inv_selected].amount =
  prog->current_click.npc->trade->given->amount;
  prog->player->inventory[(int)prog->player->inv_selected].object =
  prog->current_click.npc->trade->given->object;
  prog->current_click.npc->trade->in_stock->amount -=
  prog->current_click.npc->trade->needed->amount;
  if (prog->current_click.npc->trade->in_stock->amount <= 0)
    {
      prog->current_click.npc->trade->in_stock->id = -1;
      prog->current_click.npc->trade->in_stock->amount = 0;
      prog->current_click.npc->trade->in_stock->object = NULL;
    }
}
