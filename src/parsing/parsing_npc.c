/*
** parsing_pnj.c for  in /Users/ethankerdelhue/Documents/Shared/TekAdventure/src/parsing/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Fri Apr  8 02:30:51 2016 Ethan Kerdelhue
** Last update Fri Apr  8 07:08:41 2016 Ethan Kerdelhue
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

  tmp = xmalloc(sizeof(tmp), ptr_list);
  tmp->item_player_id = my_getnbr(str);
  tmp->amount_player = get_a_player(str);
  tmp->item_npc_id = get_i_npc(str);
  tmp->amount_npc = get_a_npc(str);
  return (tmp);
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
  npc->id = id;
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

  if ((create_npc_node(id, ini, ptr_list)) == NULL)
    return (NULL);
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

t_npc		*load_npc(t_bunny_ini *ini, t_ptr_list **ptr_list)
{
  t_npc		*list;
  int		nb_npc;
  int		i;

  i = 0;
  list = NULL;
  nb_npc =
      my_getnbr((char *)bunny_ini_get_field(ini, "count", "npc_count", 0));
  if (nb_npc == 0)
    return (my_puterror_n("npc_count is null, no npc loaded"));
  while (i != nb_npc)
    {
      if ((list = list_add_npc(list, i, ini, ptr_list)) == NULL)
	  return (my_puterror_n("\nCan't add NPC"));
      i++;
    }
  return (list);
}
