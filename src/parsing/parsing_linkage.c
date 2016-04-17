/*
** parsing_linkage.c for TekAdventure in /media/storage/my_files/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing/
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Thu Apr 14 02:50:32 2016 Philippe Lefevre
** Last update Sun Apr 17 04:33:06 2016 Philippe Lefevre
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
	    {
	      tmp_object->texture = tmp_sprite->sprite;
	      if ((tmp_object->texture_hitbox->x + tmp_object->texture_hitbox->
		   width > tmp_object->texture->width)
		  || (tmp_object->texture_hitbox->y + tmp_object->
		     texture_hitbox->height > tmp_object->texture->height))
		return (my_puterror_object("Error: hitbox form object id ",
					   tmp_object->object_id,
					   " is out of range\n"));
	    }
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
	    {
	      tmp_decors->texture = tmp_sprite->sprite;
	      if ((tmp_decors->texture_hitbox->x + tmp_decors->
		   texture_hitbox->width > tmp_decors->texture->width)
		  || (tmp_decors->texture_hitbox->y + tmp_decors->
		      texture_hitbox->height > tmp_decors->texture->height))
		return (my_puterror_decors("Error: hitbox form decors id ",
					   tmp_decors->decors_id,
					   " is out of range\n"));
	    }
	  tmp_sprite = tmp_sprite->next;
	}
      tmp_decors = tmp_decors->next;
    }
  return (decors);
}

t_npc			*link_npc_trade_object(t_object *object, t_npc *tmp_npc)
{
  t_object		*tmp_object;

  tmp_object = object;
  while (tmp_object != NULL)
    {
      if (tmp_object->object_id == tmp_npc->trade->needed->id)
	tmp_npc->trade->needed->object = tmp_object;
      if (tmp_object->object_id == tmp_npc->trade->given->id)
	tmp_npc->trade->given->object = tmp_object;
      tmp_object = tmp_object->next;
    }
  return (tmp_npc->next);
}

t_npc			*link_npc(t_npc *npc, t_sprite *sprite,
				  t_object *object)
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
	    {
	      tmp_npc->texture = tmp_sprite->sprite;
              if ((tmp_npc->texture_hitbox->x + tmp_npc->
                   texture_hitbox->width > tmp_npc->texture->width)
		  || (tmp_npc->texture_hitbox->y + tmp_npc->
		      texture_hitbox->height > tmp_npc->texture->height))
		return (my_puterror_npc("Error: hitbox form decors id ",
					   tmp_npc->npc_id,
					   " is out of range\n"));
	    }
	  tmp_sprite = tmp_sprite->next;
	}
      tmp_npc = link_npc_trade_object(object, tmp_npc);
    }
  return (npc);
}
