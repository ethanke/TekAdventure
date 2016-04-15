/*
** disp_floating_item.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/disp/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Fri Apr 15 22:18:46 2016 Victor Sousa
** Last update Fri Apr 15 22:29:13 2016 Victor Sousa
*/

#include		"main.h"

static void		choose_floating_item(t_prog *prog,
					     t_bunny_position pos)
{
  if (prog->state == STATE_NPC && prog->player->inv_selected == -2)
    place_image(create_hitbox(pos.x, pos.y, 36, 30),
		*prog->current_click.npc->trade->needed->object->texture_hitbox,
		prog->current_click.npc->trade->needed->object->texture,
		prog->pix);
  else if (prog->state == STATE_NPC && prog->player->inv_selected == -3)
    place_image(create_hitbox(pos.x, pos.y, 36, 30),
		*prog->current_click.npc->trade->given->object->texture_hitbox,
		prog->current_click.npc->trade->given->object->texture,
		prog->pix);
  else
    place_image(create_hitbox(pos.x, pos.y, 36, 30),
		*prog->player->inventory
		[(int)prog->player->inv_selected].object->texture_hitbox,
		prog->player->inventory
		[(int)prog->player->inv_selected].object->texture,
		prog->pix);
}

void			disp_floating_item(t_prog *prog,
					   t_bunny_position *click_pos)
{
  t_bunny_position	pos;

  if (prog->player->inv_selected != -1)
    {
      pos.x = click_pos->x - 20;
      pos.y = click_pos->y - 18;
      choose_floating_item(prog, pos);
    }
}
