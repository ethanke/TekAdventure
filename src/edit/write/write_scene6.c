/*
** write_scene6.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/edit/write/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat Apr 16 21:35:08 2016 Gaëtan Léandre
** Last update Sat Apr 16 21:46:05 2016 Gaëtan Léandre
*/

#include		"main.h"

void			write_sky_hitbox_w(t_sky *sky, int fd,
					   int size)
{
  t_sky			*tmp;
  int			i;

  i = 0;
  tmp = sky;
  my_printf(fd, "scene_sky_sprite_hitbox_width=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->hitbox->width);
      else
	my_printf(fd, "\"%d\"\n", tmp->hitbox->width);
      tmp = tmp->next;
      i++;
    }
}

void			write_sky_hitbox_y(t_sky *sky, int fd,
					   int size)
{
  t_sky			*tmp;
  int			i;

  i = 0;
  tmp = sky;
  my_printf(fd, "scene_sky_sprite_hitbox_y=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->hitbox->y);
      else
	my_printf(fd, "\"%d\"\n", tmp->hitbox->y);
      tmp = tmp->next;
      i++;
    }
}

void			write_sky_hitbox_x(t_sky *sky, int fd,
					   int size)
{
  t_sky			*tmp;
  int			i;

  i = 0;
  tmp = sky;
  my_printf(fd, "scene_sky_sprite_hitbox_x=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->hitbox->x);
      else
	my_printf(fd, "\"%d\"\n", tmp->hitbox->x);
      tmp = tmp->next;
      i++;
    }
}

void			write_sky_id(t_sky *sky, int fd,
				     int size)
{
  t_sky			*tmp;
  int			i;

  i = 0;
  tmp = sky;
  my_printf(fd, "object_sprite_id=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->sky_sprite_id);
      else
	my_printf(fd, "\"%d\"\n", tmp->sky_sprite_id);
      tmp = tmp->next;
      i++;
    }
}

void			write_sprite_sky(t_sky *sky, int fd)
{
  t_sky			*tmp;
  int			i;

  i = 0;
  tmp = sky;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      i++;
    }
  my_printf(fd, "scene_sky_count=\"%d\"\n", i);
  write_sky_id(sky, fd, i);
  write_sky_hitbox_x(sky, fd, i);
  write_sky_hitbox_y(sky, fd, i);
  write_sky_hitbox_w(sky, fd, i);
  write_sky_hitbox_h(sky, fd, i);
  my_printf(fd, "\n\n");
}
