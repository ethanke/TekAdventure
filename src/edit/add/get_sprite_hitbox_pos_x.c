/*
** get_sprite_hitbox_pos_x.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/edit/add/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sun Apr 17 00:39:47 2016 Victor Sousa
** Last update Sun Apr 17 01:15:57 2016 Victor Sousa
*/

#include		"main.h"

int			valid_pos_x_in_sprite(t_ini *ini, int id, int pos)
{
  t_sprite		*tmp;

  tmp = ini->scene->sprite;
  while (tmp != NULL)
    {
      if (tmp->id == id && pos <= tmp->sprite->width)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

int			get_sprite_width_id(t_ini *ini, int id)
{
  t_sprite		*tmp;

  tmp = ini->scene->sprite;
  while (tmp != NULL)
    {
      if (tmp->id == id)
	return (tmp->sprite->width);
      tmp = tmp->next;
    }
  return (0);
}

int			get_x_pos_sprite(t_ini *ini, int id)
{
  char			*str;
  int			pos;

  if ((str = get_next_line(0)) == NULL)
    return (-1);
  while ((pos = my_getnbr(str)) <= -1)
    {
      my_printf(1, "must be superior or equal to 0\n");
      free(str);
      if ((str = get_next_line(0)) == NULL)
	return (-1);
    }
  if (valid_pos_x_in_sprite(ini, id, pos) == 0)
    {
      my_printf(1, "out of range : max width for this sprite is %d\n",
		get_sprite_width_id(ini, id));
      return (get_x_pos_sprite(ini, id));
    }
  return (pos);
}
