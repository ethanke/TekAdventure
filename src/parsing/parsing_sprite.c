/*
** load_sprite.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Thu Apr  7 00:39:08 2016 Ethan Kerdelhue
** Last update Wed Apr 13 22:04:16 2016 Philippe Lefevre
*/

#include 		"main.h"

t_sprite		*create_sprite_node(int id,
					    t_bunny_ini *ini,
					    t_ptr_list **ptr_list)
{
  t_sprite		*sprite;
  char			*str;

  if ((sprite = xmalloc(sizeof(*sprite), ptr_list)) == NULL)
    return (my_puterror_sprite("Error: sprite:xmalloc ", -1, "failed in create_sprite_node\n"));
  if ((str = (char *)bunny_ini_get_field(ini, "sprite", "sprite_path", id)) == NULL)
    return (my_puterror_sprite("Error: sprite:sprite_path field \n", id, " not found\n"));
  if ((sprite->path = my_strdup(str, ptr_list)) == NULL)
    return (my_puterror_sprite("Error: sprite->path:my_strdup ", -1, "failed in create_sprite_node\n"));
  if ((sprite->sprite = load_image(str, ptr_list)) == NULL)
    return (my_puterror_sprite("Error: sprite->sprite:load_image ", -1, "failed in create_sprite_node"));
  if ((str = (char *)bunny_ini_get_field(ini, "sprite", "sprite_id", id)) == NULL)
    return (my_puterror_sprite("Error: sprite:sprite_id field \n", id, " not found\n"));
  if ((sprite->id = my_getnbr(str)) < 0)
    return (my_puterror_sprite("Error: sprite:sprite_id field ", id, " should not be negative\n"));
  sprite->next = NULL;
  sprite->prev = NULL;
  return (sprite);
}

t_sprite		*list_add_sprite(t_sprite *list, int id,
					 t_bunny_ini *ini,
					 t_ptr_list **ptr_list)
{
  t_sprite		*new;
  t_sprite		*tmp;

  if ((new = create_sprite_node(id, ini, ptr_list)) == NULL)
    return (NULL);
  if (list == NULL)
    return (new);
  tmp = list;
  while (tmp->next != NULL)
    {
      if (tmp->id == new->id)
		{
		  my_puterror_sprite("Error: sprite:sprite_id field ", new->id, " ");
		  return (my_puterror_sprite("already declared in field ", tmp->id, "\n"));
		}
      tmp = tmp->next;
    }
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

  if ((str = (char *)bunny_ini_get_field(ini, "sprite", "sprite_count", 0)) == NULL)
    return (my_puterror_sprite("Error: balise sprite or sprite:sprite_count ", -1, "field not found\n"));
  if ((nb_sprite = my_getnbr(str)) < 0)
    return (my_puterror_sprite("Error: sprite:sprite_id ", -1, "should not be negative\n"));
  list = NULL;
  i = -1;
  while (++i != nb_sprite)
    list = list_add_sprite(list, i, ini, ptr_list);
  return (list);
}
