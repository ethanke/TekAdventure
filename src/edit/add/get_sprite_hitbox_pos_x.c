/*
** get_sprite_hitbox_pos_x.c for  in /home/sousa_v/rendu/lapin/TekAdventure_temp/src/edit/add/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sun Apr 17 00:39:47 2016 Victor Sousa
** Last update Sun Apr 17 06:17:12 2016 Victor Sousa
*/

#include		"main.h"

void			get_object_sprite_info(t_ini *ini, t_object *obj)
{
  my_printf(1, "\nChoose a sprite id for your object : ");
  obj->sprite_id = get_existing_sprite(ini);
  if ((obj->texture_hitbox = xmalloc(sizeof(t_hitbox),
				     &ini->ptr_list)) == NULL)
    return;
  my_printf(1, "\ntop left position in the sprite\nx : ");
  obj->texture_hitbox->x = get_x_pos_sprite(ini, obj->sprite_id);
  my_printf(1, "y : ");
  obj->texture_hitbox->y = get_y_pos_sprite(ini, obj->sprite_id);
  my_printf(1, "\nwidth in the sprite : ");
  obj->texture_hitbox->width = get_x_pos_sprite(ini, obj->sprite_id);
  my_printf(1, "height in the sprite : ");
  obj->texture_hitbox->height = get_y_pos_sprite(ini, obj->sprite_id);
}

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
