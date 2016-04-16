/*
** load_image.c for image in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/image/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Wed Apr  6 23:25:07 2016 Gaëtan Léandre
** Last update Sat Apr 16 19:45:40 2016 Ethan Kerdelhue
*/

#include 		"main.h"

t_texture		*pix_array_to_texture(t_bunny_pixelarray *pix,
					      t_ptr_list **pr)
{
  t_texture		*ou;
  t_bunny_position	pos;

  if ((ou = xmalloc(sizeof(t_texture), pr)) == NULL)
    return (NULL);
  ou->width = pix->clipable.clip_width;
  ou->height = pix->clipable.clip_height;
  if ((ou->color = xmalloc(sizeof(t_color *) * (ou->height + 1), pr)) == NULL)
    return (NULL);
  pos.y = 0;
  while (pos.y < ou->height)
    {
      if ((ou->color[pos.y] = xmalloc(4 * (ou->width + 1), pr)) == NULL)
	return (NULL);
      pos.x = 0;
      while (pos.x < ou->width)
	{
	  ou->color[pos.y][pos.x].full =
	    ((t_color *)pix->pixels)[pos.y * ou->width + pos.x].full;
	  pos.x++;
	}
      pos.y++;
    }
  bunny_delete_clipable(&pix->clipable);
  return (ou);
}

t_texture      		*load_image(const char *file, t_ptr_list **ptr_list)
{
  t_bunny_pixelarray	*tmp;

  if ((tmp = bunny_load_pixelarray(file)) == NULL)
    return (NULL);
  return (pix_array_to_texture(tmp, ptr_list));
}
