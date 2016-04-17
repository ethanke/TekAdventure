/*
** get_decors_id.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/edit/add/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Apr 17 03:03:55 2016 Gaëtan Léandre
** Last update Sun Apr 17 07:51:50 2016 Gaëtan Léandre
*/

#include		"main.h"

char			*look_for_decors_name(t_ini *ini, int id)
{
  t_decors		*tmp;

  tmp = ini->scene->decors;
  while (tmp != NULL)
    {
      if (tmp->decors_id == id)
	return (tmp->name);
      tmp = tmp->next;
    }
  return (NULL);
}

int			decors_id_is_taken(t_ini *ini, int id)
{
  t_decors		*tmp;

  tmp = ini->scene->decors;
  while (tmp != NULL)
    {
      if (tmp->decors_id == id)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

int			get_dec_id(t_ini *ini)
{
  char			*str;
  int			id;

  if ((str = get_next_line(0)) == NULL)
    return (-1);
  while ((id = my_getnbr(str) - 1) <= -1)
    {
      my_printf(1, "Id must be superior to 0\nTry again : ");
      free(str);
      if ((str = get_next_line(0)) == NULL)
	return (-1);
    }
  if (decors_id_is_taken(ini, id + 1) == 1)
    {
      my_printf(1, "Id already taken by decors : %s\nTry again : ",
		look_for_decors_name(ini, id + 1));
      return (get_dec_id(ini));
    }
  return (id + 1);
}
