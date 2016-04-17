/*
** parsing_npc.c for TekAventure in /media/storage/my_files/Repository/Epitech/Year_1/Infographie/gfx_tekadventure/src/parsing/
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Sun Apr 17 00:44:45 2016 Philippe Lefevre
** Last update Sun Apr 17 04:04:19 2016 Philippe Lefevre
*/

#include		"main.h"

t_hitbox		*npc_hitbox_x(int id, t_bunny_ini *ini, char *name,
				      t_hitbox *hitbox)
{
  char			*str;

  if ((str = (char *)bunny_ini_get_field(ini, name,
					 "npc_sprite_hitbox_x", id))
      == NULL)
    {
      my_puterror_hitbox("Error: ", -1, name);
      return (my_puterror_hitbox(":npc_sprite_hitbox_x field ",
				 id, " not found\n"));
    }
  if ((hitbox->x = my_getnbr(str)) < 0)
    {
      my_puterror_hitbox("Error: ", -1, name);
      return (my_puterror_hitbox(":npc_sprite_hitbox_x field ", id,
				 " should not be negative and only number\n"));
    }
  return (hitbox);
}

t_hitbox		*npc_hitbox_y(int id, t_bunny_ini *ini, char *name,
				      t_hitbox *hitbox)
{
  char			*str;

  if ((str = (char *)bunny_ini_get_field(ini, name,
					 "npc_sprite_hitbox_y", id))
      == NULL)
    {
      my_puterror_hitbox("Error: ", -1, name);
      return (my_puterror_hitbox(":npc_sprite_hitbox_y field ",
				 id, " not found\n"));
    }
  if ((hitbox->y = my_getnbr(str)) < 0)
    {
      my_puterror_hitbox("Error: ", -1, name);
      return (my_puterror_hitbox(":npc_sprite_hitbox_y field ", id,
				 " should not be negative and only number\n"));
    }
  return (hitbox);
}

t_hitbox		*npc_hitbox_width(int id, t_bunny_ini *ini,
					  char *name, t_hitbox *hitbox)
{
  char			*str;

  if ((str = (char *)bunny_ini_get_field(ini, name,
					 "npc_sprite_hitbox_width", id))
      == NULL)
    {
      my_puterror_hitbox("Error: ", -1, name);
      return (my_puterror_hitbox(":npc_sprite_hitbox_width field ",
				 id, " not found\n"));
    }
  if ((hitbox->width = my_getnbr(str)) < 0)
    {
      my_puterror_hitbox("Error: ", -1, name);
      return (my_puterror_hitbox(":npc_sprite_hitbox_width field ", id,
				 " should not be negative and only number\n"));
    }
  return (hitbox);
}

t_hitbox		*npc_hitbox_height(int id, t_bunny_ini *ini,
					   char *name, t_hitbox *hitbox)
{
  char		*str;

  if ((str = (char *)bunny_ini_get_field(ini, name,
					 "npc_sprite_hitbox_height", id))
      == NULL)
    {
      my_puterror_hitbox("Error: ", -1, name);
      return (my_puterror_hitbox(":npc_sprite_hitbox_height field ",
				 id, " not found\n"));
    }
  if ((hitbox->height = my_getnbr(str)) < 0)
    {
      my_puterror_hitbox("Error: ", -1, name);
      return (my_puterror_hitbox(":npc_sprite_hitbox_height field ", id,
				 " should not be negative and only number\n"));
    }
  return (hitbox);
}

t_hitbox		*create_npc_hitbox(int id, t_bunny_ini *ini,
					   t_ptr_list **ptr_list)
{
  t_hitbox		*hitbox;

  if ((hitbox = xmalloc(sizeof(*hitbox), ptr_list)) == NULL)
    return (my_puterror_hitbox("Error: hitbox:xmalloc ", -1,
			       "failed in create_npc_hitbox\n"));
  if ((hitbox = npc_hitbox_x(id, ini, "npc", hitbox)) == NULL)
    return (NULL);
  if ((hitbox = npc_hitbox_y(id, ini, "npc", hitbox)) == NULL)
    return (NULL);
  if ((hitbox = npc_hitbox_width(id, ini, "npc", hitbox)) == NULL)
    return (NULL);
  if ((hitbox = npc_hitbox_height(id, ini, "npc", hitbox)) == NULL)
    return (NULL);
  return (hitbox);
}

