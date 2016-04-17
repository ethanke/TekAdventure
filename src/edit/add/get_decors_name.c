/*
** get_decors_name.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/edit/add/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Apr 17 03:10:09 2016 Gaëtan Léandre
** Last update Sun Apr 17 03:12:15 2016 Gaëtan Léandre
*/

#include		"main.h"

int			decors_name_is_taken(t_ini *ini, char *str)
{
  t_decors		*tmp;

  tmp = ini->scene->decors;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->name, str) == 0)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

char			*get_dec_name(t_ini *ini)
{
  char			*str;

  if ((str = get_next_line(0)) == NULL)
    return (NULL);
  while (decors_name_is_taken(ini, str) == 1)
    {
      my_printf(1, "name already taken by another decors\n");
      free(str);
      if ((str = get_next_line(0)) == NULL)
	return (NULL);
    }
  return (str);
}
