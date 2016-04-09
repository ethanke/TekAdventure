/*
** parsing_scene.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Thu Apr  7 01:13:52 2016 Philippe Lefevre
** Last update Sat Apr  9 05:51:51 2016 Philippe Lefevre
*/

#include		"main.h"

t_object		*link_object(t_object *object, t_sprite *sprite)
{
  t_object		*tmp_object;
  t_sprite		*tmp_sprite;

  tmp_object = object;
  while (tmp_object != NULL)
    {
      tmp_sprite = sprite;
      while (tmp_sprite != NULL)
	{
	  if (tmp_sprite->id == tmp_object->sprite_id)
	    tmp_object->texture = tmp_sprite->sprite;
	  tmp_sprite = tmp_sprite->next;
	}
      tmp_object = tmp_object->next;
    }
  return (object);
}

t_decors		*link_decors(t_decors *decors, t_sprite *sprite)
{
  t_decors		*tmp_decors;
  t_sprite		*tmp_sprite;

  tmp_decors = decors;
  while (tmp_decors != NULL)
    {
      tmp_sprite = sprite;
      while (tmp_sprite != NULL)
	{
	  if (tmp_sprite->id == tmp_decors->sprite_id)
	    tmp_decors->texture = tmp_sprite->sprite;
	  tmp_sprite = tmp_sprite->next;
	}
      tmp_decors = tmp_decors->next;
    }
  return (decors);
}

t_npc			*link_npc(t_npc *npc, t_sprite *sprite)
{
  t_npc			*tmp_npc;
  t_sprite		*tmp_sprite;

  tmp_npc = npc;
  while (tmp_npc != NULL)
    {
      tmp_sprite = sprite;
      while (tmp_sprite != NULL)
	{
	  if (tmp_sprite->id == tmp_npc->sprite_id)
	    tmp_npc->texture = tmp_sprite->sprite;
	  tmp_sprite = tmp_sprite->next;
	}
      tmp_npc = tmp_npc->next;
    }
  return (npc);
}

t_item			*link_inventory_item(t_item *inventory, t_object *object)
{
  t_object		*tmp_object;
 int			i;

  i = -1;
  while (++i != SIZE_INVENTORY)
    {
      tmp_object = object;
      while (tmp_object != NULL)
	{
	  if (tmp_object->object_id == inventory[i].id)
	    inventory[i].object = tmp_object;
	  tmp_object = tmp_object->next;
	}
    }
  return (inventory);
}

t_scene			*load_scene(t_bunny_ini *ini, t_scene *scene,
				    t_ptr_list **ptr_list)
{
  scene->object = link_object(scene->object, scene->sprite);
  scene->player->inventory = link_inventory_item(scene->player->inventory, scene->object);
  scene->decors = link_decors(scene->decors, scene->sprite);
  scene->npc = link_npc(scene->npc, scene->sprite);
  (void)ini;
  (void)ptr_list;
  return (scene);
}
