/*
** write_decors.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/edit/write/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat Apr 16 18:32:36 2016 Gaëtan Léandre
** Last update Sat Apr 16 23:00:44 2016 Gaëtan Léandre
*/

#include		"main.h"

void			write_decors_spite_hitbox_x(t_decors *decors, int fd,
						    int size)
{
  t_decors		*tmp;
  int			i;

  i = 0;
  tmp = decors;
  my_printf(fd, "decors_sprite_hitbox_x=");
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

void			write_decors_sprite_id(t_decors *decors, int fd,
					       int size)
{
  t_decors		*tmp;
  int			i;

  i = 0;
  tmp = decors;
  my_printf(fd, "decors_sprite_id=");
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

void			write_decors_name(t_decors *decors, int fd, int size)
{
  t_decors		*tmp;
  int			i;

  i = 0;
  tmp = decors;
  my_printf(fd, "decors_name=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%s\", ", tmp->name);
      else
	my_printf(fd, "\"%s\"\n", tmp->name);
      tmp = tmp->next;
      i++;
    }
  if (size == 0)
    my_printf(fd, "\n");
}

void			write_decors_id(t_decors *decors, int fd, int size)
{
  t_decors		*tmp;
  int			i;

  i = 0;
  tmp = decors;
  my_printf(fd, "decors_id=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->decors_id);
      else
	my_printf(fd, "\"%d\"\n", tmp->decors_id);
      tmp = tmp->next;
      i++;
    }
  if (size == 0)
    my_printf(fd, "\n");
}

void			write_decors(t_decors *decors, int fd)
{
  t_decors		*tmp;
  int			i;

  i = 0;
  tmp = decors;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      i++;
    }
  my_printf(fd, "[decors]\ndecors_count=\"%d\"\n", i);
  write_decors_id(decors, fd, i);
  write_decors_name(decors, fd, i);
  write_decors_sprite_id(decors, fd, i);
  write_decors_spite_hitbox_x(decors, fd, i);
  write_decors_spite_hitbox_y(decors, fd, i);
  write_decors_spite_hitbox_w(decors, fd, i);
  write_decors_spite_hitbox_h(decors, fd, i);
  write_decors_brecabl(decors, fd, i);
  write_decors_brecabl_life(decors, fd, i);
  write_decors_brecabl_break(decors, fd, i);
  write_decors_brecabl_lootable(decors, fd, i);
  write_decors_loot_id(decors, fd, i);
  write_decors_loot_amount(decors, fd, i);
  my_printf(fd, "\n\n");
}