t_trade			*get_trade_needed(t_trade *trade, t_ptr_list **ptr_list,
					  int id, t_bunny_ini *ini)
{
  char		*str;

  if ((trade->needed = xmalloc(sizeof(t_item), ptr_list)) == NULL)
    return (my_puterror_trade("Error: trade->needed:xmalloc ",
			      -1, "failed in get_trade\n"));
  if ((str = (char *)bunny_ini_get_field(ini, "npc",
					 "npc_trade_needed_id", id)) == NULL)
    return (my_puterror_trade("Error: npc:npc_trade_needed_id field ", id,
			      " not found\n"));
  if ((trade->needed->id = my_getnbr(str)) < 0)
    return (my_puterror_trade("Error: npc:npc_trade field ",
			      id, " needed id should not be negative\n"));
  if ((str = (char *)bunny_ini_get_field(ini, "npc", "npc_trade_needed_ammout",
					 id)) == NULL)
    return (my_puterror_trade("Error: npc:npc_trade_needed_ammout field ", id,
			      " not found\n"));
  if ((trade->needed->amount = my_getnbr(str)) < 0)
    return (my_puterror_trade("Error: npc:npc_trade field ",
      			      id, " needed amount should not be negative\n"));
  return (trade);
}

t_trade			*get_trade_given(t_trade *trade, t_ptr_list **ptr_list,
					 int id, t_bunny_ini *ini)
{
  char			*str;

  if ((trade->given = xmalloc(sizeof(t_item), ptr_list)) == NULL)
    return (my_puterror_trade("Error: trade->given:xmalloc ",
			      -1, "failed in get_trade\n"));
  if ((str = (char *)bunny_ini_get_field(ini, "npc",
					 "npc_trade_given_id", id)) == NULL)
    return (my_puterror_trade("Error: npc:npc_trade_given_id field ", id,
			      " not found\n"));
  if ((trade->given->id = my_getnbr(str)) < 0)
    return (my_puterror_trade("Error: npc:npc_trade field ",
			      id, " given id should not be negative\n"));
  if ((str = (char *)bunny_ini_get_field(ini, "npc", "npc_trade_given_amount",
					 id)) == NULL)
    return (my_puterror_trade("Error: npc:npc_trade_given_amount field ", id,
			      " not found\n"));
  if ((trade->given->amount = my_getnbr(str)) < 0)
    return (my_puterror_trade("Error: npc:npc_trade field ",
			      id, " given amount should not be negative\n"));
  return (trade);
}

t_trade			*get_trade(t_ptr_list **ptr_list,
				   int id, t_bunny_ini *ini)
{
  t_trade		*trade;

  if ((trade = xmalloc(sizeof(*trade), ptr_list)) == NULL)
    return (my_puterror_trade("Error: trade:xmalloc ",
			      -1, "failed in get_trade\n"));
  if ((trade = get_trade_needed(trade, ptr_list, id, ini)) == NULL)
    return (NULL);
  if ((trade = get_trade_given(trade, ptr_list, id, ini)) == NULL)
    return (NULL);
  if ((trade->in_stock = xmalloc(sizeof(t_item), ptr_list)) == NULL)
    return (my_puterror_trade("Error: trade->in_stock:xmalloc ",
			      -1, "failed in get_trade\n"));
  if ((trade->in_stock->object = xmalloc(sizeof(t_object), ptr_list)) == NULL)
    return (my_puterror_trade("Error: trade->in_stock->object:xmalloc ",
			      -1, "failed in get_trade\n"));
  trade->in_stock->id = -1;
  trade->in_stock->amount = 0;
  trade->in_stock->object = NULL;
  return (trade);
}

