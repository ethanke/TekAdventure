/*
** write_object2.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/edit/write/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat Apr 16 09:38:30 2016 Gaëtan Léandre
** Last update Sat Apr 16 22:58:53 2016 Gaëtan Léandre
*/

#include		"main.h"

void			write_object_sprite_hit_w(t_object *object, int fd,
						  int size)
{
  t_object		*tmp;
  int			i;

  i = 0;
  tmp = object;
  my_printf(fd, "object_sprite_hitbox_width=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->texture_hitbox->width);
      else
	my_printf(fd, "\"%d\"\n", tmp->texture_hitbox->width);
      tmp = tmp->next;
      i++;
    }
  if (size == 0)
    my_printf(fd, "\n");
}

void			write_object_sprite_hit_h(t_object *object, int fd,
						  int size)
{
  t_object		*tmp;
  int			i;

  i = 0;
  tmp = object;
  my_printf(fd, "object_sprite_hitbox_height=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->texture_hitbox->height);
      else
	my_printf(fd, "\"%d\"\n", tmp->texture_hitbox->height);
      tmp = tmp->next;
      i++;
    }
  if (size == 0)
    my_printf(fd, "\n");
}

void			write_object_sprite_hit_y(t_object *object, int fd,
						  int size)
{
  t_object		*tmp;
  int			i;

  i = 0;
  tmp = object;
  my_printf(fd, "object_sprite_hitbox_y=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->texture_hitbox->y);
      else
	my_printf(fd, "\"%d\"\n", tmp->texture_hitbox->y);
      tmp = tmp->next;
      i++;
    }
  if (size == 0)
    my_printf(fd, "\n");
}

void			write_object_sprite_hit_x(t_object *object, int fd,
						  int size)
{
  t_object		*tmp;
  int			i;

  i = 0;
  tmp = object;
  my_printf(fd, "object_sprite_hitbox_x=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->texture_hitbox->x);
      else
	my_printf(fd, "\"%d\"\n", tmp->texture_hitbox->x);
      tmp = tmp->next;
      i++;
    }
  if (size == 0)
    my_printf(fd, "\n");
}

void			write_object_sprite_id(t_object *object, int fd,
					       int size)
{
  t_object		*tmp;
  int			i;

  i = 0;
  tmp = object;
  my_printf(fd, "object_sprite_id=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->sprite_id);
      else
	my_printf(fd, "\"%d\"\n", tmp->sprite_id);
      tmp = tmp->next;
      i++;
    }
  if (size == 0)
    my_printf(fd, "\n");
}
