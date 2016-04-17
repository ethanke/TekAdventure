/*
** get_obj_id.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/edit/add/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr 16 20:21:50 2016 Victor Sousa
** Last update Sun Apr 17 08:04:17 2016 Victor Sousa
*/

#include		"main.h"

char			*look_for_obj_name(t_ini *ini, int id)
{
  t_object		*tmp;

  tmp = ini->scene->object;
  while (tmp != NULL)
    {
      if (tmp->object_id == id)
	return (tmp->name);
      tmp = tmp->next;
    }
  return (NULL);
}

int			object_id_is_taken(t_ini *ini, int id)
{
  t_object		*tmp;

  tmp = ini->scene->object;
  while (tmp != NULL)
    {
      if (tmp->object_id == id)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

t_object		*look_for_obj(t_ini *ini, int id)
{
  t_object		*tmp;

  tmp = ini->scene->object;
  while (tmp != NULL)
    {
      if (tmp->object_id == id)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

int			get_obj_id(t_ini *ini)
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
  if (object_id_is_taken(ini, id) == 1)
    {
      my_printf(1, "Id already taken by object : %s\n",
		look_for_obj_name(ini, id));
      return (get_obj_id(ini));
    }
  return (id);
}
