/*
** animated_image.c for image in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/image/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Fri Apr 15 03:06:55 2016 Gaëtan Léandre
** Last update Sun Apr 17 00:49:33 2016 Gaëtan Léandre
*/

#include		"main.h"

void			animated_image(t_anim *anim, t_hitbox hitbox,
				       t_bunny_pixelarray *pix)
{
  t_hitbox		actual;

  actual = create_hitbox(anim->hitbox.x + (anim->hitbox.width * anim->pos),
			 anim->hitbox.y, anim->hitbox.width,
			 anim->hitbox.height);
  place_image(hitbox, actual, anim->texture, pix);
  anim->pos = (anim->pos >= anim->max - 2
	       || actual.width + actual.x >= anim->texture->width) ?
	  (0) : (anim->pos + 1);
}
