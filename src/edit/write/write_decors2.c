/*
** write_decors2.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/edit/write/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat Apr 16 18:40:16 2016 Gaëtan Léandre
** Last update Sat Apr 16 23:00:26 2016 Gaëtan Léandre
*/

#include		"main.h"

void			write_decors_brecabl_life(t_decors *decors, int fd,
						  int size)
{
  t_decors		*tmp;
  int			i;

  i = 0;
  tmp = decors;
  my_printf(fd, "decors_breakable_life=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->decors_breakable->life);
      else
	my_printf(fd, "\"%d\"\n", tmp->decors_breakable->life);
      tmp = tmp->next;
      i++;
    }
  if (size == 0)
    my_printf(fd, "\n");
}

void			write_decors_brecabl(t_decors *decors, int fd,
					     int size)
{
  t_decors		*tmp;
  int			i;

  i = 0;
  tmp = decors;
  my_printf(fd, "decors_is_breakable=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->decors_breakable->is_breakable);
      else
	my_printf(fd, "\"%d\"\n", tmp->decors_breakable->is_breakable);
      tmp = tmp->next;
      i++;
    }
  if (size == 0)
    my_printf(fd, "\n");
}

void			write_decors_spite_hitbox_h(t_decors *decors, int fd,
						    int size)
{
  t_decors		*tmp;
  int			i;

  i = 0;
  tmp = decors;
  my_printf(fd, "decors_sprite_hitbox_height=");
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

void			write_decors_spite_hitbox_w(t_decors *decors, int fd,
						    int size)
{
  t_decors		*tmp;
  int			i;

  i = 0;
  tmp = decors;
  my_printf(fd, "decors_sprite_hitbox_width=");
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

void			write_decors_spite_hitbox_y(t_decors *decors, int fd,
						    int size)
{
  t_decors		*tmp;
  int			i;

  i = 0;
  tmp = decors;
  my_printf(fd, "decors_sprite_hitbox_y=");
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
