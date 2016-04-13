/*
** parsing_npc.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Fri Apr  8 02:30:51 2016 Ethan Kerdelhue
** Last update Wed Apr 13 17:30:49 2016 Philippe Lefevre
*/

#include		"main.h"

int			get_a_npc(char *str)
{
  int			i;

  i = 0;
  while (str[i])
    i++;
  while (str[i] != ';')
    i--;
  return (my_getnbr(&str[i + 1]));
}

int			get_i_npc(char *str)
{
  int			i;

  i = 0;
  while (str[i] != '/')
    i++;
  return (my_getnbr(&str[i + 1]));
}

int			get_a_player(char *str)
{
  int			i;

  i = 0;
  while (str[i] != ';')
    i++;
  return (my_getnbr(&str[i + 1]));
}

t_trade			*get_trade(char *str, t_ptr_list **ptr_list)
{
  t_trade		*trade;

  if ((trade = xmalloc(sizeof(*trade), ptr_list)) == NULL)
    return (my_puterror_trade("Error: trade:xmalloc failed in get_trade\n"));
  if ((trade->needed = xmalloc(sizeof(trade->needed), ptr_list)) == NULL)
    return (my_puterror_trade("Error: trade->needed:xmalloc failed in get_trade\n"));
  if ((trade->needed->id = my_getnbr(str)) < 0)
    return (my_puterror_trade("Error: npc:npc_trade needed id should not be negative\n"));
  if ((trade->needed->amount = get_a_player(str)) < 0)
    return (my_puterror_trade("Error: npc:npc_trade needed amount should not be negative\n"));
  if ((trade->given = xmalloc(sizeof(trade->given), ptr_list)) == NULL)
    return (my_puterror_trade("Error: trade->given:xmalloc failed in get_trade\n"));
  if ((trade->given->id = get_i_npc(str)) < 0)
    return (my_puterror_trade("Error: npc:npc_trade given id should not be negative\n"));
  if ((trade->given->amount = get_a_npc(str)) < 0)
    return (my_puterror_trade("Error: npc:npc_trade given amount should not be negative\n"));
  if ((trade->in_stock = xmalloc(sizeof(trade->in_stock), ptr_list)) == NULL)
    return (my_puterror_trade("Error: trade->in_stock:xmalloc failed in get_trade\n"));
  trade->in_stock->id = -1;
  trade->in_stock->amount = 0;
  if ((trade->in_stock->object = xmalloc(sizeof(t_object), ptr_list)) == NULL)
    return (my_puterror_trade("Error: trade->in_stock->object:xmalloc failed in get_trade\n"));
    trade->in_stock->object = NULL;
  return (trade);
}

t_hitbox		*create_npc_hitbox(int id, t_bunny_ini *ini,
						 t_ptr_list **ptr_list)
{
  t_hitbox		*hitbox;
  char			*str;
  int			i;

  if ((hitbox = xmalloc(sizeof(*hitbox), ptr_list)) == NULL)
    return (my_puterror_hitbox("Error: hitbox:xmalloc failed in create_npc_hitbox\n"));
  if ((str = (char *)bunny_ini_get_field(ini, "npc", "npc_sprite_hitbox", id)) == NULL)
    return (my_puterror_hitbox("Error: npc:npc_sprite_hitbox field not found\n"));
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

t_npc			*create_npc_node(int id, t_bunny_ini *ini,
					 t_ptr_list **ptr_list)
{
  t_npc		*npc;
  char		*str;

  if ((npc = xmalloc(sizeof(t_npc), ptr_list)) == NULL)
      return (my_puterror_npc("Error: npc:xmalloc failed in create_npc_node\n"));
  if ((str = (char *)bunny_ini_get_field(ini, "npc", "npc_id", id)) == NULL)
    return (my_puterror_npc("Error: npc:npc_id field not found\n"));
  if ((npc->npc_id = my_getnbr(str)) < 0)
    return (my_puterror_npc("Error: npc:npc_id should not be negative\n"));
  if ((str = (char *)bunny_ini_get_field(ini, "npc", "npc_name", id)) == NULL)
    return (my_puterror_npc("Error: npc:npc_name field not found\n"));
  if ((npc->name = my_strdup(str, ptr_list)) == NULL)
    return (my_puterror_npc("Error: npc->name:my_strdup failed in create_npc_node\n"));
  if ((str = (char *)bunny_ini_get_field(ini, "npc", "npc_text", id)) == NULL)
    return (my_puterror_npc("Error: npc:npc_text field not found\n"));
  if ((npc->text = my_strdup(str, ptr_list)) == NULL)
    return (my_puterror_npc("Error: npc->text:my_strdup failed in create_npc_node\n"));
  if ((str = (char *)bunny_ini_get_field(ini, "npc", "npc_trade", id)) == NULL)
    return (my_puterror_npc("Error: npc:npc_trade field not found\n"));
  if ((npc->trade = get_trade(str, ptr_list)) == NULL)
    return (NULL);
  npc->texture_hitbox = create_npc_hitbox(id, ini, ptr_list);
  if ((str = (char *)bunny_ini_get_field(ini, "npc", "npc_sprite_id", id)) == NULL)
    return (my_puterror_npc("Error: npc:npc_sprite_id field not found\n"));
  if ((npc->sprite_id = my_getnbr(str)) < 0)
    return (my_puterror_npc("Error: npc:npc_sprite_id should not be negative\n"));
  npc->next = NULL;
  npc->prev = NULL;
  return (npc);
}

t_npc		*list_add_npc(t_npc *list, int id, t_bunny_ini *ini,
			      t_ptr_list **ptr_list)
{
  t_npc		*new;
  t_npc		*npc;

  if ((new = create_npc_node(id, ini, ptr_list)) == NULL)
    return (my_puterror_npc("Error: new:xmalloc failed in list_add_npc\n"));
  if (list == NULL)
    return (new);
  npc = list;
  while (npc->next != NULL)
    npc = npc->next;
  if (npc == NULL)
  new->prev = npc;
  new->next = NULL;
  npc->next = new;
  return (list);
}

t_npc		*load_npc(t_bunny_ini *ini, t_ptr_list **ptr_list)
{
  t_npc		*list;
  char		*str;
  int		nb_npc;
  int		i;

  if ((str = (char *)bunny_ini_get_field(ini, "npc", "npc_count", 0)) == NULL)
    return (my_puterror_npc("Error: balise npc or npc:npc_count field not found\n"));
    if ((nb_npc = my_getnbr(str)) < 0)
    return (my_puterror_npc("Error: decors:decors_count should not be negative\n"));
	list = NULL;
      i = -1;
      while (++i != nb_npc)
    {
      if ((list = list_add_npc(list, i, ini, ptr_list)) == NULL)
	  return (NULL);
    }
  return (list);
}
