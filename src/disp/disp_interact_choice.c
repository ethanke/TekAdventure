/*
** disp_interact_choice.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/disp/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Thu Apr 14 05:59:32 2016 Victor Sousa
** Last update Fri Apr 15 00:20:53 2016 Victor Sousa
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
  t_font		font;
  t_bunny_position	f_pos;

  font.font_img = prog->font->font_img;
  font.font_size = 25;
  font.font_color.full = 0xFF050505;
  f_pos.x = WIN_WIDTH / 2;
  f_pos.y = WIN_HEIGHT - 200;
  if (prog->player->item_selected != -1 &&

      prog->player->inventory[prog->player->item_selected].id != -1)
    {
      if (prog->current_click.decors->decors_breakable->is_breakable == 1)
	{
	  if (prog->player->inventory[prog->player->item_selected].id ==
	      prog->current_click.decors->decors_breakable->breakable_by)
	    {
	      printf("damage applyed\n");
	      prog->current_click.decors->decors_breakable->life -=
	      prog->player->inventory[prog->player->item_selected].object->damage          * 10;
	      if (prog->current_click.decors->decors_breakable->life <= 0)
		{
		  printf("Decors dead\n");
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
                    }
                  else
                    printf("Out of space in inventory\n");
		}
	      else
		printf("decors has now %dlife\n",
		       prog->current_click.decors->decors_breakable->life);
	    }
	  else
	    printf("Wrong tools\n");
	}
      else
	printf("Can't break this\n");
      prog->player->item_selected = -1;
      prog->state = STATE_GAME;
    }
  else
    {
      tektext("Pick the item to use in your hotbar!",
	      &f_pos, prog->pix, &font);
    }
}
