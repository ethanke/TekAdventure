/*
** load_image.c for image in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/image/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Wed Apr  6 23:25:07 2016 Gaëtan Léandre
** Last update Thu Apr  7 02:07:58 2016 victor sousa
*/

#include 		"main.h"

t_texture		*pix_array_to_texture(t_bunny_pixelarray *pix,
					      t_ptr_list **pr)
{
  t_texture		*out;
  t_bunny_position	pos;

  if ((out = xmalloc(sizeof(t_texture), pr)) == NULL)
    return (NULL);
  out->width = pix->clipable.clip_width;
  out->height = pix->clipable.clip_height;
  if ((out->color = xmalloc(sizeof(t_color *) * (out->height + 1), pr)) == NULL)
    return (NULL);
  pos.y = 0;
  while (pos.y < out->height)
    {
      if ((out->color[pos.y] = xmalloc(4 * (out->width + 1), pr)) == NULL)
	return (NULL);
      pos.x = 0;
      while (pos.x < out->width)
	{
	  out->color[pos.y][pos.x].full =
	    ((t_color *)pix->pixels)[pos.y * out->width + pos.x].full;
	  pos.x++;
	}
      pos.y++;
    }
  bunny_delete_clipable(&pix->clipable);
  return (out);
}

t_texture      		*load_image(const char *file, t_ptr_list **ptr_list)
{
  t_bunny_pixelarray	*tmp;

  if ((tmp = bunny_load_pixelarray(file)) == NULL)
    return (NULL);
  return (pix_array_to_texture(tmp, ptr_list));
}
