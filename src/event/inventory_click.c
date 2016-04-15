/*
** inventory_click.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/event/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr  9 09:11:28 2016 Victor Sousa
** Last update Fri Apr 15 04:21:18 2016 Philippe Lefevre
*/

#include		"main.h"

void			handle_inventory_click(t_prog *prog)
{
  t_bunny_position	*click_pos;
  int			need_to_move;

  need_to_move = -1;
  click_pos = (t_bunny_position *)bunny_get_mouse_position();
  if (prog->player->inv_selected != -1)
    {
      need_to_move = prog->player->inv_selected;
      place_image(create_hitbox(click_pos->x, click_pos->y, 36, 30),
		  *prog->player->inventory[need_to_move].object->texture_hitbox,
		  prog->player->inventory[need_to_move].object->texture, prog->pix);
    }
  prog->player->inv_selected = get_click_place_hotbar(prog, click_pos);
  if (prog->player->inv_selected == -1 && prog->player->inventory_open == 1)
    prog->player->inv_selected = get_click_place_inventory(prog, click_pos);
  if (prog->player->inv_selected != 1 &&
      prog->player->inventory[(int)prog->player->inv_selected].id == -1 &&
      need_to_move == -1)
    prog->player->inv_selected = -1;
  if (need_to_move != -1 && prog->player->inv_selected != -1)
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
      prog->player->inv_selected = -1;
    }
}

void			handle_inventory_click_npc(t_prog *prog)
{
  t_bunny_position	*click_pos;
  int			need_to_move;

  need_to_move = -1;
  click_pos = (t_bunny_position *)bunny_get_mouse_position();
  if (click_pos->x >= WIN_WIDTH / 2 + prog->exchange_sprite->width / 2 - 30 &&
      click_pos->x <= WIN_WIDTH / 2 + prog->exchange_sprite->width / 2 &&
      click_pos->y >= WIN_HEIGHT / 2 - prog->exchange_sprite->height / 2 &&
      click_pos->y <= WIN_HEIGHT / 2 - prog->exchange_sprite->height / 2 + 30)
    prog->state = STATE_GAME;
  if (prog->player->inv_selected != -1)
    {
      need_to_move = prog->player->inv_selected;
      if (need_to_move == -2)
	{
	  place_image(create_hitbox(click_pos->x, click_pos->y, 36, 30),
		      *prog->current_click.npc->trade->in_stock->object->texture_hitbox,
		      prog->current_click.npc->trade->in_stock->object->texture, prog->pix);
	}
      else if (need_to_move == -3)
	{
	  place_image(create_hitbox(click_pos->x, click_pos->y, 36, 30),
		      *prog->current_click.npc->trade->given->object->texture_hitbox,
		      prog->current_click.npc->trade->given->object->texture, prog->pix);
	}
      else
	{
	  place_image(create_hitbox(click_pos->x, click_pos->y, 36, 30),
		      *prog->player->inventory[need_to_move].object->texture_hitbox,
		      prog->player->inventory[need_to_move].object->texture, prog->pix);
	}
    }
  prog->player->inv_selected = get_click_place_hotbar(prog, click_pos);
  if (prog->player->inv_selected == -1 && prog->state == STATE_NPC)
    prog->player->inv_selected = get_click_place_npc_trade(prog, click_pos);
  if (prog->player->inv_selected == -2 && prog->current_click.npc->trade->in_stock->amount <= 0 && need_to_move == -1)
    prog->player->inv_selected = -1;
  if (prog->player->inventory[(int)prog->player->inv_selected].id == -1 &&
      need_to_move == -1)
    prog->player->inv_selected = -1;
  if (need_to_move == -2 && prog->player->inv_selected == -2)
    prog->player->inv_selected = -1;
  if (need_to_move != -1 && prog->player->inv_selected != -1)
    {
      if (need_to_move >= 0 && prog->player->inv_selected >= 0)
	{
	  /* inside hotbar */
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
      else if (need_to_move == -3 &&
	       prog->player->inventory[(int)prog->player->inv_selected].id == -1)
	{
	  /* output npc */
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
      else
	{
	  /* stock npc */
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
      prog->player->inv_selected = -1;
    }
}
