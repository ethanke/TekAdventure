/*
** get_click_value.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/event/npc/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Fri Apr 15 08:40:34 2016 Victor Sousa
** Last update Fri Apr 15 08:42:41 2016 Victor Sousa
*/

#include		"main.h"

int			get_click_value(t_prog *prog, int need_to_move,
					t_bunny_position *click_pos)
{
  if (prog->player->inv_selected != -1)
    {
      need_to_move = prog->player->inv_selected;
      draw_folowing_item(prog, need_to_move, click_pos);
    }
  prog->player->inv_selected = get_click_place_hotbar(prog, click_pos);
  if (prog->player->inv_selected == -1 && prog->state == STATE_NPC)
    prog->player->inv_selected = get_click_place_npc_trade(prog, click_pos);
  if (prog->player->inv_selected == -2 && prog->current_click.npc->trade->
      in_stock->amount <= 0 && need_to_move == -1)
    prog->player->inv_selected = -1;
  if (prog->player->inventory[(int)prog->player->inv_selected].id == -1 &&
      need_to_move == -1)
    prog->player->inv_selected = -1;
  if (need_to_move == -2 && prog->player->inv_selected == -2)
    prog->player->inv_selected = -1;
  return (need_to_move);
}
