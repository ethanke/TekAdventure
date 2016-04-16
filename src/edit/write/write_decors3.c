/*
** write_decors3.c for tekadventure in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/edit/write/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat Apr 16 18:43:57 2016 Gaëtan Léandre
** Last update Sat Apr 16 23:00:08 2016 Gaëtan Léandre
*/

#include		"main.h"

void			write_decors_loot_amount(t_decors *decors, int fd,
						 int size)
{
  t_decors		*tmp;
  int			i;

  i = 0;
  tmp = decors;
  my_printf(fd, "decors_loot_amount=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->decors_breakable->loot[1]);
      else
	my_printf(fd, "\"%d\"\n", tmp->decors_breakable->loot[1]);
      tmp = tmp->next;
      i++;
    }
  if (size == 0)
    my_printf(fd, "\n");
}

void			write_decors_loot_id(t_decors *decors, int fd,
					     int size)
{
  t_decors		*tmp;
  int			i;

  i = 0;
  tmp = decors;
  my_printf(fd, "decors_loot_id=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->decors_breakable->loot[0]);
      else
	my_printf(fd, "\"%d\"\n", tmp->decors_breakable->loot[0]);
      tmp = tmp->next;
      i++;
    }
  if (size == 0)
    my_printf(fd, "\n");
}

void			write_decors_brecabl_lootable(t_decors *decors, int fd,
						      int size)
{
  t_decors		*tmp;
  int			i;

  i = 0;
  tmp = decors;
  my_printf(fd, "decors_is_lootable=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->decors_breakable->lootable);
      else
	my_printf(fd, "\"%d\"\n", tmp->decors_breakable->lootable);
      tmp = tmp->next;
      i++;
    }
  if (size == 0)
    my_printf(fd, "\n");
}

void			write_decors_brecabl_break(t_decors *decors, int fd,
						   int size)
{
  t_decors		*tmp;
  int			i;

  i = 0;
  tmp = decors;
  my_printf(fd, "decors_breakable_breaker=");
  while (tmp != NULL)
    {
      if (i != size - 1)
	my_printf(fd, "\"%d\", ", tmp->decors_breakable->breakable_by);
      else
	my_printf(fd, "\"%d\"\n", tmp->decors_breakable->breakable_by);
      tmp = tmp->next;
      i++;
    }
  if (size == 0)
    my_printf(fd, "\n");
}
