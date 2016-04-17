/*
** get_existing_sprite.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/edit/add/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Apr 16 23:33:24 2016 Victor Sousa
** Last update Sun Apr 17 10:02:21 2016 Gaëtan Léandre
*/

#include		"main.h"

int			sprite_id_exist(t_ini *ini, int id)
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

int			get_existing_sprite(t_ini *ini)
{
  char			*str;
  int			id;

  if ((str = get_next_line(0)) == NULL)
    return (-1);
  while ((id = my_getnbr(str)) - 1 <= -1)
    {
      my_printf(1, "Id must be superior or equal to 0\n");
      free(str);
      if ((str = get_next_line(0)) == NULL)
	return (-1);
    }
  if (sprite_id_exist(ini, id) == 0)
    {
      my_printf(1, "There is no sprite with this id\n");
      return (get_existing_sprite(ini));
    }
  return (id);
}
