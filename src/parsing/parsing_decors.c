/*
** parsing_decors.c for TekAdventure in /home/lefevr_h/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Thu Apr  7 01:13:52 2016 Philippe Lefevre
** Last update Wed Apr 13 23:24:49 2016 Philippe Lefevre
*/

#include		"main.h"

int 			fill_loot_table(char *str, int tab[2])
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
    return (my_puterror_breakable("Error: breakable:xmalloc ", -1, "failed in create_decors_breakable\n"));
  if ((str = (char *)bunny_ini_get_field(ini, "decors", "decors_is_breakable", id)) == NULL)
    return (my_puterror_breakable("Error: decors:decors_is_breakable field ", id, " not found\n"));
  breakable->is_breakable = my_getnbr(str);
  if ((breakable->is_breakable != 0) && (breakable->is_breakable != 1))
    return (my_puterror_breakable("Error: decors:decors_is_breakable field ", id, " must be 0 or 1\n"));
  if ((str = (char *)bunny_ini_get_field(ini, "decors", "decors_breakable_life", id)) == NULL)
    return (my_puterror_breakable("Error: decors:decors_breakable_life field ", id, " not found\n"));
  if ((breakable->life = my_getnbr(str)) < 0)
    return (my_puterror_breakable("Error: decors:decors_breakable_life field ", id, " should not be negative\n"));
  if ((breakable->is_breakable == 1) && (breakable->life < 0))
    return (my_puterror_breakable("Error: decors:decors_breakable_life field ", id, " must be positive\n"));
  if ((str = (char *)bunny_ini_get_field(ini, "decors", "decors_breakable_breaker", id)) == NULL)
    return (my_puterror_breakable("Error: decors:decors_breakable_breaker field ", id, " not found\n"));
  breakable->breakable_by = my_getnbr(str); /* gestion d'erreu ici */
  if ((str = (char *)bunny_ini_get_field(ini, "decors", "decors_is_lootable", id)) == NULL)
    return (my_puterror_breakable("Error: decors:decors_is_lootable ", -1, "field not found\n"));
  breakable->lootable = my_getnbr(str);
  if ((breakable->lootable != 0) && (breakable->lootable != 1))
    return (my_puterror_breakable("Error: decors:decors_is_lootable field ", id, " format 0 or 1\n"));
  if ((str = (char *)bunny_ini_get_field(ini, "decors", "decors_loot", id)) == NULL)
    return (my_puterror_breakable("Error: decors:decors_loot field ", id, " not found\n"));
  fill_loot_table(str, breakable->loot);
  return (breakable);
}

t_hitbox		*create_decors_hitbox(int id, t_bunny_ini *ini,
						 t_ptr_list **ptr_list)
{
  t_hitbox		*hitbox;
  char			*str;
  int			i;

  if ((hitbox = xmalloc(sizeof(*hitbox), ptr_list)) == NULL)
    return (my_puterror_hitbox("Error: hitbox:xmalloc ", -1, "failed in create_decors_hitbox\n"));
  if ((str = (char *)bunny_ini_get_field(ini, "decors", "decors_sprite_hitbox", id)) == NULL)
    return (my_puterror_hitbox("Error: decors:decors_sprite_hitbox field ", id, " not found\n"));
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

t_decors		*create_decors_node(int id, t_bunny_ini *ini,
					    t_ptr_list **ptr_list)
{
  t_decors		*decors;
  char			*str;

  if ((decors = xmalloc(sizeof(*decors), ptr_list)) == NULL)
    return (my_puterror_decors("Error: decors:xmalloc ", -1, "failed in create_decors_node\n"));
  if ((str = (char *)bunny_ini_get_field(ini, "decors", "decors_id", id)) == NULL)
    return (my_puterror_decors("Error: decors:decors_id field ", id, " not found\n"));
  if ((decors->decors_id = my_getnbr(str)) < 0)
    return (my_puterror_decors("Error: decors:decors_id field ", id, " should not be negative\n"));
  if ((str = (char *)bunny_ini_get_field(ini, "decors", "decors_name", id)) == NULL)
    return (my_puterror_decors("Error: decors:decors_name field ", id, " not found\n"));
  if ((decors->name = my_strdup(str, ptr_list)) == NULL)
    return (my_puterror_decors("Error: decors->name:my_strdup ", -1, "failed in create_decors_node\n"));
  if ((str = (char *)bunny_ini_get_field(ini, "decors", "decors_sprite_id", id)) == NULL)
    return (my_puterror_decors("Error: decors:decors_sprite_id field ", id, " not found\n"));
  if ((decors->sprite_id = my_getnbr(str)) < 0)
    return (my_puterror_decors("Error: decors:decors_sprite_id field ", id, " should not be negative\n"));
  if ((decors->decors_breakable =
       create_decors_breakable(id, ini, ptr_list)) == NULL)
    return (NULL);
  if ((decors->texture_hitbox = create_decors_hitbox(id, ini, ptr_list)) == NULL)
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
  int			i;

  if ((new = create_decors_node(id, ini, ptr_list)) == NULL)
    return (NULL);
  if (list == NULL)
    return (new);
  tmp = list;
  i = 0;
  while (tmp->next != NULL && ++i)
    {
      if (tmp->decors_id == new->decors_id)
	{
	  my_puterror_decors("Error: decors:decors_id field ", id, " ");
	  return (my_puterror_decors("already declared in field ", i, "\n"));
	}
      tmp = tmp->next;
    }
  if (tmp->decors_id == new->decors_id)
    {
      my_puterror_decors("Error: decors:decors_id field ", (id + 1), " ");
      return (my_puterror_decors("already declared in field ", i, "\n"));
    }
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

  if ((str = (char *)bunny_ini_get_field(ini, "decors", "decors_count", 0)) == NULL)
    return (my_puterror_decors("Error: balise decors or decors:decors_count ", -1, "field not found\n"));
  if ((nb_decors = my_getnbr(str)) < 0)
    return (my_puterror_decors("Error: decors:decors_count ", -1, "should not be negative\n"));
  list = NULL;
  i = -1;
  while (++i < nb_decors)
    {
      if ((list = list_add_decors(list, i, ini, ptr_list)) == NULL)
	return (NULL);
    }
  return (list);
}
