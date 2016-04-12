/*
** parsing_pnj.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Fri Apr  8 02:30:51 2016 Ethan Kerdelhue
** Last update Wed Apr 13 01:38:52 2016 Philippe Lefevre
*/

#include	"main.h"

static t_npc	*my_puterror_n(char *str)
{
  t_npc 	*tmp;

  tmp = NULL;
  write(2, str, my_strlen(str));
  return (tmp);
}

int		get_a_npc(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  while (str[i] != ';')
    i--;
  return (my_getnbr(&str[i + 1]));
}

int		get_i_npc(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '/')
    i++;
  return (my_getnbr(&str[i + 1]));
}

int		get_a_player(char *str)
{
  int		i;

  i = 0;
  while (str[i] != ';')
    i++;
  return (my_getnbr(&str[i + 1]));
}

t_trade		*get_trade(char *str, t_ptr_list **ptr_list)
{
  t_trade	*tmp;

  tmp = xmalloc(sizeof(*tmp), ptr_list);
  tmp->needed = xmalloc(sizeof(tmp->needed), ptr_list);
  tmp->needed->id = my_getnbr(str);
  tmp->needed->amount = get_a_player(str);
  tmp->given = xmalloc(sizeof(tmp->given), ptr_list);
  tmp->given->id = get_i_npc(str);
  tmp->given->amount = get_a_npc(str);
  return (tmp);
}

t_hitbox		*create_npc_hitbox(int id, t_bunny_ini *ini,
						 t_ptr_list **ptr_list)
{
  t_hitbox		*hitbox;
  char			*str;
  int			i;

  if ((hitbox = xmalloc(sizeof(*hitbox), ptr_list)) == NULL)
    return (NULL);
  if ((str = (char *)bunny_ini_get_field(ini, "npc", "sprite_hitbox", id)) == NULL)
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

t_npc		*create_npc_node(int id,
				 t_bunny_ini *ini,
				 t_ptr_list **ptr_list)
{
  t_npc		*npc;
  char		*str;

  if ((npc = xmalloc(sizeof(t_npc), ptr_list)) == NULL)
      return (my_puterror_n("Malloc fail"));
  if ((str = (char *)bunny_ini_get_field(ini, "npc", "name", id)) == NULL)
    return (my_puterror_n("Nom \"name\" field in npc scope"));
  if ((npc->name = my_strdup(str, ptr_list)) == NULL)
    return (my_puterror_n("Strdup fail"));
  if ((str = (char *)bunny_ini_get_field(ini, "npc", "text", id)) == NULL)
    return (my_puterror_n("No \"text\" field in npc scope"));
  if ((npc->text = my_strdup(str, ptr_list)) == NULL)
    return (my_puterror_n("Strdup fail"));
  if ((str = (char *)bunny_ini_get_field(ini, "npc", "trade", id)) == NULL)
    return (my_puterror_n("No \"trade\" field in npc scope"));
  npc->trade = get_trade(str, ptr_list);
  npc->texture_hitbox = create_npc_hitbox(id, ini, ptr_list);
  if ((str = (char *)bunny_ini_get_field(ini, "npc", "npc_id", id)) == NULL)
    return (my_puterror_n("Error: npc_id not set"));
  npc->npc_id = my_getnbr(str);
  if ((str = (char *)bunny_ini_get_field(ini, "npc", "sprite_id", id)) == NULL)
    return (my_puterror_n("Error: sprite_id not set"));
  npc->sprite_id = my_getnbr(str);
  npc->next = NULL;
  npc->prev = NULL;
  return (npc);
}

t_npc		*list_add_npc(t_npc *list, int id,
					 t_bunny_ini *ini,
					 t_ptr_list **ptr_list)
{
  t_npc		*new;
  t_npc		*tmp;

  if ((new = create_npc_node(id, ini, ptr_list)) == NULL)
    return (NULL);
  if (list == NULL)
    return (new);
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  if (tmp == NULL)
  new->prev = tmp;
  new->next = NULL;
  tmp->next = new;
  return (list);
}

t_npc		*load_npc(t_bunny_ini *ini, t_ptr_list **ptr_list)
{
  t_npc		*list;
  char		*str;
  int		nb_npc;
  int		i;

  i = 0;
  list = NULL;
  if ((str = (char *)bunny_ini_get_field(ini, "count", "npc_count", 0)) == NULL)
    return (my_puterror_n("Error: count field or count:npc_count not set\n"));
  if ((nb_npc = my_getnbr(str)) == 0)
    return (my_puterror_n("npc_count is null, no npc loaded\n"));
  while (i != nb_npc)
    {
      if ((list = list_add_npc(list, i, ini, ptr_list)) == NULL)
	  return (NULL);
      i++;
    }
  return (list);
}
