/*
** parsing_object.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Thu Apr  7 01:13:52 2016 Philippe Lefevre
** Last update Thu Apr  7 05:59:07 2016 Philippe Lefevre
*/

#include		"parsing.h"

t_object		*list_create_node(void *data)
{
  t_object		*list;

  if ((list = malloc(sizeof(*list))) == NULL)
    return (NULL);
  list->data = data;
  list->prev = NULL;
  list->next = NULL;
  return (list);
}

t_object		*list_add_object()
{
  t_object		*new;
  t_object		*tmp;

  new = list_create_node(data);
  if (list == NULL)
    return (new);
  tmp = list;
  while (tmp != NULL)
    tmp = tmp->next;
  new->prev = tmp;
  new->next = NULL;
  tmp->next = new;
  return (list);
}

t_object		*create_object_node(int id, t_list *list,
					   t_bunny_ini *ini, t_ptr_list **ptr_list)
{
  t_object		*object;
  char			*str;

  if ((object = xmalloc(sizeof(t_object), &ptr_list)) == NULL)
    return (NULL);
  if ((object->name = my_strdup(bunny_ini_get_field(ini, "object", "name", id),
			   ptr_list)) == NULL);
    return (NULL);
  if ((str = bunny_ini_get_field(ini, "object", "damage", id)) == NULL)
    return (NULL);
  object->damage = my_getnbr(str);
  free(str);
  if ((str = bunny_ini_get_field(ini, "object", "sprite", id)) == NULL)
    return (NULL);
  object->sprite = my_getnbr(str);
  free(str);
}

t_object		*load_object(t_bunny_ini *ini, t_ptr_list **ptr_list)
{
  t_object		*list;
  int			nb_object;
  int			i;

  i = 0;
  nb_object = my_getnbr(bunny_ini_get_field(ini, "count", "nb_object", 0));
  while (i != nb_object)
    {
      list = list_add_object(list,
			   (void *)create_object_node(i, list, ini, ptr_list));
      i++;
  }
  return (list);
}
