/*
** disp_interact_choice.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/disp/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Thu Apr 14 05:59:32 2016 Victor Sousa
** Last update Fri Apr 15 23:34:12 2016 Victor Sousa
*/

#include		"main.h"

int			there_is_place_in_inv(t_item *inv)
{
  int			i;

  i = 0;
  while (i < SIZE_INVENTORY)
    {
      if (inv[i].id == -1)
	return (i);
      i++;
    }
  return (-1);
}

t_object		*fint_obj_by_id(t_object *head, int id)
{
  t_object		*tmp;

  tmp = head;
  while (tmp != NULL)
    {
      if (tmp->object_id == id)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

void			get_dropped_item(t_prog *prog, int place)
{
  prog->player->inventory[place].id =
  prog->current_click.decors->decors_breakable->loot[0];
  prog->player->inventory[place].amount =
  prog->current_click.decors->decors_breakable->loot[1];
  prog->player->inventory[place].object =
  fint_obj_by_id(prog->scene->object,
		 prog->current_click.decors->decors_breakable->loot[0]);
  if ((prog->disp_str =
       malloc(my_strlen(my_itoa(prog->player->
				inventory[place].amount))
	      + my_strlen(prog->player->inventory[place].
			object->name) + 8)) == NULL)
    return;
  prog->disp_str = my_strcpy(prog->disp_str, "You got ");
  prog->disp_str =
  my_strcat(prog->disp_str, my_itoa(prog->player->
				    inventory[place].
				    amount));
  prog->disp_str =
  my_strcat(prog->disp_str, prog->player->inventory[place].
	    object->name);
  prog->disp_delay = 25;
}

void			try_to_break(t_prog *prog)
{
  int			place;

  if (prog->player->inventory[prog->player->item_selected].id ==
      prog->current_click.decors->decors_breakable->breakable_by)
    {
      prog->current_click.decors->decors_breakable->life -=
      prog->player->inventory[prog->player->item_selected].object->damage;
      if (prog->current_click.decors->decors_breakable->life <= 0)
	{
	  prog->scene->ground[prog->current_click.x + prog->current_click.y
	  * prog->scene->size.x].decors = NULL;
	  if ((place = there_is_place_in_inv(prog->player->inventory)) != -1)
	    get_dropped_item(prog, place);
	  else
	    disp_out_of_space(prog);
	}
            else
	disp_decord_life_text(prog);
    }
  else
    disp_need_tools(prog);
}

void			interact_decors(t_prog *prog)
{
  if (prog->player->item_selected != -1 &&
      prog->player->inventory[prog->player->item_selected].id != -1)
    {
      if (prog->current_click.decors->decors_breakable->is_breakable == 1)
	try_to_break(prog);
      else
	disp_cant_break(prog);
      prog->player->item_selected = -1;
      prog->state = STATE_GAME;
    }
  else
    disp_pick_item(prog);
}
