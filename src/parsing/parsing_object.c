/*
** parsing_object.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Thu Apr  7 01:13:52 2016 Philippe Lefevre
** Last update Wed Apr 13 18:23:04 2016 Philippe Lefevre
*/

#include		"main.h"

t_hitbox		*create_object_hitbox(int id, t_bunny_ini *ini,
						 t_ptr_list **ptr_list)
{
  t_hitbox		*hitbox;
  char			*str;
  int			i;

  if ((hitbox = xmalloc(sizeof(*hitbox), ptr_list)) == NULL)
    return (my_puterror_hitbox("Error: hitbox:xmalloc failed in create_object_hitbox\n"));
  if ((str = (char *)bunny_ini_get_field(ini, "object", "object_sprite_hitbox", id)) == NULL)
    return (my_puterror_hitbox("Error: object:object_sprite_hitbox field not found\n"));
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
    return (my_puterror_object("Error: object:xmalloc failed in create_object_node\n"));
  if ((str = (char *)bunny_ini_get_field(ini, "object", "object_id", id)) == NULL)
    return (my_puterror_object("Error: object:object_id field not found\n"));
  if ((object->object_id = my_getnbr(str)) < 0)
    return (my_puterror_object("Error: object:object_id should not be negative\n"));
  if ((str = (char *)bunny_ini_get_field(ini, "object", "object_name", id)) == NULL)
    return (my_puterror_object("Error: object:object_name field not found\n"));
  if ((object->name = my_strdup(str, ptr_list)) == NULL)
    return (my_puterror_object("Error: object->name:my_strdup failed in create_object_node\n"));
  if ((str = (char *)bunny_ini_get_field(ini, "object", "object_damage", id)) == NULL)
    return (my_puterror_object("Error: object:object_damage field not found\n"));
  object->damage = my_getnbr(str);
  if ((str = (char *)bunny_ini_get_field(ini, "object", "object_sprite_id", id)) == NULL)
    return (my_puterror_object("Error: object:object_sprite_id field not found\n"));
  if ((object->sprite_id = my_getnbr(str)) < 0)
    return (my_puterror_object("Error: object:object_sprite_id should not be negative\n"));
  if ((object->texture_hitbox = create_object_hitbox(id, ini, ptr_list)) == NULL)
    return (NULL);
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

  if ((str = (char *)bunny_ini_get_field(ini, "object", "object_count", 0)) == NULL)
    return (my_puterror_object("Error: balise object or object:object_count field not found\n"));
    if ((nb_object = my_getnbr(str)) < 0)
	return (my_puterror_object("Error: object:object_count \
				should not be negative\n"));
  list = NULL;
  i = -1;
  while (++i != nb_object)
    {
      if ((list = list_add_object(list, i, ini, ptr_list)) == NULL)
	return (NULL);
    }
  return (list);
}
