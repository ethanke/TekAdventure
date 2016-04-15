/*
** disp_interact_choice.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/disp/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Thu Apr 14 05:59:32 2016 Victor Sousa
** Last update Fri Apr 15 02:12:35 2016 Victor Sousa
*/

#include		"main.h"

static int		there_is_place_in_inv(t_item *inv)
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

static t_object		*fint_obj_by_id(t_object *head, int id)
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

void			interact_decors(t_prog *prog)
{
  int			place;

  if (prog->player->item_selected != -1 &&
      prog->player->inventory[prog->player->item_selected].id != -1)
    {
      if (prog->current_click.decors->decors_breakable->is_breakable == 1)
	{
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
		    {
		      prog->player->inventory[place].id =
		      prog->current_click.decors->decors_breakable->loot[0];
		      prog->player->inventory[place].amount =
		      prog->current_click.decors->decors_breakable->loot[1];
		      prog->player->inventory[place].object =
		      fint_obj_by_id(prog->scene->object,
				     prog->current_click.decors->decors_breakable->loot[0]);
		      prog->disp_str =
		      malloc(my_strlen(my_itoa(prog->player->
					       inventory[place].amount)) +
			     my_strlen(prog->player->inventory[place].
				       object->name) + 8);
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
		  else
		    {
		      prog->disp_str = malloc(27);
		      prog->disp_str =
		      my_strcpy(prog->disp_str,
				"Out of space in inventory");
		      prog->disp_delay = 25;
		    }
		}
	      else
		{
		  prog->disp_str = malloc(my_strlen(my_itoa(prog->current_click.
							    decors->decors_breakable->life)) + 20);
		  prog->disp_str = my_strcpy(prog->disp_str, "decors has now ");
		  prog->disp_str =
		  my_strcat(prog->disp_str, my_itoa(prog->current_click.
						    decors->decors_breakable->
						    life));
		  prog->disp_str = my_strcat(prog->disp_str, " life");
		  prog->disp_delay = 25;
		}
	    }
	  else
	    {
	      prog->disp_str = malloc(my_strlen(fint_obj_by_id(prog->scene->object,
							       prog->current_click.
							       decors->decors_breakable->
							       breakable_by)->name) + 25);
	      prog->disp_str = my_strcpy(prog->disp_str, "Wrong tools, you need ");
	      prog->disp_str =
	      my_strcat(prog->disp_str,
			fint_obj_by_id(prog->scene->object,
				       prog->current_click.decors->
				       decors_breakable->
				       breakable_by)->name);
	      prog->disp_delay = 25;
	    }
	}
      else
	{
	  prog->disp_str = malloc(33);
	  prog->disp_str = my_strcpy(prog->disp_str, "Can't break this, Too Strong :D");
	  prog->disp_delay = 25;
	}
      prog->player->item_selected = -1;
      prog->state = STATE_GAME;
    }
  else
    {
      prog->disp_str = malloc(39);
      prog->disp_str = my_strcpy(prog->disp_str, "Pick the item to use\nin your hotbar!");
      prog->disp_delay = 25;
    }
}
