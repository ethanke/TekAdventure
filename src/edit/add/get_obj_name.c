/*
** get_obj_name.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/edit/add/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr 16 20:59:35 2016 Victor Sousa
** Last update Sat Apr 16 21:21:22 2016 Victor Sousa
*/

#include		"main.h"

int			object_name_is_taken(t_ini *ini, char *str)
{
  t_object		*tmp;

  tmp = ini->scene->object;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->name, str) == 0)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

char			*get_obj_name(t_ini *ini)
{
  char			*str;

  if ((str = get_next_line(0)) == NULL)
    return (NULL);
  while (object_name_is_taken(ini, str) == 1)
    {
      my_printf(1, "name already taken by another object\n");
      free(str);
      if ((str = get_next_line(0)) == NULL)
	return (NULL);
    }
  return (str);
}
