/*
** write_ini.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/edit/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat Apr 16 07:45:43 2016 Gaëtan Léandre
** Last update Sat Apr 16 08:29:17 2016 Gaëtan Léandre
*/

#include 		"main.h"

int			write_sprite_id(t_sprite *sprite, int fd, int size)
{
  t_sprite		*tmp;
  int			i;

  i = 0;
  my_printf(fd, "sprite_id=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", sprite->id);
      else
	my_printf(fd, "\"%d\"\n", sprite->id);
      tmp = tmp->next;
      i++;
    }
}

int			write_sprite_path(t_sprite *sprite, int fd, int size)
{
  t_sprite		*tmp;
  int			i;

  i = 0;
  my_printf(fd, "sprite_path=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%s\", ", sprite->path);
      else
	my_printf(fd, "\"%s\"\n", sprite->path);
      tmp = tmp->next;
      i++;
    }
}

int			write_sprite(t_sprite *sprite, int fd)
{
  t_sprite		*tmp;
  int			i;

  i = 0;
  tmp = sprite;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      i++;
    }
  my_printf(fd, "[sprite]\nsprite_count=\"%d\"\n", i);
  write_sprite_id(sprite, fd, i);
  write_sprite_path(sprite, fd, i);
  my_printf(fd, "\n\n");
}
