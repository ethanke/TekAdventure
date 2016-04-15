/*
** draw_folowing_item.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/event/npc/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Fri Apr 15 08:35:22 2016 Victor Sousa
** Last update Fri Apr 15 08:37:25 2016 Victor Sousa
*/

#include		"main.h"

void			draw_folowing_item(t_prog *prog, int need_to_move,
					   t_bunny_position *click_pos)
{
  if (need_to_move == -2)
    {
      place_image(create_hitbox(click_pos->x, click_pos->y, 36, 30),
		  *prog->current_click.npc->trade->in_stock->object->
		  texture_hitbox, prog->current_click.npc->trade->in_stock->
		  object->texture, prog->pix);
    }
  else if (need_to_move == -3)
    {
      place_image(create_hitbox(click_pos->x, click_pos->y, 36, 30),
		  *prog->current_click.npc->trade->given->object->
		  texture_hitbox, prog->current_click.npc->trade->given->
		  object->texture, prog->pix);
    }
  else
    {
      place_image(create_hitbox(click_pos->x, click_pos->y, 36, 30),
		  *prog->player->inventory[need_to_move].object->
		  texture_hitbox, prog->player->inventory[need_to_move].
		  object->texture, prog->pix);
    }
}