t_npc			*create_npc_node_bis(int id, t_bunny_ini *ini,
					     t_ptr_list **ptr_list,
					     t_npc *npc)
{
  char			*str;

  if ((str = (char *)bunny_ini_get_field(ini, "npc", "npc_text", id)) == NULL)
    return (my_puterror_npc("Error: npc:npc_text field ", id, " not found\n"));
  if ((npc->text = my_strdup(str, ptr_list)) == NULL)
    return (my_puterror_npc("Error: npc->text:my_strdup ",
			    -1, "failed in create_npc_node\n"));
  if ((npc->trade = get_trade(ptr_list, id, ini)) == NULL)
    return (NULL);
  if ((npc->texture_hitbox = create_npc_hitbox(id, ini, ptr_list)) == NULL)
    return (NULL);
  if ((str = (char *)bunny_ini_get_field(ini, "npc",
					 "npc_sprite_id", id)) == NULL)
    return (my_puterror_npc("Error: npc:npc_sprite_id field ",
			    id, " not found\n"));
  if ((npc->sprite_id = my_getnbr(str)) < 0)
    return (my_puterror_npc("Error: npc:npc_sprite_id field ",
			    id, " should not be negative\n"));
  return (npc);
}

t_npc			*create_npc_node(int id, t_bunny_ini *ini,
					 t_ptr_list **ptr_list)
{
  t_npc			*npc;
  char			*str;

  if ((npc = xmalloc(sizeof(t_npc), ptr_list)) == NULL)
    return (my_puterror_npc("Error: npc:xmalloc ",
			    -1, "failed in create_npc_node\n"));
  if ((str = (char *)bunny_ini_get_field(ini, "npc", "npc_id", id)) == NULL)
    return (my_puterror_npc("Error: npc:npc_id field ", id, " not found\n"));
  if ((npc->npc_id = my_getnbr(str)) < 0)
    return (my_puterror_npc("Error: npc:npc_id field ",
			    id, " should not be negative\n"));
  if ((str = (char *)bunny_ini_get_field(ini, "npc", "npc_name", id)) == NULL)
    return (my_puterror_npc("Error: npc:npc_name field ", id, " not found\n"));
  if ((npc->name = my_strdup(str, ptr_list)) == NULL)
    return (my_puterror_npc("Error: npc->name:my_strdup ",
			    -1, "failed in create_npc_node\n"));
  if ((npc = create_npc_node_bis(id, ini, ptr_list, npc)) == NULL)
    return (NULL);
  npc->next = NULL;
  npc->prev = NULL;
  return (npc);
}

t_npc			*list_add_npc(t_npc *list, int id, t_bunny_ini *ini,
				      t_ptr_list **ptr_list)
{
  t_npc			*new;
  t_npc			*npc;

  if ((new = create_npc_node(id, ini, ptr_list)) == NULL)
    return (my_puterror_npc("Error: new:xmalloc failed ",
			    -1, "in list_add_npc\n"));
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

t_npc			*load_npc(t_bunny_ini *ini, t_ptr_list **ptr_list)
{
  t_npc			*list;
  char			*str;
  int			nb_npc;
  int			i;

  if ((str = (char *)bunny_ini_get_field(ini, "npc",
					 "npc_count", 0)) == NULL)
    return (my_puterror_npc("Error: balise npc or npc:npc_count field ",
			    1,  " not found\n"));
  if ((nb_npc = my_getnbr(str)) < 0)
    return (my_puterror_npc("Error: decors:decors_count field ", 1,
			    " should not be negative\n"));
  list = NULL;
  i = -1;
  while (++i != nb_npc)
    {
      if ((list = list_add_npc(list, i, ini, ptr_list)) == NULL)
	return (NULL);
    }
  return (list);
}
