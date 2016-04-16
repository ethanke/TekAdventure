/*
** parsing_sprite.c for TekAdventure in /media/storage/my_files/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing/
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Sat Apr 16 07:35:33 2016 Philippe Lefevre
** Last update Sat Apr 16 09:26:50 2016 Philippe Lefevre
*/

#include 		"main.h"

t_sprite		*create_sprite_node(int id,
					    t_bunny_ini *ini,
					    t_ptr_list **ptr_list, char *str)
{
  t_sprite		*sprite;

  if ((sprite = xmalloc(sizeof(*sprite), ptr_list)) == NULL)
    return (my_puterror_sprite("Error: sprite:xmalloc ", -1,
			       "failed in create_sprite_node\n"));
  if ((str = (char *)bunny_ini_get_field(ini, "sprite", "sprite_path", id))
      == NULL)
    return (my_puterror_sprite("Error: sprite:sprite_path field \n", id,
			       " not found\n"));
  if ((sprite->path = my_strdup(str, ptr_list)) == NULL)
    return (my_puterror_sprite("Error: sprite->path:my_strdup ", -1,
			       "failed in create_sprite_node\n"));
  if ((sprite->sprite = load_image(str, ptr_list)) == NULL)
    return (my_puterror_sprite("Error: sprite->sprite:load_image ", -1,
			       "failed in create_sprite_node"));
  if ((str = (char *)bunny_ini_get_field(ini, "sprite", "sprite_id", id))
      == NULL)
    return (my_puterror_sprite("Error: sprite:sprite_id field \n", id,
			       " not found\n"));
  if ((sprite->id = my_getnbr(str)) < 0)
    return (my_puterror_sprite("Error: sprite:sprite_id field ", id,
			       " should not be negative\n"));
  sprite->next = NULL;
  sprite->prev = NULL;
  return (sprite);
}

t_sprite		*list_add_sprite_check(t_sprite *tmp, t_sprite *new,
					       int id, int i)
{
  if (tmp->id == new->id)
    {
      my_puterror_sprite("Error: sprite:sprite_id field ", id, " ");
      return (my_puterror_sprite("already declared in field ", i, "\n"));
    }
  else if (my_strcmp(tmp->path, new->path) == 0)
    {
      my_puterror_sprite("Error: sprite:sprite_path field ", id, " ");
      return (my_puterror_sprite("already declared in field ", i, "\n"));
    }
  return (new);
}

t_sprite		*list_add_sprite(t_sprite *list, int id,
					 t_bunny_ini *ini,
					 t_ptr_list **ptr_list)
{
  t_sprite		*new;
  t_sprite		*tmp;
  int			i;

  if ((new = create_sprite_node(id, ini, ptr_list, NULL)) == NULL)
    return (NULL);
  if (list == NULL)
    return (new);
  tmp = list;
  i = 0;
  while (tmp->next != NULL && ++i)
    {
      if ((list_add_sprite_check(tmp, new, id, i)) == NULL)
	return (NULL);
      tmp = tmp->next;
    }
  if ((list_add_sprite_check(tmp, new, id, i)) == NULL)
    return (NULL);
  tmp = tmp;
  new->prev = tmp;
  new->next = NULL;
  tmp->next = new;
  return (list);
}

t_sprite		*load_sprite(t_bunny_ini *ini, t_ptr_list **ptr_list)
{
  t_sprite	*list;

  char		*str;
  int		nb_sprite;
  int		i;

  if ((str = (char *)bunny_ini_get_field(ini, "sprite", "sprite_count", 0))
      == NULL)
    return (my_puterror_sprite("Error: balise sprite or sprite:sprite_count ",
			       -1, "field not found\n"));
  if ((nb_sprite = my_getnbr(str)) < 0)
    return (my_puterror_sprite("Error: sprite:sprite_id ", -1,
			       "should not be negative\n"));
  list = NULL;
  i = -1;
  while (++i != nb_sprite)
    if ((list = list_add_sprite(list, i, ini, ptr_list)) == NULL)
      return (NULL);
  return (list);
}
