/*
** parsing_sky.c for TekAdventure in /media/storage/my_files/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing/
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Thu Apr 14 02:52:33 2016 Philippe Lefevre
** Last update Thu Apr 14 02:56:45 2016 Philippe Lefevre
*/

#include		"main.h"

t_sky			*order_sky(t_sky *sky)
{
  t_texture		*texture_swap;
  t_hitbox		*hitbox_swap;
  t_sky  		*tmp_sky;
  int			id_swap;
  int			distance_swap;

  tmp_sky = sky;
  while (tmp_sky != NULL)
    {
      if ((tmp_sky->next != NULL)
	  && (tmp_sky->distance > tmp_sky->next->distance))
	{
	  id_swap = tmp_sky->sky_sprite_id;
	  tmp_sky->sky_sprite_id = tmp_sky->next->sky_sprite_id;
	  tmp_sky->next->sky_sprite_id = id_swap;

	  texture_swap = tmp_sky->texture;
	  tmp_sky->texture = tmp_sky->next->texture;
	  tmp_sky->next->texture = texture_swap;

	  hitbox_swap = tmp_sky->hitbox;
	  tmp_sky->hitbox = tmp_sky->next->hitbox;
	  tmp_sky->next->hitbox = hitbox_swap;

	  distance_swap = tmp_sky->distance;
	  tmp_sky->distance = tmp_sky->next->distance;
	  tmp_sky->next->distance = distance_swap;
	  tmp_sky = sky;
	}
      else
	tmp_sky = tmp_sky->next;
    }
  return (sky);
}

t_sky			*link_sky(t_sky *sky, t_sprite *sprite)
{
  t_sprite		*tmp_sprite;
  t_sky			*tmp_sky;

  tmp_sprite = sprite;
  while (tmp_sprite != NULL)
    {
      tmp_sky = sky;
      while (tmp_sky != NULL)
	{
	  if (tmp_sky->sky_sprite_id == tmp_sprite->id)
	    tmp_sky->texture = tmp_sprite->sprite;
	  tmp_sky = tmp_sky->next;
	}
      tmp_sprite = tmp_sprite->next;
    }
  return (order_sky(sky));
}
