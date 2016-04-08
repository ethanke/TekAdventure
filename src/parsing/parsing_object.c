/*
** parsing_object.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Thu Apr  7 01:13:52 2016 Philippe Lefevre
** Last update Fri Apr  8 05:07:10 2016 Philippe Lefevre
*/

#include		"main.h"

t_object		*create_object_node(int id,
					    t_bunny_ini *ini,
					    t_ptr_list **ptr_list)
{
  t_object		*object;
  char			*str;

  if ((object = xmalloc(sizeof(t_object), ptr_list)) == NULL)
    return (NULL);
  object->object_id = id;
  if ((str = (char *)bunny_ini_get_field(ini, "object", "name", id)) == NULL)
    return (NULL);
  if ((object->name = my_strdup(str, ptr_list)) == NULL)
    return (NULL);
  if ((str = (char *)bunny_ini_get_field(ini, "object", "damage", id)) == NULL)
    return (NULL);
  object->damage = my_getnbr(str);
  object->next = NULL;
  object->prev = NULL;
  return (object);
}

t_object		*list_add_object(t_object *list, int id,
					 t_bunny_ini *ini,
					 t_ptr_list **ptr_list)
{
  t_object		*new;
  t_object		*tmp;

  if ((new = create_object_node(id, ini, ptr_list)) == NULL)
    return (NULL);
  if (list == NULL)
    return (new);
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  new->prev = tmp;
  new->next = NULL;
  tmp->next = new;
  return (list);
}

t_object		*load_object(t_bunny_ini *ini, t_ptr_list **ptr_list)
{
  t_object		*list;
  char			*str;
  int			nb_object;
  int			i;

  i = 0;
  if ((str = (char *)bunny_ini_get_field(ini, "count", "object_count", 0)) == NULL)
    return (NULL);
  nb_object = my_getnbr(str);
  list = NULL;
  while (i != nb_object)
    {
      if ((list = list_add_object(list, i, ini, ptr_list)) == NULL)
	return (NULL);
      i++;
    }
  return (list);
}
