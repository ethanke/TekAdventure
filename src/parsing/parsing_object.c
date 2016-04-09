/*
** parsing_object.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Thu Apr  7 01:13:52 2016 Philippe Lefevre
** Last update Sat Apr  9 04:08:09 2016 Philippe Lefevre
*/

#include		"main.h"

static t_object		*my_puterror_n(char *str)
{
  t_object 	*tmp;

  tmp = NULL;
  write(2, str, my_strlen(str));
  return (tmp);
}

t_hitbox		*create_object_hitbox(int id, t_bunny_ini *ini,
						 t_ptr_list **ptr_list)
{
  t_hitbox		*hitbox;
  char			*str;
  int			i;

  if ((hitbox = xmalloc(sizeof(*hitbox), ptr_list)) == NULL)
    return (NULL);
  if ((str = (char *)bunny_ini_get_field(ini, "object", "sprite_hitbox", id)) == NULL)
    return (NULL);
  i = -1;
  hitbox->x = my_getnbr(str);
  while (str[++i] && str[i] != ';');
  hitbox->y = my_getnbr(str + i + 1);
  while (str[++i] && str[i] != ';');
  hitbox->width = my_getnbr(str + i + 1);
  while (str[++i] && str[i] != ';');
  hitbox->height = my_getnbr(str + i + 1);
  return (hitbox);
}

t_object		*create_object_node(int id,
					    t_bunny_ini *ini,
					    t_ptr_list **ptr_list)
{
  t_object		*object;
  char			*str;

  if ((object = xmalloc(sizeof(t_object), ptr_list)) == NULL)
    return (my_puterror_n("Malloc fail"));
  object->object_id = id;
  if ((str = (char *)bunny_ini_get_field(ini, "object", "name", id)) == NULL)
    return (my_puterror_n("No \"name\" in object scope"));
  if ((object->name = my_strdup(str, ptr_list)) == NULL)
    return (my_puterror_n("Strdup fail"));
  if ((str = (char *)bunny_ini_get_field(ini, "object", "damage", id)) == NULL)
    return (my_puterror_n("No \"damage\" found in object scope"));
  object->damage = my_getnbr(str);
  if ((str = (char *)bunny_ini_get_field(ini, "object", "sprite_id", id)) == NULL)
    return (my_puterror_n("Error: decors or decors:sprite_id not set\n"));
  object->sprite_id = my_getnbr(str);
  object->texture_hitbox = create_object_hitbox(id, ini, ptr_list);
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
    return (my_puterror_n("No \"object_count\" in count scope"));
  nb_object = my_getnbr(str);
  list = NULL;
  while (i != nb_object)
    {
      if ((list = list_add_object(list, i, ini, ptr_list)) == NULL)
	return (my_puterror_n("Can't add object"));
      i++;
    }
  return (list);
}
