/*
** get_npc_id.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/edit/add/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sun Apr 17 04:01:24 2016 Victor Sousa
** Last update Sun Apr 17 09:58:31 2016 Victor Sousa
*/

#include		"main.h"

char			*look_for_npc_name(t_ini *ini, int id)
{
  t_npc			*tmp;

  tmp = ini->scene->npc;
  while (tmp != NULL)
    {
      if (tmp->npc_id == id)
	return (tmp->name);
      tmp = tmp->next;
    }
  return (NULL);
}

t_npc			*look_for_npc(t_ini *ini, int id)
{
  t_npc			*tmp;

  tmp = ini->scene->npc;
  while (tmp != NULL)
    {
      if (tmp->npc_id == id)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

int			npc_id_is_taken(t_ini *ini, int id)
{
  t_npc			*tmp;

  tmp = ini->scene->npc;
  while (tmp != NULL)
    {
      if (tmp->npc_id == id)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

int			get_npc_id(t_ini *ini)
{
  char			*str;
  int			id;

  if ((str = get_next_line(0)) == NULL)
    return (-1);
  while ((id = my_getnbr(str) - 1) <= -1)
    {
      my_printf(1, "Id must be superior to 0\n");
      free(str);
      if ((str = get_next_line(0)) == NULL)
	return (-1);
    }
  if (npc_id_is_taken(ini, id) == 1)
    {
      my_printf(1, "Id already taken by npc : %s\n",
		look_for_npc_name(ini, id));
      return (get_npc_id(ini));
    }
  return (id);
}
