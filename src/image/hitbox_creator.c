/*
** hitbox_creator.c for image in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/image/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Wed Apr  6 23:47:57 2016 Gaëtan Léandre
** Last update Thu Apr  7 00:26:43 2016 Gaëtan Léandre
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
