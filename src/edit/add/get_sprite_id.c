/*
** get_sprite_id.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/edit/add/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sun Apr 17 02:56:54 2016 Victor Sousa
** Last update Sun Apr 17 09:20:08 2016 Gaëtan Léandre
*/

#include		"main.h"

char			*look_for_sprite_name(t_ini *ini, int id)
{
  t_sprite		*tmp;

  tmp = ini->scene->sprite;
  while (tmp != NULL)
    {
      if (tmp->id == id)
	return (tmp->path);
      tmp = tmp->next;
    }
  return (NULL);
}

t_sprite		*look_for_sprite(t_ini *ini, int id)
{
  t_sprite		*tmp;

  tmp = ini->scene->sprite;
  while (tmp != NULL)
    {
      if (tmp->id == id)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

int			sprite_id_is_taken(t_ini *ini, int id)
{
  t_sprite		*tmp;

  tmp = ini->scene->sprite;
  while (tmp != NULL)
    {
      if (tmp->id == id)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

int			get_sprite_id(t_ini *ini)
{
  char			*str;
  int			id;

  my_printf(1, "Enter sprite id : ");
  if ((str = get_next_line(0)) == NULL)
    return (-1);
  while ((id = my_getnbr(str) - 1) <= -1)
    {
      my_printf(1, "Id must be superior to 0\n");
      free(str);
      if ((str = get_next_line(0)) == NULL)
	return (-1);
    }
  if (sprite_id_is_taken(ini, id) == 1)
    {
      my_printf(1, "Id already taken by sprite : %s\n",
		look_for_sprite_name(ini, id));
      return (get_sprite_id(ini));
    }
  return (id);
}
