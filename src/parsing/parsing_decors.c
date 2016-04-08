/*
** parsing_decors.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Thu Apr  7 01:13:52 2016 Philippe Lefevre
** Last update Fri Apr  8 05:09:50 2016 Philippe Lefevre
*/

#include		"main.h"

int 			fill_loot_table(char *str, unsigned int tab[2])
{
  int			i;

  tab[0] = my_getnbr(str);
  i = -1;
  while (str[++i] && str[i] != ';');
  tab[1] = my_getnbr(str + i + 1);
  return (0);
}

t_breakable		*create_decors_breakable(int id, t_bunny_ini *ini,
						 t_ptr_list **ptr_list)
{
  t_breakable		*breakable;
  char			*str;

  if ((breakable = xmalloc(sizeof(*breakable), ptr_list)) == NULL)
    return (NULL);
  if ((str = (char *)bunny_ini_get_field(ini, "decors", "breakable", id)) == NULL)
    return (NULL);
  breakable->is_breakable = my_getnbr(str);
  if ((breakable->is_breakable != 0) && (breakable->is_breakable != 1))
    return (NULL);
  if ((str = (char *)bunny_ini_get_field(ini, "decors", "breakable_life", id)) == NULL)
    return (NULL);
  breakable->life = my_getnbr(str);
  if ((str = (char *)bunny_ini_get_field(ini, "decors", "breakable_by", id)) == NULL)
    return (NULL);
  breakable->breakable_by = my_getnbr(str);
  if ((str = (char *)bunny_ini_get_field(ini, "decors", "lootable", id)) == NULL)
    return (NULL);
  breakable->lootable = my_getnbr(str);
  if ((str = (char *)bunny_ini_get_field(ini, "decors", "loot", id)) == NULL)
    return (NULL);
  fill_loot_table(str, breakable->loot);
  return (breakable);
}

t_decors		*create_decors_node(int id,
					    t_bunny_ini *ini,
					    t_ptr_list **ptr_list)
{
  t_decors		*decors;
  t_hitbox		decors_hitbox;
  char			*str;

  if ((decors = xmalloc(sizeof(*decors), ptr_list)) == NULL)
    return (NULL);
  decors->decors_id = id;
  if ((str = (char *)bunny_ini_get_field(ini, "decors", "name", id)) == NULL)
    return (NULL);
  if ((decors->name = my_strdup(str, ptr_list)) == NULL)
    return (NULL);
  if ((decors->decors_breakable =
       create_decors_breakable(id, ini, ptr_list)) == NULL)
    return (NULL);
  decors->next = NULL;
  decors->prev = NULL;
  return (decors);
}

t_decors		*list_add_decors(t_decors *list, int id,
					 t_bunny_ini *ini,
					 t_ptr_list **ptr_list)
{
  t_decors		*new;
  t_decors		*tmp;

  if ((new = create_decors_node(id, ini, ptr_list)) == NULL)
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

t_decors		*load_decors(t_bunny_ini *ini, t_ptr_list **ptr_list)
{
  t_decors		*list;
  char			*str;
  int			nb_decors;
  int			i;

  i = 0;
  if ((str = (char *)bunny_ini_get_field(ini, "count", "decors_count", 0)) == NULL)
    return (NULL);
  nb_decors = my_getnbr(str);
  list = NULL;
  while (i < nb_decors)
    {
      if ((list = list_add_decors(list, i, ini, ptr_list)) == NULL)
	return (NULL);
      i++;
    }
  return (list);
}
