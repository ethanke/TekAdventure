/*
** parsing_player_linkage.c for TekAdventure in /media/storage/my_files/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing/
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Thu Apr 14 03:00:55 2016 Philippe Lefevre
** Last update Sun Apr 17 06:06:22 2016 Philippe Lefevre
*/

#include		"main.h"

static int		is_in_inventory(t_object *object, int to_find, int i)
{
  t_object		*tmp_object;

  tmp_object = object;
  while (tmp_object != NULL)
    {
      if (tmp_object->object_id == to_find)
	return (0);
      tmp_object = tmp_object->next;
    }
  return (my_printf(2, "Error: inventory slot %d, no such object id %d\n",
		    i, to_find) - 1);
}

t_item			*link_inventory_item(t_item *inventory,
					     t_object *object)
{
  t_object		*tmp_object;
 int			i;

  i = -1;
  while (++i != SIZE_INVENTORY)
    {
      tmp_object = object;
      while (tmp_object != NULL)
	{
	  if (!(inventory[i].id < 0))
	    if (is_in_inventory(object, inventory[i].id, i))
	      return (NULL);
	  if (tmp_object->object_id == inventory[i].id)
	    inventory[i].object = tmp_object;
	  tmp_object = tmp_object->next;
	}
    }
  return (inventory);
}
