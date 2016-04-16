/*
** hitbox_creator.c for image in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/image/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Wed Apr  6 23:47:57 2016 Gaëtan Léandre
** Last update Sat Apr 16 05:09:27 2016 Gaëtan Léandre
*/

#include 		"main.h"

t_hitbox	create_hitbox(int x, int y, int width, int height)
{
  t_hitbox	result;

  result.x = x;
  result.y = y;
  result.width = width;
  result.height = height;
  return (result);
}

t_hitbox	*create_hitbox_ptr(t_bunny_position pos, int width, int height,
				   t_ptr_list *ptr_list)
{
  t_hitbox	*result;

  if ((result = xmalloc(sizeof(t_hitbox), &ptr_list)) == NULL)
    return (NULL);
  result->x = pos.x;
  result->y = pos.y;
  result->width = width;
  result->height = height;
  return (result);
}

int			in_hitbox(t_hitbox *hitbox, t_bunny_position *pos)
{
  if (pos->x > hitbox->x && pos->x < hitbox->x + hitbox->width
      && pos->y > hitbox->y && pos->y < hitbox->y + hitbox->height)
    return (1);
  return (0);
}
